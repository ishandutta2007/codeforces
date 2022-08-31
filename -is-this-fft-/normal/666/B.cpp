#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 3005;
const int INF = 1023456789;

vector<int> adj [MAX_V];
int dist [MAX_V][MAX_V];
vector<pair<int, int>> best3To [MAX_V];
vector<pair<int, int>> best3From [MAX_V];

void addToBest (pair<int, int> pr, vector<pair<int, int>> &best) {
  if (pr > best[0]) {
    best[2] = best[1];
    best[1] = best[0];
    best[0] = pr;
  } else if (pr > best[1]) {
    best[2] = best[1];
    best[1] = pr;
  } else if (pr > best[2]) {
    best[2] = pr;
  }
}

void calcDist (int source) {
  for (int i = 0; i < MAX_V; i++) {
    dist[source][i] = INF;
  }

  vector<int> Q;
  Q.push_back(source);
  dist[source][source] = 0;
  for (int i = 0; i < (int) Q.size(); i++) {
    int cur = Q[i];

    for (int nxt : adj[cur]) {
      if (dist[source][nxt] == INF) {
        dist[source][nxt] = dist[source][cur] + 1;
        Q.push_back(nxt);
      }
    }
  }
}

int main () {
  int vertexc, edgec;
  cin >> vertexc >> edgec;

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
  }

  for (int i = 1; i <= vertexc; i++) {
    calcDist(i);
  }

  for (int i = 1; i <= vertexc; i++) {
    best3To[i] = vector<pair<int, int>> (3, make_pair(-1, -1));
    best3From[i] = vector<pair<int, int>> (3, make_pair(-1, -1));
  }

  for (int i = 1; i <= vertexc; i++) {
    for (int j = 1; j <= vertexc; j++) {
      if (i != j && dist[i][j] < INF) {
        addToBest(make_pair(dist[i][j], j), best3From[i]);
        addToBest(make_pair(dist[i][j], i), best3To[j]);
      }
    }
  }

  int ansDist = 0;
  vector<int> ans;
  for (int v = 1; v <= vertexc; v++) {
    for (int w = 1; w <= vertexc; w++) {
      if (w != v && dist[v][w] < INF) {
        for (pair<int, int> up : best3To[v]) {
          int u = up.second;
          if (u != w && u != -1) {
            for (pair<int, int> xp : best3From[w]) {
              int x = xp.second;
              if (x != -1 && x != v && x != u) {
                int newDist = dist[u][v] + dist[v][w] + dist[w][x];
                if (newDist >= ansDist) {
                  ansDist = newDist;
                  ans = {u, v, w, x};
                }
              }
            }
          }
        }
      }
    }
  }

  for (int u : ans) {
    cout << u << " ";
  }
  cout << endl;
}