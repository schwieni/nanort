#ifndef RENDER_CONFIG_H
#define RENDER_CONFIG_H

#include "common-util.h"

#include <string>

namespace example {

enum VDispSpace {
  VDISP_SPACE_WORLD = 0,
  VDISP_SPACE_TANGENT
};

struct RenderConfig {
  // framebuffer
  int width;
  int height;

  // camera
  float eye[3];
  float up[3];
  float look_at[3];
  float fov;  // vertical fov in degree.

  // render pass
  int pass = 0;
  int max_passes = 65535;

  // Scene input info
  std::string obj_filename;
  float scene_scale;

  // vdisp parameter.
  VDispSpace vdisp_space;
  float vdisp_scale = 1.0f;

};

/// Loads config from JSON file.
bool LoadRenderConfig(example::RenderConfig *config, const char *filename);

}  // namespace

#endif  // RENDER_CONFIG_H