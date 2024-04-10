#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 1e18 + 200;
const int MAX_N = 2e5 + 5;

struct TwoBest {
  pair<ll, int> top;
  pair<ll, int> stop;
  
  TwoBest () : top(0, 0), stop(0, 0) {}

  void add (pair<ll, int> pr) {
    if (pr > top) {
      stop = top;
      top = pr;
    } else if (pr > stop) {
      stop = pr;
    }
  }
  
  void add (ll u, int v) {
    add(make_pair(u, v));
  }
  
  ll max_not (int u) {
    if (top.second == u) return stop.first;
    return top.first;
  }
};

vector<int> adj [MAX_N];
ll H [MAX_N];

ll dp [MAX_N];
ll sdp [MAX_N];

TwoBest smx [MAX_N];
ll mx [MAX_N];

void calc_dp (int u, int p) {
  for (int nxt : adj[u]) {
    if (nxt != p) {
      calc_dp(nxt, u);
    }
  }

  for (int nxt : adj[u]) {
    if (nxt != p) {
      sdp[u] += dp[nxt];
      smx[u].add(mx[nxt], nxt);
    }
  }

  mx[u] = max(H[u], smx[u].max_not(-1));
  dp[u] = sdp[u] + mx[u] - smx[u].max_not(-1);
}

ll updp [MAX_N];
ll upmx [MAX_N];

void calc_updp (int u, int p) {
  // we store at updp[p]

  ll upsdp = sdp[u] + updp[u] - dp[p];
  upmx[p] = max(H[u], max(upmx[u], smx[u].max_not(p)));
  updp[p] = upsdp + upmx[p] - max(upmx[u], smx[u].max_not(p));
}

void updp_dfs (int u, int p) {
  for (int nxt : adj[u]) {
    if (nxt != p) {
      calc_updp(u, nxt);
    }
  }

  for (int nxt : adj[u]) {
    if (nxt != p) {
      updp_dfs(nxt, u);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> H[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (n == 2) {
    cout << 2 * max(H[1], H[2]) << '\n';
    return 0;
  }

  int root = -1;
  for (int i = 1; i <= n; i++) {
    if ((int) adj[i].size() != 1) {
      root = i;
      break;
    }
  }

  calc_dp(root, 0);
  updp_dfs(root, 0);

  ll ans = INF, maxh = 0;
  for (int i = 1; i <= n; i++) {
    if ((int) adj[i].size() == 1) {
      ll cur = updp[i];
      cur += max(0LL, H[i] - upmx[i]);
      ans = min(ans, cur);
    }
    maxh = max(maxh, H[i]);
  }

  cout << ans + maxh << '\n';
}