/*
start thinking:
BULB:
result of thinking: Lost.

MO:  <=> 
1e-9.
CF442E.
rO_irO_{i - l + 1}
 ~ O_{i + l - 1}k-11: 
PrO_{i - l + 1} ~ O_{i + l - 1}k-1.
O_j6rr
O(k). checknlogn
klogn.
**:  ~ **

start coding: 8:00
AC: 11:30

TLE:
- O_{i - l + 1} ~ O_{i + l - 1}, 
-  while (rb - lb < EPS) EPS
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

const ldouble EPS = 1e-11;
const ldouble pi = acos(-1);
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

#define maxn 50005
int n, l, k;
Point a[maxn];

// max
namespace Sgt {
  int add[131085], maxi[131085];

  void init(int n) {
    int foo = 1 << (33 - __builtin_clz(n - 1));
    for (int i = 1; i < foo; i++)
      add[i] = maxi[i] = 0;
  }

  void up(int u) {
    maxi[u] = max(maxi[u << 1], maxi[u << 1 | 1]) + add[u];
  }

  void down(int u) {
    if (add[u]) {
      maxi[u << 1] += add[u];
      add[u << 1] += add[u];
      maxi[u << 1 | 1] += add[u];
      add[u << 1 | 1] += add[u];
      add[u] = 0;
    }
  }

  void inc(int u, int l, int r, int ql, int qr, int x) {
    if (ql <= l && r <= qr) {
      maxi[u] += x;
      add[u] += x;
      return;
    }
    down(u);
    int mid = (l + r) >> 1;
    if (ql <= mid)
      inc(u << 1, l, mid, ql, qr, x);
    if (mid < qr)
      inc(u << 1 | 1, mid + 1, r, ql, qr, x);
    up(u);
  }
}

ldouble ans;
// (belong, point_id_list)
map<P, set<int>> buc;

void rebuild(int id) {
  buc.clear();
  for (int i = max(1, id - l + 1); i <= min(n, id + l - 1); i++)
    buc[{floor(a[i].x / ans / 2), floor(a[i].y / ans / 2)}].insert(i);
}

vector<pair<ldouble, int>> events;

void cover(ldouble lb, ldouble rb, int id) {
  if (lb <= -pi)
    lb += 2 * pi;
  if (lb > pi)
    lb -= 2 * pi;
  if (rb <= -pi)
    rb += 2 * pi;
  if (rb > pi)
    rb -= 2 * pi;
  if (lb > rb) {
    events.push_back({lb, id});
    events.push_back({2 * pi, -id});
    events.push_back({-2 * pi, id});
    events.push_back({rb, -id});
  } else {
    events.push_back({lb, id});
    events.push_back({rb, -id});
  }
}

bool check(int id, ldouble r) {
  events.clear();
  int bx = floor(a[id].x / ans / 2), by = floor(a[id].y / ans / 2);
  for (int i = bx - 1; i <= bx + 1; i++) {
    for (int j = by - 1; j <= by + 1; j++) {
      auto it = buc.find({i, j});
      if (it == buc.end())
        continue;
      for (auto p : it->second) {
        if (a[p] == a[id] || (a[p] - a[id]).norm() > 4 * r * r - EPS)
          continue;
        ldouble mid = atan2(a[p].y - a[id].y, a[p].x - a[id].x),
                var = acos((a[p] - a[id]).len() / 2 / r);
        cover(mid - var, mid + var, p);
      }
    }
  }
  sort(events.begin(), events.end());
  if (events.empty())
    return false;
  bool ok = false;
  for (int i = 0; i < (int)events.size(); i++) {
    if (events[i].second > 0)
      Sgt::inc(1, 1, n, max(id, events[i].second),
                 min(events[i].second, id) + l - 1, 1);
    else
      Sgt::inc(1, 1, n, max(id, -events[i].second),
                 min(-events[i].second, id) + l - 1, -1);
    ok |= i + 1 < (int)events.size() && events[i].first + EPS < events[i + 1].first
            && Sgt::maxi[1] >= k - 1;
  }
  return ok;
}

void solve() {
  scanf("%d%d%d", &n, &l, &k);
  for (int i = 1; i <= n; i++)
    scanf("%Lf%Lf", &a[i].x, &a[i].y);
  Sgt::init(n);
  ans = 1e8 * sqrt(2);
  rebuild(1);
  for (int i = 1; i <= n; i++) {
    if (!check(i, ans)) {
      if (i < n && i >= l)
        buc[{floor(a[i - l + 1].x / ans / 2),
          floor(a[i - l + 1].y / ans / 2)}].erase(i - l + 1);
      if (i + l <= n)
        buc[{floor(a[i + l].x / ans / 2),
          floor(a[i + l].y / ans / 2)}].insert(i + l);
    } else {
      ldouble lb = 0, rb = ans;
      for (int j = 1; j <= 63; j++) {
        ldouble mid = (lb + rb) / 2;
        if (check(i, mid))
          rb = mid;
        else
          lb = mid;
      }
      ans = lb;
      if (i < n)
        rebuild(i + 1);
    }
  }
  printf("%.11Lf\n", ans);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}