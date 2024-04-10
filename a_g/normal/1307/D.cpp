#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
const int INF = 1e9;
vector<int> G[N];
int dist[2][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(k);
  for (int& x: a) cin >> x;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int s = 0; s < 2; s++) {
    fill(dist[s], dist[s]+n+1, INF);
    int start = (s ? n : 1);
    dist[s][start] = 0;
    vector<int> que(1, start);
    for (int i = 0; i < (int)que.size(); i++) {
      int v = que[i];
      for (int u: G[v]) {
        if (dist[s][u] == INF) {
          dist[s][u] = dist[s][v]+1;
          que.push_back(u);
        }
      }
    }
  }

  // dist[0][u]+dist[1][v]+1, dist[1][u]+dist[0][v]+1
  sort(a.begin(), a.end(), [&] (int u, int v) {
      return dist[0][u]-dist[1][u] < dist[0][v]-dist[1][v];
      });
  int mx = -1;
  int best = 0;
  for (int v: a) {
    if (mx == -1) {
      mx = dist[0][v];
      continue;
    }
    best = max(best, mx+dist[1][v]+1);
    mx = max(mx, dist[0][v]);
  }
  cout << min(best, dist[1][1]) << '\n';
}