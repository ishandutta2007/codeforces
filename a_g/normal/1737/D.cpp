#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int INF = 1e9;
int d[3][N];
vector<int> G[N];

struct edge {
  int u, v, w;
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for (auto& e: edges) {
      cin >> e.u >> e.v >> e.w;
      G[e.u].push_back(e.v);
      G[e.v].push_back(e.u);
    }
    for (int i: {0, 1, 2}) {
      vector<int> que;
      for (int v = 1; v <= n; v++) {
        d[i][v] = INF;
        bool flag = 0;
        if (i == 0) {
          flag = (v == 1);
        }
        else if (i == 1) {
          flag = (v == n);
        }
        else {
          flag = (d[0][n] == d[0][v]+d[1][v]);
        }
        if (flag) {
          que.emplace_back(v);
          d[i][v] = 0;
        }
      }

      for (int j = 0; j < (int)que.size(); j++) {
        int v = que[j];
        if (i == 2 && j > 0 && d[i][v] > d[i][que[j-1]]) {
          for (int u = 1; u <= n; u++) {
            if (d[0][u]+d[1][u] == d[2][v]+d[0][n] && d[2][u] == INF) {
              que.emplace_back(u);
              d[2][u] = d[0][u]+d[1][u]-d[0][n];
            }
          }
        }
        for (int u: G[v]) {
          if (d[i][u] == INF) {
            d[i][u] = d[i][v]+1;
            que.emplace_back(u);
          }
        }
      }
    }

    long long ans = 1e18;
    for (auto& [u, v, w]: edges) {
      int steps = min({
          d[0][u]+d[1][v],
          d[1][u]+d[0][v],
          1+d[2][u]+d[0][n],
          1+d[2][v]+d[0][n]
          });
      ans = min(ans, 1LL*(steps+1)*w);
    }
    cout << ans << '\n';
    for (int v = 1; v <= n; v++) {
      G[v].clear();
    }
  }
}