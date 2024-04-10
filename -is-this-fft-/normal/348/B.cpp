#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll appsum;
void failure () {
  cout << appsum << endl;
  exit(0);
}

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

ll chmul (ll p, ll q) {
  ll ans;
  bool fail = __builtin_mul_overflow(p, q, &ans);
  if (fail) failure();
  return ans;
}

ll lcm (ll p, ll q) {
  return chmul(p / gcd(p, q), q);
}

const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];

ll arr [MAX_N];
ll dv [MAX_N];
ll dp [MAX_N];

void dfs (int u, int p) {
  int chc = 0;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      chc++;
      dfs(nxt, u);
    }
  }

  if (chc == 0) { // leaf
    dp[u] = arr[u];
    dv[u] = 1;
    return;
  }

  dv[u] = 1;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      dv[u] = lcm(dv[u], dv[nxt]);
    }
  }

  // all children must divide dv[u] now
  dp[u] = appsum;
  for (int nxt : adj[u]) {
    if (nxt != p) {
      dp[u] = min(dp[u], dp[nxt] - dp[nxt] % dv[u]);
    }
  }

  dp[u] *= (ll) chc;
  dv[u] = chmul(dv[u], chc);
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    appsum += arr[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0);

  cout << appsum - dp[1] << endl;
}