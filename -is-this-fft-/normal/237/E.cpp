#include <iostream>
#include <vector>
#include <queue>

const int INF = 1023456789;

using namespace std;

class graph {
  vector<int> *adj;
  int **capac, **cost, *dist, *prev, vertexc;

public:
  graph (int size) {
    vertexc = size;
    adj = new vector<int> [vertexc];
    capac = new int* [vertexc];
    cost = new int* [vertexc];
    dist = new int [vertexc];
    prev = new int [vertexc];
    
    for (int i = 0; i < vertexc; i++) {
      capac[i] = new int [vertexc];
      cost[i] = new int [vertexc];
      for (int j = 0; j < vertexc; j++) {
	capac[i][j] = 0;
	cost[i][j] = 0;
      }
    }
  }

  void add_edge (int u, int v, int cap, int cst) {
    if (capac[u][v] != 0) {
      capac[u][v] += cap;
    } else {
      adj[u].push_back(v);
      adj[v].push_back(u);
      capac[u][v] = cap;
      cost[u][v] = cst;
      cost[v][u] = -cst;
    }
  }

  pair<int, int> max_flow (int source, int sink) {
    int ans_flow = 0, ans_cost = 0;

    while (true) {
      for (int i = 0; i < vertexc; i++) {
	dist[i] = INF;
	prev[i] = -1;
      }

      dist[source] = 0;
    
      for (int i = 0; i < vertexc; i++) {
	for (int j = 0; j < vertexc; j++) {
	  for (int k = 0; k < adj[j].size(); k++) {
	    if (capac[j][adj[j][k]] > 0 &&
		dist[j] + cost[j][adj[j][k]] < dist[adj[j][k]]) {
	      dist[adj[j][k]] = dist[j] + cost[j][adj[j][k]];
	      prev[adj[j][k]] = j;
	    }
	  }
	}
      }

      if (dist[sink] == INF) {
	break;
      }

      int pathc = INF; /* Get the capacity of the shortest path */
      for (int cur = sink; cur != source; cur = prev[cur]) {
	pathc = min(pathc, capac[prev[cur]][cur]);
      }

      for (int cur = sink; cur != source; cur = prev[cur]) {
	capac[prev[cur]][cur] -= pathc; /* Decrement forward arcs */
	capac[cur][prev[cur]] += pathc; /* Increment backward arcs */
      }

      ans_flow += pathc;
      ans_cost += pathc * dist[sink];
    }

    return make_pair(ans_flow, ans_cost);
  }

  void print_graph () {
    for (int i = 0; i < vertexc; i++) {
      for (int j = 0; j < adj[i].size(); j++) {
	cout << i << " " << adj[i][j] << " " 
	     << capac[i][adj[i][j]] << " " << cost[i][adj[i][j]] << endl;
      }
    }
  }
};

const int OFFS = 30;

int main () {
  string target;
  cin >> target;

  int stringc;
  cin >> stringc;

  graph network (OFFS + stringc);
  int source = OFFS - 2, sink = OFFS - 1;

  for (int i = 0; i < stringc; i++) {
    string si;
    int cap;
    cin >> si >> cap;
    
    network.add_edge(OFFS + i, sink, cap, 0);

    for (int j = 0; j < si.size(); j++) {
      network.add_edge(si[j] - 'a', OFFS + i, 1, i + 1);
    }
  }

  for (int i = 0; i < target.size(); i++) {
    network.add_edge(source, target[i] - 'a', 1, 0);
  }

  // network.print_graph();
  pair<int, int> ans = network.max_flow(source, sink);
  
  if (ans.first != target.size()) {
    cout << -1 << endl;
  } else {
    cout << ans.second << endl;
  }
}