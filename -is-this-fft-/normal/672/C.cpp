#include <iostream>
#include <limits>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>

const int MAX_BOTTLE = 100005;
const double INF = std::numeric_limits<double>::infinity();

using namespace std;

struct point {
  double x, y;
 
  point () {
    x = 0;
    y = 0;
  }

  point (double _x, double _y) {
    x = _x;
    y = _y;
  }
};

double dist (point p, point q) {
  return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

point bottles [MAX_BOTTLE];
point abottles [MAX_BOTTLE];
point bbottles [MAX_BOTTLE];
point adil, bera, bin;

bool compa (point p, point q) {
  return dist(bin, p) - dist(adil, p) > dist(bin, q) - dist(adil, q);
}

bool compb (point p, point q) {
  return dist(bin, p) - dist(bera, p) > dist(bin, q) - dist(bera, q);
}

bool operator!= (point p, point q) {
  return (p.x != q.x) || (p.y != q.y);
}

int main () {
  cin >> adil.x >> adil.y >> bera.x >> bera.y >> bin.x >> bin.y;

  int bottlec;
  cin >> bottlec;
  double sdist = 0;
  for (int i = 0; i < bottlec; i++) {
    cin >> bottles[i].x >> bottles[i].y;
    sdist += 2 * dist(bin, bottles[i]);
    abottles[i] = bottles[i];
    bbottles[i] = bottles[i];
  }

  cout << fixed << setprecision(12);

  if (bottlec == 1) {
    cerr << "var 0" << endl;
    cout << min(dist(adil, bottles[0]), dist(bera, bottles[0])) + 
      dist(bin, bottles[0]) << endl;
    return 0;
  }

  sort(abottles, abottles + bottlec, compa);
  sort(bbottles, bbottles + bottlec, compb);

  if (abottles[0] != bbottles[0]) {
    vector<double> vars (3);
    vars[0] = sdist - dist(bin, abottles[0]) + dist(adil, abottles[0]);
    vars[1] = sdist - dist(bin, bbottles[0]) + dist(bera, bbottles[0]);
    vars[2] = sdist - dist(bin, abottles[0]) + dist(adil, abottles[0])
      - dist(bin, bbottles[0]) + dist(bera, bbottles[0]);
    double ans = INF;
    for (int i = 0; i < 3; i++) {
      ans = min(ans, vars[i]);
    }
    cout << ans << endl;
  } else {
    vector<double> vars (4);
    vars[0] = sdist - dist(bin, abottles[0]) + dist(adil, abottles[0]);
    vars[1] = sdist - dist(bin, bbottles[0]) + dist(bera, bbottles[0]);
    vars[2] = sdist - dist(bin, abottles[0]) + dist(adil, abottles[0])
      - dist(bin, bbottles[1]) + dist(bera, bbottles[1]);
    vars[3] = sdist - dist(bin, abottles[1]) + dist(adil, abottles[1])
      - dist(bin, bbottles[0]) + dist(bera, bbottles[0]);
    double ans = INF;
    for (int i = 0; i < 4; i++) {
      ans = min(ans, vars[i]);
    }
    cout << ans << endl;
  }
}