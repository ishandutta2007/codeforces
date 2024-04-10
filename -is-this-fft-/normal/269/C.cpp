#include <iostream>
#include <queue>
#include <vector>
#include <map>

const int MAX_VERT = 200005;

using namespace std;

struct edge {
  int vertex, weight;
  
  edge (int _vertex, int _weight) {
    vertex = _vertex;
    weight = _weight;
  }
};

vector<edge> adj [MAX_VERT];
int flow [MAX_VERT], capac [MAX_VERT], vis [MAX_VERT];

int main () {
  ios::sync_with_stdio(false);

  int vertexc, edgec;
  cin >> vertexc >> edgec;

  vector<pair<int, int> > edge_ord;
  map<pair<int, int>, bool> edge_ans;

  for (int i = 0; i < edgec; i++) {
    int u, v, weight;
    cin >> u >> v >> weight;

    capac[u] += weight;
    capac[v] += weight;

    adj[u].push_back(edge(v, weight));
    adj[v].push_back(edge(u, weight));

    edge_ord.push_back(make_pair(u, v));
  }

  queue<int> que;
  que.push(1);
  flow[1] = capac[1] / 2;

  while (!que.empty()) {
    int qtop = que.front();
    que.pop();

    for (int i = 0; i < (int) adj[qtop].size(); i++) {
      if ((flow[adj[qtop][i].vertex] != capac[adj[qtop][i].vertex] / 2) ||
          (adj[qtop][i].vertex == vertexc)) {
        flow[adj[qtop][i].vertex] += adj[qtop][i].weight;
        edge_ans[make_pair(qtop, adj[qtop][i].vertex)] = 0;
        edge_ans[make_pair(adj[qtop][i].vertex, qtop)] = 1;
      
        if ((flow[adj[qtop][i].vertex] == capac[adj[qtop][i].vertex] / 2) &&
            (adj[qtop][i].vertex != vertexc)) {
          que.push(adj[qtop][i].vertex);
        }
      }
    }
  }

  for (int i = 0; i < edgec; i++) {
    cout << edge_ans[edge_ord[i]] << '\n';
  }
}