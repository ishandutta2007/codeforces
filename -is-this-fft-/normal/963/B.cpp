#include <iostream>
#include <vector>

using namespace std;

void failure () {
  cout << "NO" << endl;
  exit(0);
}

const int MAX_N = 2e5 + 5;

int par [MAX_N];
vector<int> adj [MAX_N];

// can we do it such that the edge u->p[u] is 0 - in; 1 - out
int dp [MAX_N][2];
void calc_dp (int u) {
  for (int nxt : adj[u]) {
    calc_dp(nxt);
  }

  int in_only = 0, both = 0;
  for (int nxt : adj[u]) {
    if (dp[nxt][0] == 1) {
      if (dp[nxt][1] == 1) {
        both++;
      } else {
        in_only++;
      }
    }
  }

  if (in_only % 2 == 0) {
    dp[u][0] = 1;
  } else if (both > 0) {
    dp[u][0] = 1;
  }

  if (in_only % 2 == 1) {
    dp[u][1] = 1;
  } else if (both > 0) {
    dp[u][1] = 1;
  }

  if (!dp[u][0] && !dp[u][1]) failure();
}

vector<int> ins [MAX_N];

void add_edge (int u, int v) {
  ins[v].push_back(u);
}

void rebuild (int u, int sgn) {
  if (par[u] != 0) {
    if (sgn == 0) add_edge(par[u], u);
    else add_edge(u, par[u]);
  }

  int both = -1;
  int in_only = 0;
  for (int nxt : adj[u]) {
    if (dp[nxt][0] == 1) {
      if (dp[nxt][1] == 1) {
        both = nxt;
      } else {
        in_only++;
      }
    }
  }

  int use_both = 0;
  if (sgn == 0 && in_only % 2 == 1) use_both = 1;
  if (sgn == 1 && in_only % 2 == 0) use_both = 1;

  for (int nxt : adj[u]) {
    if (nxt == both && use_both) {
      rebuild(nxt, 0);
    } else if (dp[nxt][0] == 1 && dp[nxt][1] == 0) {
      rebuild(nxt, 0);
    } else {
      rebuild(nxt, 1);
    }
  }
}

int vis [MAX_N];
void topo (int u) {
  for (int nxt : ins[u]) {
    if (!vis[nxt]) {
      topo(nxt);
    }
  }

  cout << u << '\n';
  vis[u] = 1;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> par[i];
    adj[par[i]].push_back(i);
  }

  int root = adj[0][0];
  calc_dp(root);

  if (!dp[root][0]) failure();
  rebuild(root, 0);

  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      topo(i);
    }
  }
}