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
    for (int& x: a) cin >> x;
    for (int i = 0; i < n; i++) {
      int b;
      cin >> b;
      a[i] -= b;
    }
    vector<long long> s(n+1);
    for (int i = 0; i < n; i++) {
      s[i+1] = s[i] + a[i];
    }
    vector<pair<int, int>> segs(m);
    for (pair<int, int>& p: segs) {
      cin >> p.first >> p.second;
    }

    set<int> non_zero_indices;
    for (int i = 0; i <= n; i++) {
      if (s[i]) non_zero_indices.insert(i);
    }
    vector<int> indeg(m);
    vector<vector<int>> G(n+1);
    vector<int> que;
    for (int i = 0; i < m; i++) {
      for (int k: {segs[i].first-1, segs[i].second}) {
        if (s[k]) {
          indeg[i]++;
          G[k].push_back(i);
        }
      }
      if (!indeg[i]) que.push_back(i);
    }

    for (int i = 0; i < (int)que.size(); i++) {
      int k = que[i];
      for (auto it = non_zero_indices.lower_bound(segs[k].first); it != non_zero_indices.end() && *it <= segs[k].second; non_zero_indices.erase(it++)) {
        for (int v: G[*it]) {
          indeg[v]--;
          if (!indeg[v]) {
            que.push_back(v);
          }
        }
        s[*it] = 0;
      }
    }

    cout << (count(s.begin(), s.end(), 0) == n+1 ? "YES" : "NO") << '\n';
  }
}