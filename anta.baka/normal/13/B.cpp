#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

struct point {
  int x, y;
  point() {}
  point(int _x, int _y) : x(_x), y(_y) {}
  bool operator == (const point &a) const {
    return x == a.x && y == a.y;
  }
};

bool prod(point a, point b, point c) {
  return 1LL * (b.x - a.x) * (c.y - b.y) - 1LL * (b.y - a.y) * (c.x - b.x) == 0;
}

bool ok1(point a, point b, point c) {
  long long ac = 1LL * (a.x - c.x) * (a.x - c.x) + 1LL * (a.y - c.y) * (a.y - c.y);
  long long bc = 1LL * (b.x - c.x) * (b.x - c.x) + 1LL * (b.y - c.y) * (b.y - c.y);
  int x1 = a.x, y1 = a.y, x2 = b.x, y2 = b.y;
  if(x1 > x2)
    swap(x1, x2);
  if(y1 > y2)
    swap(y1, y2);
  return (x1 <= c.x && c.x <= x2 && y1 <= c.y && c.y <= y2) && (16 * ac >= bc) && (16 * bc >= ac);
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    pair<point, point> a[3];
    for(int i = 0; i < 3; i++)
        cin >> a[i].fi.x >> a[i].fi.y >> a[i].se.x >> a[i].se.y;
    if(a[0].fi == a[0].se || a[1].fi == a[1].se || a[2].fi == a[2].se) {
      cout << "NO\n";
      continue;
    }
    bool ok = (a[0].fi == a[1].fi || a[0].fi == a[1].se || a[0].se == a[1].fi || a[0].se == a[1].se);
    if(!ok) {
      swap(a[1], a[2]);
      ok = (a[0].fi == a[1].fi || a[0].fi == a[1].se || a[0].se == a[1].fi || a[0].se == a[1].se);
    }
    if(!ok) {
      swap(a[0], a[2]);
      ok = (a[0].fi == a[1].fi || a[0].fi == a[1].se || a[0].se == a[1].fi || a[0].se == a[1].se);
    }
    if(!ok) {
      swap(a[1], a[2]);
      ok = (a[0].fi == a[1].fi || a[0].fi == a[1].se || a[0].se == a[1].fi || a[0].se == a[1].se);
    }
    if(!ok) {
      swap(a[0], a[2]);
      ok = (a[0].fi == a[1].fi || a[0].fi == a[1].se || a[0].se == a[1].fi || a[0].se == a[1].se);
    }
    if(!ok) {
      swap(a[1], a[2]);
      ok = (a[0].fi == a[1].fi || a[0].fi == a[1].se || a[0].se == a[1].fi || a[0].se == a[1].se);
    }
    if(!ok) {
      cout << "NO\n";
      continue;
    }
    if(a[0].fi == a[1].se)
      swap(a[1].fi, a[1].se);
    else if(a[0].se == a[1].fi)
      swap(a[0].fi, a[0].se);
    else if(a[0].se == a[1].se) {
      swap(a[0].fi, a[0].se);
      swap(a[1].fi, a[1].se);
    }
    if(prod(a[0].fi, a[0].se, a[1].se)) {
      cout << "NO\n";
      continue;
    }
    if(!(prod(a[0].fi, a[0].se, a[2].fi) && prod(a[1].fi, a[1].se, a[2].se)) && !(prod(a[0].fi, a[0].se, a[2].se) && prod(a[1].fi, a[1].se, a[2].fi))) {
      cout << "NO\n";
      continue;
    }
    if(1LL * (a[0].fi.x - a[0].se.x) * (a[0].fi.x - a[0].se.x) + 1LL * (a[0].fi.y - a[0].se.y) * (a[0].fi.y - a[0].se.y) + 
      1LL * (a[1].fi.x - a[1].se.x) * (a[1].fi.x - a[1].se.x) + 1LL * (a[1].fi.y - a[1].se.y) * (a[1].fi.y - a[1].se.y) < 
      1LL * (a[0].se.x - a[1].se.x) * (a[0].se.x - a[1].se.x) + 1LL * (a[0].se.y - a[1].se.y) * (a[0].se.y - a[1].se.y)) {
      cout << "NO\n";
      continue;
    }
    if(prod(a[0].fi, a[0].se, a[2].se) && prod(a[1].fi, a[1].se, a[2].fi))
      swap(a[2].fi, a[2].se);
    if(!ok1(a[0].fi, a[0].se, a[2].fi) || !ok1(a[1].fi, a[1].se, a[2].se)) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
  }
}