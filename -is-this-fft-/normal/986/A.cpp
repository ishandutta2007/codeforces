#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_V = 100005;
const int MAX_G = 105;

vector<int> adj [MAX_V];
vector<int> producers [MAX_G];
vector<int> dist [MAX_V];

int main () {  
  int vertexc, edgec, goodc, necess;
  cin >> vertexc >> edgec >> goodc >> necess;

  for (int i = 1; i <= vertexc; i++) {
    dist[i] = vector<int> (MAX_G, MAX_V);
    
    int type;
    cin >> type;

    producers[type].push_back(i);
  }

  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int k = 1; k <= goodc; k++) {
    vector<int> Q;
    for (int v : producers[k]) {
      Q.push_back(v);
      dist[v][k] = 0;
    }

    for (int q = 0; q < Q.size(); q++) {
      int cur = Q[q];

      for (int nxt : adj[cur]) {
        if (dist[nxt][k] == MAX_V) {
          dist[nxt][k] = dist[cur][k] + 1;
          Q.push_back(nxt);
        }
      }
    }
  }

  for (int i = 1; i <= vertexc; i++) {
    sort(dist[i].begin(), dist[i].end());

    int sum = 0;
    for (int j = 0; j < necess; j++) {
      sum += dist[i][j];
    }

    cout << sum << " ";
  }
  cout << endl;
}