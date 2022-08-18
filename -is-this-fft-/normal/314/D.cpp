#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;

struct Point {
  ll x, y, id;
};

bool byx (const Point &p, const Point &q) {
  if (p.x != q.x) {
    return p.x < q.x;
  }
  return p.id < q.id;
}

struct ByY {
  bool operator() (const Point &p, const Point &q) const {
    if (p.y != q.y) {
      return p.y < q.y;
    }
    return p.id < q.id;
  }
};

const ll INF = 1e18 + 1000;
const int MAX_N = 1e5 + 5;

int n;
ll pmny [MAX_N];
ll pmxy [MAX_N];

ll smny [MAX_N];
ll smxy [MAX_N];

ll get_mxy (int l, int r) {
  ll ans = -INF;
  if (l != 0) {
    ans = max(ans, pmxy[l - 1]);
  }
  if (r != n - 1) {
    ans = max(ans, smxy[r + 1]);
  }
  return ans;
}

ll get_mny (int l, int r) {
  ll ans = INF;
  if (l != 0) {
    ans = min(ans, pmny[l - 1]);
  }
  if (r != n - 1) {
    ans = min(ans, smny[r + 1]);
  }
  return ans;
}

// points are ordered by x
bool can (ll K, const vector<Point> &points) {
  ll n = points.size();
  
  ll rptr = -1;
  for (ll i = 0; i < n; i++) {
    while (rptr + 1 < n && points[rptr + 1].x - points[i].x <= K) {
      rptr++;
    }

    if (i == 0 && rptr == n - 1) {
      return true;
    }

    if (get_mxy(i, rptr) - get_mny(i, rptr) <= K) {
      return true;
    }
  }
  return false;
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n;

  vector<Point> points;
  for (ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;

    Point p;
    p.x = x - y;
    p.y = x + y;
    p.id = i;
    points.push_back(p);
  }

  sort(points.begin(), points.end(), byx);

  pmny[0] = points[0].y;
  pmxy[0] = points[0].y;
  for (int i = 1; i < n; i++) {
    pmny[i] = min(pmny[i - 1], points[i].y);
    pmxy[i] = max(pmxy[i - 1], points[i].y);
  }

  smny[n - 1] = points[n - 1].y;
  smxy[n - 1] = points[n - 1].y;
  for (int i = n - 2; i >= 0; i--) {
    smny[i] = min(smny[i + 1], points[i].y);
    smxy[i] = max(smxy[i + 1], points[i].y);
  }
  
  if (can(0, points)) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 0;
  for (ll k = 1LL << 32; k != 0; k /= 2) {
    if (!can(ans + k, points)) {
      ans += k;
    }
  }
  ans++;

  cout << fixed << setprecision(8) << (double) ans / 2 << endl;
}