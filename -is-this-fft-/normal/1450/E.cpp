#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> edge;
#define u first
#define v second

const int MAX_N = 205;

int dist [MAX_N][MAX_N];

int main () {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = MAX_N;
    }
    dist[i][i] = 0;
  }
  
  vector<pair<int, int>> edges (m);
  vector<int> dirs (m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].u >> edges[i].v >> dirs[i];

    if (dirs[i] == 1) {
      dist[edges[i].u][edges[i].v] = 1;
      dist[edges[i].v][edges[i].u] = -1;
    } else {
      dist[edges[i].u][edges[i].v] = 1;
      dist[edges[i].v][edges[i].u] = 1;
    }
  }
  
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  pair<int, int> best = make_pair(0, -1);
  for (int i = 1; i <= n; i++) {
    int mn = dist[i][1], mx = dist[i][1];
    bool ok = true;
    for (int j = 1; j <= n; j++) {
      mn = min(mn, dist[i][j]);
      mx = max(mx, dist[i][j]);
    }

    for (int j = 0; j < m; j++) {
      auto e = edges[j];
      int dir = dirs[j];

      if (abs(dist[i][e.u] - dist[i][e.v]) != 1) {
        ok = false;
      }

      if (dir && dist[i][e.v] - dist[i][e.u] != 1) {
        ok = false;
      }
    }

    if (ok) {
      best = max(best, make_pair(mx - mn, i));
    }
  }

  if (best.second == -1) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  cout << best.first << endl;
  int row = best.second;
  for (int j = 1; j <= n; j++) {
    cout << best.first + dist[row][j] << " ";
  }
  cout << endl;
}