/* Copyright 2020 Adam Honse <calcprogrammer1@gmail.com>
 * Copyright 2020 Dimitris Mantzouranis <d3xter93@gmail.com>
 * Copyright 2022 Harrison Chan (Xelus)
 * Copyright 2022 Thomas Bowman Mørch (tbowmo)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    WIN_BASE    = 0,
    WIN_FN      = 1,
    MAC_BASE    = 2,
    MAC_FN      = 3,
};

#define KC_TASK LGUI(KC_TAB)        // Task viewer
#define KC_FLXP LGUI(KC_E)          // Windows file explorer
#define KC_CRTN LGUI(KC_C)          // Cortana | Microsoft Teams

#define KC_MSSN LGUI(KC_F3)         // Mission Control
#define KC_FIND LALT(LGUI(KC_SPC))  // Finder
#define KC_SIRI LGUI(KC_SPC)        // Siri
#define KC_MSNP LSFT(LGUI(KC_4))    // Mac snip tool

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT_iso(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_PSCR, KC_CRTN, RGB_MOD,    _______,  _______, _______, _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,             KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,                                   KC_P4,   KC_P5,   KC_P6,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, MO(WIN_FN),  KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT
    ),

    [WIN_FN] = LAYOUT_iso(
        QK_BOOT,           KC_BRID,   KC_BRIU,   KC_TASK,   KC_FLXP,   RGB_VAD,   RGB_VAI,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MUTE,  KC_VOLD,  KC_VOLU,     _______, _______, RGB_TOG,  _______,  _______, _______, _______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,    _______,  _______, _______,    _______,  _______, _______, _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI,    _______,    _______,    _______,    _______,    _______,    _______, _______,             EE_CLR,  _______,  _______,    _______,   _______,   _______,   _______,
        _______, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,    _______,    _______,    _______,    _______,    _______, _______, _______, _______,                                   _______,   _______,   _______,
        _______, _______, _______,    _______,    _______,    _______,    NK_TOGG,    _______,    _______,    _______, _______,  _______,          _______,             _______,               _______,   _______,   _______,   _______,
        _______, _______, _______,                            _______,                             _______, _______, _______,  _______,    RGB_SAD, _______, RGB_SAI,    _______,            _______
    ),

    [MAC_BASE] = LAYOUT_iso(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_MSNP, KC_SIRI, RGB_MOD,    _______,  _______, _______, _______,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,             KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,                                   KC_P4,   KC_P5,   KC_P6,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RGUI, KC_RALT, MO(MAC_FN),  KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT
    ),

    [MAC_FN] = LAYOUT_iso(
        QK_BOOT,           KC_BRID,   KC_BRIU,   KC_TASK,   KC_FLXP,   RGB_VAD,   RGB_VAI,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MUTE,  KC_VOLD,  KC_VOLU,     _______, _______, RGB_TOG, _______,  _______, _______, _______,
        _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,  _______,    _______,  _______, _______,    _______,  _______, _______, _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI,    _______,    _______,    _______,    _______,    _______,    _______, _______,             EE_CLR,  _______,  _______,    _______,   _______,   _______,   _______,
        _______, RGB_RMOD,RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,    _______,    _______,    _______,    _______,    _______, _______, _______, _______,                                   _______,   _______,   _______,
        _______, _______, _______,    _______,    _______,    _______,    NK_TOGG,    _______,    _______,    _______, _______,  _______,          _______,             _______,               _______,   _______,   _______,   _______,
        _______, _______, _______,                            _______,                             _______, _______, _______,  _______,    RGB_SAD, _______, RGB_SAI,    _______,            _______
    ),

};

bool dip_switch_update_user(uint8_t index, bool active){
  switch(index){
    case 0:
      if(active) { // Mac mode
          layer_move(MAC_BASE);
      } else { // Windows mode
          layer_move(WIN_BASE);
      }
      return false;
    case 1:
      if(active){ //Cable mode
        // do stuff
      }
      else{ //BT mode
        // do stuff
      }
      break;
  }

  return true;
}


bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().num_lock) {
        rgb_matrix_set_color(16, 255, 255, 255);
    } else {
        rgb_matrix_set_color(16, 0, 0, 0);
    }

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(17, 255, 255, 255);
    } else {
        rgb_matrix_set_color(17, 0, 0, 0);
    }

    if (layer_state_is(MAC_BASE) || layer_state_is(MAC_FN)) {
        rgb_matrix_set_color(18, 255, 255, 255);
    } else {
        rgb_matrix_set_color(18, 0, 0, 0);
    }

    if (layer_state_is(WIN_BASE) || layer_state_is(WIN_FN)) {
        rgb_matrix_set_color(19, 255, 255, 255);
    } else {
        rgb_matrix_set_color(19, 0, 0, 0);
    }


    return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
  //debug_mouse=true;
}
