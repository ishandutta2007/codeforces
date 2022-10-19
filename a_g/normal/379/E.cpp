#include <bits/stdc++.h>
using namespace std;

double calc(vector<pair<int, int>> a) {
  vector<tuple<int, int, double>> hull;
  // (l, r) is the hull starting from s
  for (auto& [l, r]: a) {
    double s = 0;
    while (hull.size()) {
      int old_l = get<0>(hull.back());
      int old_r = get<1>(hull.back());
      if (r-l == old_r-old_l) {
        hull.pop_back();
        continue;
      }
      s = 1.0*(old_l-l)/(r-l+old_l-old_r);
      if (s < get<2>(hull.back())) {
        hull.pop_back();
        continue;
      }
      break;
    }
    hull.emplace_back(l, r, max(0.0, s));
  }
  double ans = 0;
  for (int i = 0; i < (int)hull.size(); i++) {
    int x = get<0>(hull[i]);
    int y = get<1>(hull[i]);
    double l = get<2>(hull[i]);
    if (l >= 1.0) break;
    double r = 1.0;
    if (i+1 < (int)hull.size()) {
      r = min(r, get<2>(hull[i+1]));
    }
    double m = (l+r)/2;
    ans += (r-l)*(x+(y-x)*m);
  }
  return ans;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.second-a.first != b.second-b.first) {
    return (a.second-a.first) < (b.second - b.first);
  }
  return a.first < b.first;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(15);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> poly(n, vector<int>(k+1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      cin >> poly[i][j];
    }
  }

  vector<double> ans(n);
  for (int j = 0; j < k; j++) {
    double pre = 0;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
      pair<int, int> seg = make_pair(poly[i][j], poly[i][j+1]);
      a.insert(upper_bound(a.begin(), a.end(), seg, cmp), seg);
      double area = calc(a);
      ans[i] += area-pre;
      pre = area;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
}