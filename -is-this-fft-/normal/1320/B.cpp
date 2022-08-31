#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> adj [MAX_N];
int dist [MAX_N];
int sdist [MAX_N];
int nxt [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[v].push_back(u);
  }

  int k;
  cin >> k;

  vector<int> path (k);
  for (int i = 0; i < k; i++) {
    cin >> path[i];
  }

  for (int i = 0; i < k - 1; i++) {
    nxt[path[i]] = path[i + 1];
  }

  for (int i = 1; i <= n; i++) {
    dist[i] = MAX_N;
    sdist[i] = MAX_N;
  }

  dist[path.back()] = 0;
  queue<int> Q;
  Q.push(path.back());

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    for (int v : adj[cur]) {
      if (dist[v] == MAX_N) {
        dist[v] = dist[cur] + 1;
        Q.push(v);
      }

      if ((sdist[v] == MAX_N) && (cur != nxt[v])) {
        sdist[v] = dist[cur] + 1;
      }
    }
  }

  int mn = 0, mx = 0;
  for (int i = 0; i < (int) path.size() - 1; i++) {
    if (sdist[path[i]] == dist[path[i]]) mx++;
    if (dist[path[i]] - 1 != dist[path[i + 1]]) mn++;
  }

  cout << mn << " " << mx << '\n';
}