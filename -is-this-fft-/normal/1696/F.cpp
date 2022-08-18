#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
  vector<int> root;
  
public:
  DSU (int n = 0) {
    root = vector<int> (n);
    for (int i = 0; i < n; i++) {
      root[i] = i;
    }
  }

  int find (int u) {
    if (root[u] != u) {
      root[u] = find(root[u]);
    }
    return root[u];
  }

  void merge (int u, int v) {
    u = find(u);
    v = find(v);

    root[u] = v;
  }
};

const int MAX_N = 105;

bool eq [MAX_N][MAX_N][MAX_N];
int rep [MAX_N][MAX_N];

void dfs (int u, int p, const vector<vector<int>> &adj, vector<int> &dist) {
  if (u != p) {
    dist[u] = 1 + dist[p];
  }

  for (int nxt : adj[u]) {
    if (nxt != p)
      dfs(nxt, u, adj, dist);
  }
}

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      string s;
      cin >> s;

      for (int k = 0; k < n; k++) {
        eq[k][i][j] = s[k] == '1';
        eq[k][j][i] = eq[k][i][j];
      }
    }

    for (int k = 0; k < n; k++) {
      eq[k][i][i] = 1;
    }
  }

  // verify that eq[z] is an eq relation
  for (int z = 0; z < n; z++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (eq[z][i][j] && eq[z][j][k] && !eq[z][i][k]) {
            cout << "No" << '\n';
            return;
          }
        }
      }
    }
  }

  // it is. for each z form equivalence classes
  for (int z = 0; z < n; z++) {
    for (int i = 0; i < n; i++) {
      rep[z][i] = i;

      for (int j = 0; j < i; j++) {
        if (eq[z][i][j]) {
          rep[z][i] = j;
          break;
        }
      }
    }
  }

  DSU globds (n * n);
  for (int z = 0; z < n; z++) {
    for (int i = 0; i < n; i++) {
      globds.merge(z * n + rep[z][i], i * n + rep[i][z]);
    }
  }

  for (int z = 0; z < n; z++) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (!eq[z][i][j] &&
            globds.find(z * n + rep[z][i]) == globds.find(z * n + rep[z][j])) {
          cout << "NO" << '\n';
          return;
        }
      }
    }
  }

  // every pair <z, i> has one well-defined component
  // go over all components that are actually trees
  // and check if they work
  vector<vector<pair<int, int>>> comps (n * n);
  for (int z = 0; z < n; z++) {
    for (int i = z + 1; i < n; i++) {
      int c = globds.find(z * n + rep[z][i]);
      comps[c].push_back({z, i});
    }
  }

  for (const auto& comp : comps) {
    if ((int) comp.size() != n - 1) {
      continue;
    }

    // O(n) hits at this point
    bool fail = false;
    vector<int> seen (n, 0);
    for (auto e : comp) {
      if (e.first == e.second) {
        fail = true;
      }

      seen[e.first] = 1;
      seen[e.second] = 1;
    }

    for (int u : seen) {
      if (!u)
        fail = true;
    }

    if (fail)
      continue;

    // now it is an actual tree
    vector<vector<int>> adj (n, vector<int> (0));
    for (auto e : comp) {
      adj[e.first].push_back(e.second);
      adj[e.second].push_back(e.first);
    }

    for (int i = 0; i < n; i++) {
      vector<int> dist (n, 0);
      dfs(i, i, adj, dist);
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if ((dist[j] == dist[k]) != eq[i][j][k]) {
            fail = true;
            goto chkbrk;
          }
        }
      }
    }

  chkbrk:
    if (fail)
      continue;

    cout << "Yes" << '\n';
    for (auto e : comp) {
      cout << 1 + e.first << " " << 1 + e.second << '\n';
    }
    return;
  }

  cout << "nO" << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}