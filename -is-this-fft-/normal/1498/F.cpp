#include <iostream>
#include <vector>

using namespace std;

void merge (vector<int> &p, const vector<int> &q) {
  int n = p.size();
  for (int i = 1; i < n; i++){
    p[i] ^= q[i - 1];
  }
  p[0] ^= q[n - 1];
}

int calc_ans (const vector<int> &p) {
  int n = p.size();

  int ans = 0;
  for (int i = n / 2; i < n; i++) {
    ans ^= p[i];
  }
  return ans;
}

const int MAX_N = 1e5 + 5;

int arr [MAX_N];
vector<int> adj [MAX_N];

int K;
vector<int> dp [MAX_N];
vector<int> updp [MAX_N];

void calc_dp (int u, int p) {
  dp[u] = vector<int> (2 * K, 0);
  dp[u][0] = arr[u];
    
  for (int nxt : adj[u]) {
    if (nxt != p) {
      calc_dp(nxt, u);
      merge(dp[u], dp[nxt]);
    }
  }
}

int ans [MAX_N];
void calc_updp (int u, int p) {
  vector<int> cur (2 * K, 0);
  cur[0] = arr[u];
  
  merge(cur, updp[u]);
  for (int nxt : adj[u]) {
    if (nxt != p) {
      merge(cur, dp[nxt]);
    }
  }

  for (int nxt : adj[u]) {
    if (nxt != p) {
      merge(cur, dp[nxt]); // merge is its own inverse
      updp[nxt] = cur;
      merge(cur, dp[nxt]);
    }
  }

  ans[u] = calc_ans(cur);

  for (int nxt : adj[u]) {
    if (nxt != p) {
      calc_updp(nxt, u);
    }
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n >> K;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  
  calc_dp(1, 0);
  updp[1] = vector<int> (2 * K, 0);
  calc_updp(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << (ans[i] != 0) << " ";
  }
  cout << '\n';
}