#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> G[N], G2[N];
int indeg[N], par[N];
bool parity[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }

    bool win = 1;
    function<void(int, int)> make_edge = [&] (int u, int v) {
      G2[u].push_back(v);
      indeg[v]++;
    };

    function<void(int, int)> dfs = [&] (int v, int p) {
      vector<vector<int>> parts(2);
      par[v] = p;
      for (int u: G[v]) {
        if (u != p) {
          dfs(u, v);
          parts[parity[u]].push_back(u);
        }
      }
      int d = parts[1].size()-parts[0].size();
      if (v == p) {
        if (d > 1 || d < 0) {
          win = 0;
          return;
        }
      }
      else {
        if (d > 2 || d < -1) {
          win = 0;
          return;
        }
        if (d > 0) {
          parity[v] = 0;
          parts[0].push_back(v);
        }
        else {
          parity[v] = 1;
          parts[1].push_back(v);
        }
      }

      int k = parts[0].size();
      int l = parts[1].size();
      if (k == l) {
        for (int i = 0; i < k; i++) {
          make_edge(parts[0][i], parts[1][i]);
        }
        for (int i = 0; i < k-1; i++) {
          make_edge(parts[1][i], parts[0][i+1]);
        }
      }
      else {
        assert(l == k+1);
        for (int i = 0; i < k; i++) {
          make_edge(parts[1][i], parts[0][i]);
          make_edge(parts[0][i], parts[1][i+1]);
        }
      }
    };

    dfs(1, 1);
    if (win) {
      cout << "YES\n";
      vector<int> que;
      for (int i = 2; i <= n; i++) {
        if (indeg[i] == 0) {
          que.push_back(i);
        }
      }
      for (int i = 0; i < que.size(); i++) {
        int v = que[i];
        cout << v << " " << par[v] << '\n';
        for (int u: G2[v]) {
          indeg[u]--;
          if (indeg[u] == 0) {
            que.push_back(u);
          }
        }
      }
    }
    else {
      cout << "NO\n";
    }
    for (int i = 1; i <= n; i++) {
      G[i].clear();
      G2[i].clear();
      indeg[i] = 0;
    }
  }
}