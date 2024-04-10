#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
  int n, m;
  cin >> n >> m;

  struct event {
    li x, d;

    bool operator<(const event& rhs) const {
      return x < rhs.x;
    }
  };

  struct point {
    li x, y;

    point transform() const {
      return point{-y - x, -y + x};
    }
  };

  vector<point> orig;

  vector<event> events;
  for (int i = 0; i < n; ++i) {
    li x, p;
    cin >> x >> p;

    orig.push_back(point{x, p});

    events.push_back(event{x - p, 1});
    events.push_back(event{x, -2});
    events.push_back(event{x + p, 1});
  }
  sort(all(events));

  li last_x = -2e9;
  li slope = 0;
  li last_y = 0;

  vector<point> points;

  for (event e : events) {
    last_y += (e.x - last_x) * slope;
    last_x = e.x;

    if (!points.empty() && points.back().x == e.x) {
      points.pop_back();
    }
    points.push_back(point{last_x, last_y});
    //cout << "pre_res " << last_x << " " << last_y << "\n";

    slope += e.d;
  }

  point min_p{(li)1e18, (li)1e18};
  for (auto p : points) {
    //cout << "res " << p.x << " " << p.y << "\n";

    p.y -= m;
    if (p.y <= 0) continue;

    p = p.transform();
    min_p.x = min(min_p.x, p.x);
    min_p.y = min(min_p.y, p.y);
  }

  string ans;
  for (auto p : orig) {
    p = p.transform();
    if (p.x <= min_p.x && p.y <= min_p.y) {
      ans += '1';
    } else {
      ans += '0';
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#if 1
  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }
#endif

  //solve(false);

  return 0;
}