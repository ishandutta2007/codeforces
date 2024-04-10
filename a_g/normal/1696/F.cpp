#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 1e9;
vector<int> G[N], H[N*N];
bool vh[N*N];
bool b[N][N][N];
int d[N][N];

bool check(int n) {
  for (int i = 1; i <= n; i++) {
    vector<int> que(1, i);
    for (int j = 1; j <= n; j++) {
      d[i][j] = INF;
    }
    d[i][i] = 0;
    for (int j = 0; j < (int)que.size(); j++) {
      int v = que[j];
      for (int u: G[v]) {
        if (d[i][u] == INF) {
          que.emplace_back(u);
          d[i][u] = d[i][v]+1;
        }
      }
    }
    if (que.size() < n) return 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i+1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (b[i][j][k] != (d[i][k] == d[j][k])) {
          return 0;
        }
      }
    }
  }
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;

    auto flat = [&] (int i, int j) {
      if (i > j) swap(i, j);
      return n*(i-1)+(j-1);
    };
    auto edge = [&] (int v) {
      return make_pair(v/n+1, v%n+1);
    };

    for (int i = 1; i <= n-1; i++) {
      for (int j = 1; j <= n-i; j++) {
        string s;
        cin >> s;
        for (int k = 1; k <= n; k++) {
          if (s[k-1] == '1') {
            b[i][i+j][k] = 1;
            int u = flat(i, k);
            int v = flat(i+j, k);
            H[u].push_back(v);
            H[v].push_back(u);
          }
          else {
            b[i][i+j][k] = 0;
          }
          b[i+j][i][k] = b[i][i+j][k];
        }
      }
    }
    
    vector<int> comp;
    function<void(int)> dfs = [&] (int u) {
      if (vh[u]) return;
      vh[u] = 1;
      comp.push_back(u);
      for (int v: H[u]) {
        dfs(v);
      }
    };

    for (int i = 2; i <= n; i++) {
      dfs(flat(1, i));
      if (comp.size() != n-1) {
        comp.clear();
        continue;
      }
      for (int x: comp) {
        int u = edge(x).first;
        int v = edge(x).second;
        G[u].push_back(v);
        G[v].push_back(u);
      }
      if (check(n)) {
        break;
      }
      else {
        fill(G+1, G+n+1, vector<int>());
        comp.clear();
      }
    }

    if (G[1].size()) {
      cout << "Yes\n";
      for (int i = 1; i <= n; i++) {
        for (int u: G[i]) {
          if (u > i) {
            cout << i << " " << u << '\n';
          }
        }
      }
    }
    else {
      cout << "No\n";
    }

    fill(vh, vh+n*n, 0);
    fill(H, H+n*n, vector<int>());
    fill(G+1, G+n+1, vector<int>());
  }
}