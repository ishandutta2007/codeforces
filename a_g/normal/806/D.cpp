#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int d[N][N];
long long dist[N];
bool vis[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  fill(dist, dist+n, 1e18);
  int mn = 1e9;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      cin >> d[i][j];
      d[j][i] = d[i][j];
      mn = min(mn, d[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i) continue;
      d[i][j] -= mn;
      dist[i] = min(dist[i], 2LL*d[i][j]);
    }
  }

  for (int steps = 0; steps < n; steps++) {
    int best = -1;
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      if (best == -1 || dist[i] < dist[best]) best = i;
    }
    vis[best] = 1;
    for (int i = 0; i < n; i++) {
      dist[i] = min(dist[i], dist[best]+d[best][i]);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << dist[i]+1LL*(n-1)*mn << '\n';
  }
}