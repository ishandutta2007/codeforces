#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 305;
const int maxt = 1e5+7;
int a[maxn];
int out_edge[maxn];
int in_edge[maxn];
int adjusted_val[maxn];
bool has_loop = 0;
ll t;
int dp[maxt];
const int MOD = 1000000007;

void compute(int i) {
  int source = i;
  set<int> visited;
  visited.insert(source);
  while (out_edge[i]) {
    i = out_edge[i];
    if (visited.count(i)) {
      has_loop = 1;
      return;
    }
    visited.insert(i);
  }
  for (int j: visited) {
    adjusted_val[source] += a[j];
  }
  if (in_edge[source]) {
    t -= adjusted_val[source];
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q >> t;
  for (int i = 1; i <= n; i++) cin >> a[i];
  while (q--) {
    int b, c;
    cin >> b >> c;
    out_edge[c] = b;
    in_edge[b] = c;
  }
  for (int i = 1; i <= n; i++) compute(i);
  if (has_loop || t < 0) {
    cout << 0 << endl;
    return 0;
  }
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    // multiply by 1/(1-x^k)
    int k = adjusted_val[i];
    assert(k);
    for (int j = k; j < maxt; j++) {
      dp[j] += dp[j-k];
      dp[j] %= MOD;
    }
  }
  cout << dp[t] << endl;
}