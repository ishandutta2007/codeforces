#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
int degs[N];
vector<int> nbrs[N];
int x[N];
int y[N];
int d[N];
int n;

void reset() {
  for (int i = 1; i <= n; i++) {
    degs[i] = 0;
    nbrs[i].clear();
  }
}

void dfs(int v, int p) {
  for (int u: nbrs[v]) {
    if (u != p) {
      d[u] = d[v] + 1;
      dfs(u, v);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      cin >> x[i] >> y[i];
      degs[x[i]]++;
      degs[y[i]]++;
      nbrs[x[i]].push_back(y[i]);
      nbrs[y[i]].push_back(x[i]);
    }
    if (*max_element(degs+1, degs+n+1) >= 3) {
      cout << "-1\n";
      reset();
      continue;
    }
    for (int i = 1; i <= n; i++) {
      if (degs[i] == 1) {
        d[i] = 0;
        dfs(i, i);
        break;
      }
    }
    for (int i = 0; i < n-1; i++) {
      cout << (min(d[x[i]], d[y[i]])&1 ? 2 : 3) << ' ';
    }
    cout << '\n';
    reset();
  }
}