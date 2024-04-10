#include <iostream>
#include <vector>

using namespace std;

const int MAX_LG = 12;

class Tree {
  vector<vector<int>> adj;
  vector<vector<int>> jmp;
  vector<int> lvl;

  void build (int u, int par) {
    lvl[u] = lvl[par] + 1;
    jmp[u][0] = par;
    for (int i = 1; i < MAX_LG; i++) {
      jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];
    }

    for (int nxt : adj[u]) {
      if (nxt != par) {
        build(nxt, u);
      }
    }
  }

public:
  Tree (int _vertexc) {
    adj = vector<vector<int>> (_vertexc, vector<int> (0));
    jmp = vector<vector<int>> (_vertexc, vector<int> (MAX_LG));
    lvl = vector<int> (_vertexc, 0);
  }
  
  void add_edge (int p, int u) {
    adj[p].push_back(u);
    adj[u].push_back(p);
  }

  void init () {
    build(1, 1);
  }

  int lca (int u, int v) {
    if (lvl[u] < lvl[v]) {
      swap(u, v);
    }

    int diff = lvl[u] - lvl[v];
    for (int i = 0; i < MAX_LG; i++) {
      if (diff & 1 << i) {
        u = jmp[u][i];
      }
    }

    if (u == v) return u;
    for (int i = MAX_LG - 1; i >= 0; i--) {
      if (jmp[u][i] != jmp[v][i]) {
        u = jmp[u][i];
        v = jmp[v][i];
      }
    }

    return jmp[u][0];
  }

  int cost (int last, int cur) {
    if (last == -1) {
      return lvl[cur] - 1;
    } else {
      return lvl[cur] - lvl[lca(last, cur)];
    }
  }
};

const int MAX_N = 1e3 + 5;

int topid [MAX_N];
int botid [MAX_N];
int dp [MAX_N][MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int devc;
  cin >> devc;

  int topvc;
  cin >> topvc;
  Tree topt (topvc + 5);
  for (int i = 2; i <= topvc; i++) {
    int p;
    cin >> p;
    topt.add_edge(p, i);
  }
  topt.init();
  
  topid[0] = -1;
  for (int i = 1; i <= devc; i++) {
    cin >> topid[i];
  }

  int botvc;
  cin >> botvc;
  Tree bott (botvc + 5);
  for (int i = 2; i <= botvc; i++) {
    int p;
    cin >> p;
    bott.add_edge(p, i);
  }
  bott.init();
  
  botid[0] = -1;
  for (int i = 1; i <= devc; i++) {
    cin >> botid[i];
  }

  dp[0][0] = 0;
  for (int i = 1; i <= devc; i++) {
    dp[i][0] = dp[i - 1][0] + topt.cost(topid[i - 1], topid[i]);
    dp[0][i] = dp[0][i - 1] + bott.cost(botid[i - 1], botid[i]);
  }

  int ans = 5000;
  for (int mx = 1; mx <= devc; mx++) {
    if (1) {
      int i = mx;
      for (int j = 1; j < mx; j++) {
        if (i - 1 > j) {
          dp[i][j] = dp[i - 1][j] + topt.cost(topid[i - 1], topid[i]);
        } else {
          dp[i][j] = 5000;
          for (int u = 0; u < j; u++) {
            dp[i][j] = min(dp[i][j], dp[u][j] + topt.cost(topid[u], topid[i]));
          }
        }
        
        // cout << i << " " << j << " " << dp[i][j] << endl;
        if (mx == devc) {
          ans = min(ans, dp[i][j]);
        }
      }
    }

    if (1) {
      int j = mx;
      for (int i = 1; i < mx; i++) {
        if (j - 1 > i) {
          dp[i][j] = dp[i][j - 1] + bott.cost(botid[j - 1], botid[j]);
        } else {
          dp[i][j] = 5000;
          for (int u = 0; u < i; u++) {
            dp[i][j] = min(dp[i][j], dp[i][u] + bott.cost(botid[u], botid[j]));
          }
        }

        //  cout << i << " " << j << " " << dp[i][j] << endl;
        if (mx == devc) {
          ans = min(ans, dp[i][j]);
        }
      }
    }
  }

  ans = min(ans, dp[0][devc]);
  ans = min(ans, dp[devc][0]);
  
  // cout << topt.cost(topid[2], topid[3]) << endl;
  cout << topvc + botvc - 2 - ans << endl;
}