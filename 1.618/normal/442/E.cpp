/*
start thinking:
BULB:
result of thinking:

CF442E
n^2log(n)log(err^{-1})log(err^{-1})

start coding: 13:00
AC: 18:35

WA: .
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;
const ldouble pi = acos(-1.0L);
// +-EPS
const ldouble EPS = 1e-11;

struct Point {
  ldouble x, y;
  Point(ldouble xx = 0.0, ldouble yy = 0.0): x(xx), y(yy) {}
  Point operator + (Point p) {
    return Point(x + p.x, y + p.y);
  }
  Point operator - (Point p) {
    return Point(x - p.x, y - p.y);
  }
  Point operator * (ldouble lambda) {
    return Point(x * lambda, y * lambda);
  }
  Point operator / (ldouble lambda) {
    return Point(x / lambda, y / lambda);
  }
  Point operator - () {
    return Point(-x, -y);
  }
  ldouble norm() {
    return x * x + y * y;
  }
  ldouble len() {
    return sqrt(norm());
  }
  bool operator == (const Point &p) const {
    return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
  }
};
typedef Point Vector;

#define maxn 1005
int n;
Point a[maxn];
ldouble w, h;
vector<pair<ldouble, int>> events;

void cover(ldouble l, ldouble r) {
  if (l <= -pi)
    l += 2 * pi;
  if (l > pi)
    l -= 2 * pi;
  if (r <= -pi)
    r += 2 * pi;
  if (r > pi)
    r -= 2 * pi;
  if (l <= r) {
    events.push_back({l, 1});
    events.push_back({r, -1});
  } else {
    events.push_back({l, 1});
    events.push_back({pi, -1});
    events.push_back({-pi, 1});
    events.push_back({r, -1});
  }
}

bool check(int id, ldouble r) {
  events.clear();
  for (int i = 0; i < 2; i++) {
    if (a[id].x < r - EPS) {
      cover(atan2(min(h - a[id].y, sqrt(r * r - a[id].x * a[id].x)), -a[id].x),
            atan2(max(-a[id].y, -sqrt(r * r - a[id].x * a[id].x)), -a[id].x));
    }
    if (a[id].y < r - EPS) {
      cover(atan2(-a[id].y, max(-a[id].x, -sqrt(r * r - a[id].y * a[id].y))),
            atan2(-a[id].y, min(w - a[id].x, sqrt(r * r - a[id].y * a[id].y))));
    }
    if (w - a[id].x < r - EPS) {
      cover(atan2(max(-a[id].y, -sqrt(r * r - (w - a[id].x) * (w - a[id].x))), 
                  w - a[id].x), 
            atan2(min(h - a[id].y, sqrt(r * r - (w - a[id].x) * (w - a[id].x))),
                  w - a[id].x));
    }
    if (h - a[id].y < r - EPS) {
      cover(atan2(h - a[id].y,
                  min(w - a[id].x, sqrt(r * r - (h - a[id].y) * (h - a[id].y)))),
            atan2(h - a[id].y,
                  max(-a[id].x, -sqrt(r * r - (h - a[id].y) * (h - a[id].y)))));
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[id] || (a[i] - a[id]).norm() > 4 * r * r - EPS)
      continue;
    ldouble mid = atan2(a[i].y - a[id].y, a[i].x - a[id].x),
            var = acos((a[i] - a[id]).len() / 2 / r);
    cover(mid - var, mid + var);
  }
  if (events.empty())
    return true;
  sort(events.begin(), events.end());
  if (events[0].first > -pi + EPS || events.back().first < pi - EPS)
    return true;
  int cnt = 0;
  for (int i = 0; i < (int)events.size(); i++) {
    cnt += events[i].second;
    if (cnt <= 1 && i + 1 < (int)events.size()
        && events[i].first + EPS < events[i + 1].first)
      return true;
  }
  return false;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%Lf%Lf%d", &w, &h, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%Lf%Lf", &a[i].x, &a[i].y);
    chmax(a[i].x, EPS);
    chmin(a[i].x, w - EPS);
    chmax(a[i].y, EPS);
    chmin(a[i].y, h - EPS);
  }
  mt19937 rng(time(0));
  shuffle(a + 1, a + n + 1, rng);
  ldouble ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!check(i, ans + EPS))
      continue;
    ldouble lb = 0, rb = hypot(h, w);
    while (rb - lb > EPS) {
      ldouble mid = (lb + rb) / 2;
      if (check(i, mid))
        lb = mid;
      else
        rb = mid;
    }
    chmax(ans, lb);
  }
  printf("%.11Lf\n", ans);
  return 0;
}