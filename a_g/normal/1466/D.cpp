#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> G[N];
int w[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    long long ans = accumulate(w+1, w+n+1, 0LL);
    vector<int> vals;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < (int)G[i].size()-1; j++) {
        vals.push_back(w[i]);
      }
    }
    sort(vals.begin(), vals.end(), greater<int>());
    cout << ans;
    for (int k: vals) {
      ans += k;
      cout << ' ' << ans;
    }
    cout << '\n';

    for (int i = 1; i <= n; i++) {
      G[i].clear();
    }
  }
}