// RESUBMIT: I discovered I had already solved this
// so during the virtual contest I simply waited the
// number of minutes it had once taken minutes

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;
const ll INF = 1e18 + 5;

vector<pair<int, ll>> adj [MAX_N];

pair<ll, int> naive_farthest (int u, int par) {
  pair<ll, int> ans = make_pair(0, u);
  for (auto nxt : adj[u]) {
    if (nxt.first != par) {
      pair<ll, int> pr = naive_farthest(nxt.first, u);
      pr.first += nxt.second;
      ans = max(ans, pr);
    }
  }
  return ans;
}

ll val [MAX_N];
void populate_val (int u, int par, ll cur) {
  val[u] = max(val[u], cur);
  for (auto nxt : adj[u]) {
    if (nxt.first != par) {
      populate_val(nxt.first, u, cur + nxt.second);
    }
  }
}

const int MAX_LG = 18;
int jmp [MAX_N][MAX_LG];

void build (int u, int par) {
  jmp[u][0] = par;
  for (int i = 1; i < MAX_LG; i++) {
    jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];
  }

  for (auto nxt : adj[u]) {
    if (nxt.first != par) {
      build(nxt.first, u);
    }
  }
}

int add [MAX_N];
void solve_dfs (int u, int par, ll l, int &ans) {
  int w = u;
  for (int i = MAX_LG - 1; i >= 0; i--) {
    if (val[u] - val[jmp[w][i]] <= l) {
      w = jmp[w][i];
    }
  }

  add[u] = 1;
  if (jmp[w][0] != w) {
    add[jmp[w][0]]--;
  }

  for (auto nxt : adj[u]) {
    if (nxt.first != par) {
      solve_dfs(nxt.first, u, l, ans);
      add[u] += add[nxt.first];
    }
  }

  ans = max(ans, add[u]);
}

int main () {
  ios::sync_with_stdio(false);

  int vertexc;
  cin >> vertexc;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  int far1 = naive_farthest(1, 1).second;
  int far2 = naive_farthest(far1, far1).second;

  populate_val(far1, far1, 0);
  populate_val(far2, far2, 0);

  pair<ll, int> rootpr = {INF, -1};
  for (int i = 1; i <= vertexc; i++) {
    rootpr = min(rootpr, {val[i], i});
  }

  int root = rootpr.second;
  build(root, root);

  int queryc;
  cin >> queryc;
  for (int t = 0; t < queryc; t++) {
    ll l;
    cin >> l;
    int ans = 0;
    solve_dfs(root, root, l, ans);
    cout << ans << '\n';
  }
}