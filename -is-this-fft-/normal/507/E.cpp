#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int MAX_V = 100005;
const int MAX_E = 100005;
const int INF = 1023456789;

typedef pair<int, int> Edge;

Edge make_edge (int u, int v) {
  if (u > v) {
    swap(u, v);
  }

  return make_pair(u, v);
}

vector<int> adj [MAX_V];
vector<int> preds [MAX_V];
int dist [MAX_V];

vector<int> topo;
bool vis [MAX_V];
void dfs (int vertex) {
  vis[vertex] = true;
  for (int pred : preds[vertex]) {
    if (!vis[pred]) {
      dfs(pred);
    }
  }
  topo.push_back(vertex);
}

int score [MAX_V];
int best_pred [MAX_V];

int main () {
  map<Edge, bool> state_map;
  set<Edge> blacks;
  set<Edge> whites;

  ios::sync_with_stdio(false);
  
  int vertexc, edgec;
  cin >> vertexc >> edgec;
  for (int i = 0; i < edgec; i++) {
    int u, v, state;
    cin >> u >> v >> state;

    adj[u].push_back(v);
    adj[v].push_back(u);

    Edge uv = make_edge(u, v);
    if (state == 1) {
      blacks.insert(uv);
    } else {
      whites.insert(uv);
    }

    state_map[uv] = state;
  }

  for (int i = 1; i <= vertexc; i++) {
    dist[i] = INF;
  }
  dist[1] = 0;

  queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    int vertex = Q.front();
    Q.pop();
    
    for (int child : adj[vertex]) {
      if (dist[child] == INF) {
        dist[child] = dist[vertex] + 1;
        Q.push(child);
      }

      if (dist[child] == dist[vertex] + 1) {
        preds[child].push_back(vertex);
      }
    }
  }

  dfs(vertexc);

  for (int i = 1; i <= vertexc; i++) {
    score[i] = INF;
  }
  score[1] = 0;

  for (int i = 1; i < (int) topo.size(); i++) {
    int vertex = topo[i];

    for (int pred : preds[vertex]) {
      Edge preded = make_edge(pred, vertex);
      int new_score;
      if (state_map[preded] == 0) {
        new_score = score[pred] + 1;
      } else {
        new_score = score[pred] - 1;
      }

      if (new_score < score[vertex]) {
        score[vertex] = new_score;
        best_pred[vertex] = pred;
      }
    }
  }

  vector<pair<Edge, int>> ans;
  for (int i = vertexc; i != 1; i = best_pred[i]) {
    Edge ipi = make_edge(i, best_pred[i]);
    if (state_map[ipi] == 0) {
      ans.push_back(make_pair(ipi, 1));
    } else {
      blacks.erase(ipi);
    }
  }

  for (Edge uv : blacks) {
    ans.push_back(make_pair(uv, 0));
  }

  cout << (int) ans.size() << '\n';
  for (pair<Edge, int> uvz : ans) {
    cout << uvz.first.first << " " << uvz.first.second << " " << uvz.second << '\n';
  }
}