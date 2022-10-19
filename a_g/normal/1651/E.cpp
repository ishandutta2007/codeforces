#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 3005;
vector<int> G[N];
bool vis[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < 2*n; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    vector<int> cycle(1, i);
    vis[i] = 1;
    while (1) {
      bool done = 1;
      for (int u: G[cycle.back()]) {
        if (!vis[u]) {
          cycle.push_back(u);
          done = 0;
          vis[u] = 1;
          break;
        }
      }
      if (done) break;
    }
    int l = n;
    int r = 1;
    int L = 2*n;
    int R = n+1;
    int m = cycle.size();
    for (int i = 0; i < m; i++) {
      if (i&1) {
        L = min(L, cycle[i]);
        R = max(R, cycle[i]);
      }
      else {
        l = min(l, cycle[i]);
        r = max(r, cycle[i]);
      }
    }
    cycle.insert(cycle.end(), cycle.begin(), cycle.end());

    ans += 1LL * (m/2) * (l) * (n+1-r) * (L-n) * (2*n+1-R);

    for (int j = 0; j < m; j++) {
      int maxl = INF;
      int minr = -INF;
      int maxL = INF;
      int minR = -INF;
      for (int k = j+2; k <= j+m; k++) {
        if (k&1) {
          maxl = min(maxl, cycle[k-1]);
          minr = max(minr, cycle[k-1]);
        }
        else {
          maxL = min(maxL, cycle[k-1]);
          minR = max(minR, cycle[k-1]);
        }
        if (k == j+2) continue;
        int minl = 1;
        int maxr = n;
        int minL = n+1;
        int maxR = 2*n;
        bool fail = 0;
        for (int u: {j, k}) {
          if (u&1) {
            if (cycle[u] < maxL) {
              minL = max(minL, cycle[u]+1);
            }
            else if (cycle[u] > minR) {
              maxR = min(maxR, cycle[u]-1);
            }
            else if (maxL <= minR) {
              fail = 1;
            }
          }
          else {
            if (cycle[u] < maxl) {
              minl = max(minl, cycle[u]+1);
            }
            else if (cycle[u] > minr) {
              maxr = min(maxr, cycle[u]-1);
            }
            else if (maxl <= minr) {
              fail = 1;
            }
          }
        }
        if (fail) continue;
        ans += 1LL * ((k-j-1)/2) * (maxl-minl+1) * (maxr-minr+1) * (maxL-minL+1) * (maxR-minR+1);
      }
    }
  }
  cout << ans << '\n';
}