#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
int c[N];
vector<pair<int, int>> g[N];

int f(int x, int k) {
  if (k == 0) return 0;
  return min(k-1, x/(x/k+1));
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x: a) cin >> x;

    int l = a[0];
    int rmin = a.back()/k;
    int r = a.back();
    a.resize(unique(a.begin(), a.end())-a.begin());

    for (int x: a) {
      int u = x/(x/l);
      c[u]++;
      g[f(x, u)].emplace_back(x, u);
    }

    while (!c[r] && r > l) r--;
    int ans = max(r, rmin)-l;
    for (l--; l >= 0; l--) {
      for (pair<int, int>& p: g[l]) {
        int x = p.first;
        int z = p.second;
        c[z]--;
        if (f(x, l) < l) {
          c[l]++;
          g[f(x, l)].emplace_back(x, l);
        }
      }
      g[l].clear();
      g[l].shrink_to_fit();
      while (!c[r] && r > l) r--;
      ans = min(ans, max(r, rmin)-l);
    }
    cout << ans << '\n';
    fill(c, c+N, 0);
    g[0].clear();
    g[0].shrink_to_fit();
  }
}