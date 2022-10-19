#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
const long long INF = 1e18;
int x[N];
int h[N];
vector<pair<int, int>> starts[N];
pair<int, int> ladder_ends[N];
vector<pair<int, long long>> points[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
      cin >> x[i];
    }
    for (int i = 0; i < k; i++) {
      int a, b, c, d;
      cin >> a >> b >> c >> d >> h[i];
      starts[a].push_back(make_pair(b, i));
      ladder_ends[i] = make_pair(c, d);
    }
    points[1].push_back(make_pair(1, 0));
    for (int i = 1; i <= n; i++) {
      sort(points[i].begin(), points[i].end());
      vector<pair<int, long long>> newpts;
      for (pair<int, long long> p: points[i]) {
        if (newpts.size() &&
            newpts.back().second + 1LL * x[i] * (p.first - newpts.back().first) <= p.second) {
          continue;
        }
        while (newpts.size() &&
            newpts.back().second + 1LL * x[i] * (newpts.back().first - p.first) >= p.second) {
          newpts.pop_back();
        }
        newpts.push_back(p);
      }
      if (!newpts.size()) continue;
      /*
      cout << i << '\n';
      for (pair<int, long long> z: newpts) {
        cout << z.first << " " << z.second << '\n';
      }
      */
      for (pair<int, int> l: starts[i]) {
        int b = l.first;
        int j = l.second;
        int z = lower_bound(newpts.begin(), newpts.end(), make_pair(b, -INF)) - newpts.begin();
        long long d = INF;
        if (z < (int)newpts.size()) d = min(d, newpts[z].second + 1LL*x[i]*(newpts[z].first-b));
        if (z) d = min(d, newpts[z-1].second + 1LL*x[i]*(b-newpts[z-1].first));
        points[ladder_ends[j].first].push_back(make_pair(ladder_ends[j].second, d-h[j]));
      }
    }

    if (!points[n].size()) {
      cout << "NO ESCAPE\n";
    }
    else {
      long long ans = INF;
      for (pair<int, long long> p: points[n]) {
        //cout << p.first <<  " " << p.second << '\n';
        ans = min(ans, p.second + 1LL*x[n]*(m-p.first));
      }
      cout << ans << '\n';
    }
    for (int i = 1; i <= n; i++) {
      points[i].clear();
      starts[i].clear();
    }
  }
}