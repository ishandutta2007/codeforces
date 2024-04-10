#include <iostream>
#include <vector>

const int MAX_CITY = 85;
const int MAX_EDGE = 2005;
const int INF = 1023456789;

using namespace std;

struct edge {
  int to, weight;

  edge (int _to, int _weight) {
    to = _to;
    weight = _weight;
  }
};

bool fits (int cur, int bound, edge e) {
  return ((min(cur, bound) < e.to) &&
          (e.to < max(cur, bound)));
}

vector<edge> adj [MAX_CITY];
int dp [MAX_CITY][MAX_CITY][MAX_CITY];

int main () {
  ios::sync_with_stdio(false);

  int vertexc, visitc, edgec;
  cin >> vertexc >> visitc >> edgec;
  
  for (int i = 0; i < edgec; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back(edge(v, w));
  }

  for (int i = 1; i <= vertexc; i++) {
    for (int j = 0; j <= vertexc + 1; j++) {
      for (int k = 0; k <= visitc; k++) {
        dp[i][j][k] = INF;
      }
    }
  }

  for (int i = 1; i <= vertexc; i++) {
    dp[i][0][0] = 0;
    dp[i][vertexc + 1][0] = 0;
  }

  for (int k = 0; k < visitc - 1; k++) {
    for (int i = 1; i <= vertexc; i++) {
      for (int j = 0; j <= vertexc + 1; j++) {
        for (int p = 0; p < (int) adj[i].size(); p++) {
          if (fits(i, j, adj[i][p])) {
            dp[adj[i][p].to][i][k + 1] = min(dp[adj[i][p].to][i][k + 1],
                                             dp[i][j][k] + adj[i][p].weight);
            dp[adj[i][p].to][j][k + 1] = min(dp[adj[i][p].to][j][k + 1],
                                             dp[i][j][k] + adj[i][p].weight);
          }
        }
      }
    }
  }

  int ans = INF;
  for (int i = 1; i <= vertexc; i++) {
    for (int j = 0; j <= vertexc + 1; j++) {
      ans = min(ans, dp[i][j][visitc - 1]);
    }
  }

  cout << (ans == INF ? -1 : ans) << endl;
}