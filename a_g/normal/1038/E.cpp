#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int tot[4][4], mn[4][4], deg[4][4];

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
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      mn[i][j] = INF;
    }
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int u, v, w;
    cin >> u >> w >> v;
    u--, v--;
    if (u > v) swap(u, v);
    tot[u][v] += w;
    mn[u][v] = min(mn[u][v], w);
    deg[u][v]++;
  }

  int ans = 0;
  for (int mask = 0; mask < 64; mask++) {
    int d[4] = {0, 0, 0, 0};
    dsu D(4);

    bool ok = 1;
    for (int i = 0; i < 4; i++) {
      for (int j = i+1; j < 4; j++) {
        int k = 0;
        if (i == 0) k = j-1;
        else if (i == 1) k = j+1;
        else k = j+2;
        if ((mask>>k)&1) deg[i][j]--, tot[i][j] -= mn[i][j];
        if (deg[i][j] > 0) {
          D.join(i, j);
          d[i] += deg[i][j];
          d[j] += deg[i][j];
        }
        else if (deg[i][j] < 0) ok = 0;
      }
    }

    if (ok) {
      int odds[4] = {0, 0, 0, 0};
      int wt[4] = {0, 0, 0, 0};
      for (int i = 0; i < 4; i++) {
        if (d[i]&1) odds[D.root(i)]++;
        wt[D.root(i)] += tot[i][i];
      }
      for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
          if (deg[i][j]) {
            wt[D.root(i)] += tot[i][j];
          }
        }
      }

      for (int i = 0; i < 4; i++) {
        if (odds[i] > 2) continue;
        ans = max(ans, wt[i]);
      }
    }
    
    for (int i = 0; i < 4; i++) {
      for (int j = i+1; j < 4; j++) {
        int k = 0;
        if (i == 0) k = j-1;
        else if (i == 1) k = j+1;
        else k = j+2;
        if ((mask>>k)&1) deg[i][j]++, tot[i][j] += mn[i][j];
      }
    }
  }
  cout << ans << '\n';
}