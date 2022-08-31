#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <set>

using namespace std;

const int maxn = 200005;
set<int> adj [maxn];
int K;
queue<int> Q;
bool deleted [maxn];
int delc;

void del_edge (int u, int v) {
  if (adj[u].count(v) != 0) {
    adj[u].erase(v);
    if (!deleted[u] && (int) adj[u].size() < K) {
      deleted[u] = 1;
      delc++;
      Q.push(u);
    }
  }

  if (adj[v].count(u) != 0) {
    adj[v].erase(u);
    if (!deleted[v] && (int) adj[v].size() < K) {
      deleted[v] = 1;
      delc++;
      Q.push(v);
    }
  }
}

void del_vert (int u) {
  vector<int> todel;
  for (int v : adj[u]) {
    todel.push_back(v);
  }
  
  for (int v : todel) {
    del_edge(u, v);
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int vertexc, queryc;
  cin >> vertexc >> queryc >> K;

  vector<pair<int, int>> edges;
  for (int i = 0; i < queryc; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].insert(v);
    adj[v].insert(u);
    edges.push_back(make_pair(u, v));
  }
  
  for (int i = 1; i <= vertexc; i++) {
    if ((int) adj[i].size() < K) {
      deleted[i] = 1;
      delc++;
      Q.push(i);
    }
  }
  
  deque<int> ans;
  for (int i = 0; i < queryc; i++) {
    while (!Q.empty()) {
      int qtop = Q.front();
      Q.pop();
      del_vert(qtop);
    }

    ans.push_front(vertexc - delc);

    pair<int, int> uv = edges.back();
    edges.pop_back();
    if (!deleted[uv.first] && !deleted[uv.second]) {
      del_edge(uv.first, uv.second);
    }
  }

  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << '\n';
  }
}