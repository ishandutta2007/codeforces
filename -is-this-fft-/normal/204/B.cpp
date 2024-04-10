#include <iostream>
#include <map>

using namespace std;

const int INF = 1e9 + 5;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  map<int, pair<int, int>> cnt;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;

    cnt[a].first++;
    if (a != b) {
      cnt[b].second++;
    }
  }

  int mn = (n + 1) / 2;
  int ans = INF;
  for (auto ppr : cnt) {
    auto pr = ppr.second;
    if (pr.first + pr.second >= mn) {
      ans = min(ans, max(0, mn - pr.first));
    }
  }

  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}