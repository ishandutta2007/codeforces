#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

const int MAX_N = 1e3 + 5;

int dist [MAX_N][MAX_N];
vector<int> adj [MAX_N];

vector<int> comp [MAX_N];
int color [MAX_N];

void dfs (int u, int c) {
  comp[abs(c)].push_back(u);
  color[u] = c;
  for (int nxt : adj[u]) {
    if (color[nxt] == 0) {
      dfs(nxt, -c);
    }

    if (color[nxt] == color[u]) {
      failure();
    }
  }
}

int diam (const vector<int> &cmp) {
  int ans = 0;
  for (int s : cmp) {
    for (int u : cmp) {
      dist[s][u] = MAX_N;
    }

    vector<int> Q;
    dist[s][s] = 0;
    Q.push_back(s);
    int qptr = 0;
    while (qptr < (int) Q.size()) {
      int u = Q[qptr];
      qptr++;

      for (int nxt : adj[u]) {
        if (dist[s][nxt] == MAX_N) {
          dist[s][nxt] = dist[s][u] + 1;
          Q.push_back(nxt);
        }
      }
    }

    for (int u : cmp) {
      if (dist[s][u] != MAX_N) {
        ans = max(ans, dist[s][u]);
      }
    }
  }

  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (color[i] == 0) {
      dfs(i, i);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!comp[i].empty()) {
      ans += diam(comp[i]);
    }
  }
  cout << ans << endl;
}