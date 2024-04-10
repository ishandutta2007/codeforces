#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> cnt(n);
    int pos = -1;
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == cur) {
        cnt[pos]++;
      }
      else {
        cnt[++pos]++;
        cur = a[i];
      }
    }
    a.resize(unique(a.begin(), a.end())-a.begin());
    vector<vector<int>> cnt_table(n+1);
    for (int i = pos; i >= 0; i--) {
      cnt_table[cnt[i]].push_back(i);
    }
    vector<int> candidate_counts;
    for (int i = 1; i <= n; i++) {
      if (cnt_table[i].size()) {
        candidate_counts.push_back(i);
      }
    }

    set<pair<int, int>> bad;
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      int x = lower_bound(a.begin(), a.end(), u)-a.begin();
      int y = lower_bound(a.begin(), a.end(), v)-a.begin();
      bad.emplace(x, y);
    }

    long long ans = 0;
    for (int i = 0; i <= pos; i++) {
      for (int k: candidate_counts) {
        if (k > cnt[i]) break;
        for (int j: cnt_table[k]) {
          if (j == i) continue;
          if (!bad.count(make_pair(min(i, j), max(i, j)))) {
            ans = max(ans, 1LL*(cnt[i]+cnt[j])*(a[i]+a[j]));
            break;
          }
        }
      }
    }
    cout << ans << '\n';
  }
}