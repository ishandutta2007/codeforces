#include <iostream>
#include <vector>
#include <iomanip>

typedef long double ldouble;

const int MAX_MICE = 100005;
const ldouble EPS = 0.00000000001L;
const ldouble INF = 1023456789.0L;

using namespace std;

struct mouse {
  int init, speed, dir;
  
  mouse (int _init, int _speed, int _dir) {
    init = _init;
    speed = _speed;
    dir = _dir;
  }
};

pair<ldouble, ldouble> bounds (mouse x, int lower, int upper) {
  if (x.speed == 0) {
    if (min(lower, upper) < x.init && x.init < max(lower, upper)) {
      return make_pair(0, INF);
    } else {
      return make_pair(1, 0);
    }
  } else {
    ldouble lower_meet = (ldouble) (lower - x.init) / (ldouble) x.speed;
    ldouble upper_meet = (ldouble) (upper - x.init) / (ldouble) x.speed;

    if (lower_meet > upper_meet) {
      swap(lower_meet, upper_meet);
    }

    return make_pair(lower_meet, upper_meet);
  }
}

int main () {
  int micec;
  cin >> micec;
  
  int x_lower, y_lower, x_upper, y_upper;
  cin >> x_lower >> y_lower >> x_upper >> y_upper;

  vector<mouse> mice;
  for (int i = 0; i < micec; i++) {
    int init_x, init_y, speed_x, speed_y;
    cin >> init_x >> init_y >> speed_x >> speed_y;

    mice.push_back(mouse(init_x, speed_x, 0));
    mice.push_back(mouse(init_y, speed_y, 1));
  }

  ldouble lower = 0, upper = INF;
  for (int i = 0; i < (int) mice.size(); i++) {
    pair<ldouble, ldouble> time_bounds;
    if (mice[i].dir == 0) {
      time_bounds = bounds(mice[i], x_lower, x_upper);
    } else {
      time_bounds = bounds(mice[i], y_lower, y_upper);
    }

    lower = max(lower, time_bounds.first);
    upper = min(upper, time_bounds.second);
  }

  if (upper - lower < EPS) {
    cout << -1 << endl;
  } else {
    cout << fixed << setprecision(20) << lower << endl;
  }
}