#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long double ld;

const int MAX_N = 1e5 + 5;
const ld MAX_R = 2e5 + 5;
const ld EPS = 1e-5;

bool get_range (ld r, ld x, ld y, pair<ld, ld> &out) {
  ld R = hypot(x, y);
  ld alpha = atan2(y, x);
  if (alpha < 0) {
    alpha += 2 * M_PI;
  }
  if (2 * r <= R) {
    return false;
  }
  ld d = acos(R / (2 * r));
  out = make_pair(alpha - d, alpha + d);
  return true;
}

int n, K;
int x [MAX_N], y [MAX_N];

bool can (ld r) {
  vector<pair<ld, ld>> events;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] == 0 && y[i] == 0) {
      cur++;
    } else {
      pair<ld, ld> lr;
      if (get_range(r, x[i], y[i], lr)) {
        if (lr.second >= 2 * M_PI) {
          lr.first -= 2 * M_PI;
          lr.second -= 2 * M_PI;
        }
        
        if (lr.first < 0) {
          cur++;
          lr.first += 2 * M_PI;
        }

        events.push_back(make_pair(lr.first, 1));
        events.push_back(make_pair(lr.second, -1));
      }
    }
  }

  if (cur >= K) {
    return true;
  }
  
  sort(events.begin(), events.end());
  for (auto e : events) {
    cur += e.second;
    if (cur >= K) {
      return true;
    }
  }
  return false;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> K;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  
  ld ans = 0;
  for (ld k = MAX_R; k > EPS; k /= 2) {
    if (!can(ans + k)) {
      ans += k;
    }
  }

  cout << fixed << setprecision(12) << ans << endl;
}