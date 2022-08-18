#include <iostream>
#include <vector>

using namespace std;

#define u first
#define v second

const int MAX_N = 6e5 + 5;

vector<int> adj [MAX_N];
pair<int, int> edge [MAX_N];

int vis_v [MAX_N];
int vis_e [MAX_N];

void dfs (int u, vector<int> &cyc) {
  vis_v[u] = true;
  cyc.push_back(u);
  for (int e : adj[u]) {
    if (vis_e[e]) {
      continue;
    }

    vis_e[e] = true;
    auto ed = edge[e];
    int v = u ^ ed.u ^ ed.v;
    if (vis_v[v]) {
      cyc.push_back(v);
      cyc.push_back(u);
    } else {
      dfs(v, cyc);
      cyc.push_back(u);
    }
  }
}

int ans_gr [2][MAX_N];
char ans_a [2][MAX_N];
char ans_b [2][MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> edge[i].u >> edge[i].v;
    adj[edge[i].u].push_back(i);
    adj[edge[i].v].push_back(i);
  }

  vector<vector<int>> cycs;
  for (int i = 1; i <= 2 * n; i++) {
    if (vis_v[i] || adj[i].empty()) {
      continue;
    }

    vector<int> cyc;
    dfs(i, cyc);
    cyc.pop_back();
    if (cyc.size() == 2) {
      cout << -1 << '\n';
      return 0;
    }
    cycs.push_back(cyc);
  }

  int sta = 0;
  for (const auto &cyc : cycs) {
    int m = cyc.size() / 2;
    for (int i = 0; i < m; i++) {
      ans_gr[0][sta + i] = cyc[i];
    }
    
    for (int i = 0; i < m; i++) {
      ans_gr[1][sta + m - i - 1] = cyc[i + m];
    }

    if (m % 2 == 0) {
      for (int k = 0; k < 2; k++) {
        for (int i = 0; i < m; i++) {
          ans_a[k][sta + i] = (i % 2 ? 'R' : 'L');
        }
      }

      ans_b[0][sta] = 'U';
      ans_b[1][sta] = 'D';
      ans_b[0][sta + m - 1] = 'U';
      ans_b[1][sta + m - 1] = 'D';
      for (int k = 0; k < 2; k++) {
        for (int i = 1; i < m - 1; i++) {
          ans_b[k][sta + i] = (i % 2 ? 'L' : 'R');
        }
      }
    } else {
      ans_a[0][sta + m - 1] = 'U';
      ans_a[1][sta + m - 1] = 'D';
      ans_b[0][sta] = 'U';
      ans_b[1][sta] = 'D';
      for (int k = 0; k < 2; k++) {
        for (int i = 0; i < m - 1; i++) {
          ans_a[k][sta + i] = (i % 2 ? 'R' : 'L');
        }
      }

      for (int k = 0; k < 2; k++) {
        for (int i = 1; i < m; i++) {
          ans_b[k][sta + i] = (i % 2 ? 'L' : 'R');
        }
      }
    }
    
    sta += m;
  }

  cout << 2 << " " << n << '\n';
  cout << '\n';
  
  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < n; i++) {
      cout << ans_gr[k][i] << " ";
    }
    cout << '\n';
  }
  cout << '\n';

  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < n; i++) {
      cout << ans_a[k][i];
    }
    cout << '\n';
  }
  cout << '\n';

  for (int k = 0; k < 2; k++) {
    for (int i = 0; i < n; i++) {
      cout << ans_b[k][i];
    }
    cout << '\n';
  }
  cout << '\n';
}