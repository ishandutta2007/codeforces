#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Edge {
  int u, v;
  ll w;
};

const int MAX_N = 505;
const ll INF = 1e18 + 2000;

int dist [MAX_N][MAX_N];

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = MAX_N;
    }
    dist[i][i] = 0;
  }

  vector<Edge> edges (m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;

    dist[edges[i].u][edges[i].v] = 1;
    dist[edges[i].v][edges[i].u] = 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  ll ans = INF;
  for (auto e : edges) {
    ans = min(ans, (ll) (1 + dist[1][e.u] + dist[e.v][n]) * e.w);
    ans = min(ans, (ll) (1 + dist[1][e.v] + dist[e.u][n]) * e.w);

    for (int k = 1; k <= n; k++) {
      ans = min(ans, (ll) (2 + dist[1][k] + dist[n][k] + dist[e.u][k]) * e.w);
      ans = min(ans, (ll) (2 + dist[1][k] + dist[n][k] + dist[e.v][k]) * e.w);
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}