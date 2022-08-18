#include <iostream>
#include <vector>
#include <map>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

const int MAX_N = 3e5 + 5;

vector<int> in [MAX_N];

int vc;
int add_vertex () {
  vc++;
  return vc - 1;
}

void add_edge (int u, int v) {
  in[v].push_back(u);
}

vector<int> topo;
int vis [MAX_N];
void dfs (int u) {
  vis[u] = 1;
  for (int prv : in[u]) {
    if (vis[prv] == 1) {
      failure();
    }

    if (vis[prv] == 0) {
      dfs(prv);
    }
  }

  topo.push_back(u);
  vis[u] = 2;
}

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vc = m;
  for (int i = 0; i < n; i++) {
    map<int, vector<int>> grp;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;

      if (x != -1) {
        grp[x].push_back(j);
      }
    }

    int last = -1;
    for (const auto &pr : grp) {
      if (last != -1) {
        for (int v : pr.second) {
          add_edge(last, v);
        }
      }

      last = add_vertex();
      for (int v : pr.second) {
        add_edge(v, last);
      }
    }
  }

  for (int i = 0; i < vc; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }

  for (auto u : topo) {
    if (u < m) {
      cout << 1 + u << " ";
    }
  }
  cout << '\n';
}