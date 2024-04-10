#include <bits/stdc++.h>
using namespace std;

const int N = 1<<16;
vector<int> G[N];
int p[N], col[N];
bool take[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < (n<<(n-1)); i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    p[0] = 0;
    take[0] = 1;
    for (int i = 1; i < (1<<n); i++) {
      vector<int> cand = G[p[i&(i-1)]];
      for (int j: cand) {
        if (take[j]) continue;
        bool good = 1;
        for (int k = 0; k < n; k++) {
          if (i&(1<<k)) {
            //cout << i << " " << j << " " << k << endl;
            int v = p[i^(1<<k)];
            if (find(G[v].begin(), G[v].end(), j) == G[v].end()) {
              good = 0;
              break;
            }
          }
        }

        if (good) {
          p[i] = j;
          take[j] = 1;
          break;
        }
      }
    }

    for (int i = 0; i < (1<<n); i++) {
      cout << p[i] << ' ';
      G[i].clear();
    }
    cout << '\n';
    if (__builtin_popcount(n) != 1) {
      cout << "-1\n";
    }
    else {
      for (int i = 0; i < (1<<n); i++) {
        for (int j = 0; j < n; j++) {
          if (i&(1<<j)) {
            col[p[i]] ^= j;
          }
        }
      }
      for (int i = 0; i < (1<<n); i++) {
        cout << col[i] << ' ';
      }
      cout << '\n';
    }
    fill(p, p+(1<<n), 0);
    fill(take, take+(1<<n), 0);
    fill(col, col+(1<<n), 0);
  }
}