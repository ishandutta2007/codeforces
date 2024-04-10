#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int MAX_W = 1005;

vector<int> adj [MAX_W];
ll weight [MAX_W][MAX_W];
bool cust [MAX_W][MAX_W];

ll dist [MAX_W];
ll last [MAX_W];
bool vis [MAX_W];

int main () {
  int vertexc, edgec, target, source, sink;
  cin >> vertexc >> edgec >> target >> source >> sink;

  for (int i = 0; i < edgec; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back(v);
    adj[v].push_back(u);
    weight[u][v] = w;
    weight[v][u] = w;
    if (w == 0) {
      cust[u][v] = 1;
      cust[v][u] = 1;
      weight[u][v] = 1;
      weight[v][u] = 1;
    }
  }

  while (true) {
    for (int i = 0; i < vertexc; i++) {
      dist[i] = INF;
      vis[i] = 0;
    }
    dist[source] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
    Q.push(make_pair(dist[source], source));
    while (!Q.empty()) {
      pair<ll, int> qtop = Q.top();
      Q.pop();
      
      int cur = qtop.second;
      if (!vis[cur]) {
        vis[cur] = 1;

        for (int nxt : adj[cur]) {
          if (dist[cur] + weight[cur][nxt] < dist[nxt]) {
            dist[nxt] = dist[cur] + weight[cur][nxt];
            last[nxt] = cur;
            Q.push(make_pair(dist[nxt], nxt));
          }
        }
      }
    }

    if (dist[sink] > target) {
      cout << "NO" << endl;
      return 0;
    }
    
    if (dist[sink] == target) {
      cout << "YES" << endl;
      for (int i = 0; i < vertexc; i++) {
        for (int nxt : adj[i]) {
          if (nxt > i) {
            cout << i << " " << nxt << " " << weight[i][nxt] << '\n';
          }
        }
      }
      return 0;
    }

    ll remain = target - dist[sink];
    pair<int, int> to_change = {-1, -1};
    for (int u = sink; u != source; u = last[u]) {
      if (cust[u][last[u]]) {
        to_change = make_pair(u, last[u]);
      }
    }

    if (to_change.first == -1) {
      cout << "NO" << endl;
      return 0;
    }

    weight[to_change.first][to_change.second] += remain;
    weight[to_change.second][to_change.first] += remain;
  }
}