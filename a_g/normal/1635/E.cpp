#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
bool visited[N];
bool ori[N]; // 0 = left
int pos[N];

vector<int> adj[N];
vector<int> adj2[N][2];
//vector<int> in_edges[N];
vector<int> out_edges[N];
int indeg[N];

void dfs1(int v) {
  visited[v] = 1;
  for (int u: adj[v]) {
    if (visited[u]) {
      if (ori[u] == ori[v]) {
        cout << "NO\n";
        exit(0);
      }
    }
    else {
      ori[u] = 1-ori[v];
      dfs1(u);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int type, a, b;
    cin >> type >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    adj2[a][type-1].push_back(b);
    adj2[b][type-1].push_back(a);
  }

  // check bipartite
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs1(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j: adj2[i][ori[i]]) {
      out_edges[i].push_back(j);
      //in_edges[j].push_back(i);
      indeg[j]++;
    }
  }
  //fill(visited, visited+N, 0);

  vector<int> que;
  for (int i = 1; i <= n; i++) {
    if (!indeg[i]) que.push_back(i);
  }
  int timer = 0;
  for (int i = 0; i < que.size(); i++) {
    pos[que[i]] = timer++;
    for (int j: out_edges[que[i]]) {
      indeg[j]--;
      if (!indeg[j]) {
        que.push_back(j);
      }
    }
  }

  if (que.size() < n) {
    cout << "NO\n";
    return 0;
  }
  
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << (ori[i] ? "R " : "L ") << pos[i] << '\n';
  }
}