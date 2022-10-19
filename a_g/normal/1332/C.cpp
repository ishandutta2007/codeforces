#include <bits/stdc++.h>
using namespace std;

class dsu {
  public:
    vector<int> parents;
    vector<int> sizes;
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      sizes.resize(n, 1);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      if (sizes[a] > sizes[b]) swap(a, b);
      parents[a] = b;
      sizes[b] += sizes[a];
      return 1;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    dsu D(n);
    for (int i = 0; i < n; i++) {
      D.join(i, n-1-i);
    }
    for (int i = 0; i+k < n; i++) {
      D.join(i, i+k);
    }
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
      int r = D.root(i);
      if (!m.count(r)) {
        m[r] = vector<int>(26);
      }
      m[r][s[i]-'a']++;
    }
    int ans = 0;
    for (const pair<int, vector<int>>& p: m) {
      vector<int> a = p.second;
      ans += accumulate(a.begin(), a.end(), 0) - *max_element(a.begin(), a.end());
    }
    cout << ans << '\n';
  }
}