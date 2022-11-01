#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 5e16 + 5;

vector <pair <ll, ll>> vec;
ll x, y, ax, ay, bx, by, xs, ys, t;

int main() {
  cin >> x >> y >> ax >> ay >> bx >> by >> xs >> ys >> t;
  vec.emplace_back(x, y);
  while (true) {
    x = ax * x + bx, y = ay * y + by;
    if (x < INF and y < INF) vec.emplace_back(x, y); 
    else break;
  }
  // for (auto it : vec) cout << it.first << " " << it.second << endl;
  // cout << vec.size() << endl;
  int ans = 0;
  for (int i = 0; i < vec.size(); ++i) {
    for (int j = i; j < vec.size(); ++j) {
      ll cur = abs(xs - vec[i].first) + abs(ys - vec[i].second);
      for (int k = i; k < j; ++k) {
        cur += abs(vec[k + 1].first - vec[k].first) + abs(vec[k + 1].second - vec[k].second);
        if (cur > t) break;
      }
      if (cur <= t) ans = max(ans, j - i + 1);
    }
  }
  for (int i = 0; i < vec.size(); ++i) {
    for (int j = i; j < vec.size(); ++j) {
      ll cur = abs(xs - vec[j].first) + abs(ys - vec[j].second);
      for (int k = i; k < j; ++k) {
        cur += abs(vec[k + 1].first - vec[k].first) + abs(vec[k + 1].second - vec[k].second);
        if (cur > t) break;
      }
      if (cur <= t) ans = max(ans, j - i + 1);
    }
  }
  cout << ans << endl;
  return 0;
}