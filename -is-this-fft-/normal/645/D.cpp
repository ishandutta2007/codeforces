#include <iostream>
#include <vector>
#include <map>

const int MAX_V = 100005;

using namespace std;

bool vis [MAX_V];
vector<int> adj [MAX_V];
vector<int> topsort;

void dfs (int vertex) {
  if (!vis[vertex]) {
    vis[vertex] = true;
    for (int i = 0; i < adj[vertex].size(); i++) {
      dfs(adj[vertex][i]);
    }
    topsort.push_back(vertex);
  }
}

int main () {
  int robotc, battlec;
  cin >> robotc >> battlec;

  map<pair<int, int>, int> conn;
  for (int i = 1; i <= battlec; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    conn[make_pair(u, v)] = i;
    conn[make_pair(v, u)] = i;
  }

  for (int i = 1; i <= robotc; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }

  int ans = 0;
  for (int i = 0; i + 1 < topsort.size(); i++) {
    if (conn.find(make_pair(topsort[i], topsort[i + 1])) == conn.end()) {
      cout << "-1" << endl;
      return 0;
    } else {
      ans = max(ans, conn[make_pair(topsort[i], topsort[i + 1])]);
    }
  }
  cout << ans << endl;
}