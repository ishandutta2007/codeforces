#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 998244353;
const int maxn = 2050;
vector<int> candidate;

bool valid(vector<int>& c, int n, int k) {
  if (accumulate(c.begin(), c.end(), 0LL) > n) return 0;
  if (k == 1) return 1;
  vector<int> q;
  int i = 1;
  for (auto it = c.rbegin(); it < c.rend(); it++) {
    for (int j = 0; j < *it; j++) q.push_back(i);
    i++;
  }
  return valid(q, n, k-1);
}

int dfs(int n, int k) {
  if (!valid(candidate, n, k)) return 0;
  /*
  for (int i: a) cout << i << ' ';
  cout << endl;
  */
  int ans = 1;
  int start = 1;
  if (candidate.size()) start = candidate.back();
  for (int i = start; i < maxn; i++) {
    candidate.push_back(i);
    int u = dfs(n, k);
    candidate.pop_back();
    if (!u) break;
    ans += u;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    // p(1)+p(2)+...+p(n)
    vector<ll> p(maxn);
    p[0] = 1;
    for (int k = 1; k < maxn; k++) {
      for (int i = 0; i + k < maxn; i++) {
        p[i+k] = (p[i]+p[i+k]) % MOD;
      }
    }
    cout << accumulate(p.begin()+1, p.begin()+n+1, 0LL) % MOD << endl;
    return 0;
  }
  else if (k == 2) {
    // {x_i} with x_1 >= x_2 >= ... >= x_m is possible iff
    // x_1+2x_2+...+mx_m <= n
    // fix k, then (m+1 choose 2)d_k + (m choose 2)d_{m-1} +... + (2 choose 2)d_1 <= n where d_m > 0
    ll ans = 0;
    for (int m = 1; m < maxn; m++) {
      int u = (m*(m+1))/2;
      vector<ll> dp(maxn);
      for (int i = u; i < maxn; i+=u) dp[i]++;
      for (int j = m; j >= 2; j--) {
        int v = (j*(j-1))/2;
        for (int i = 0; i+v < maxn; i++) {
          dp[i+v] = (dp[i]+dp[i+v]) % MOD;
        }
      }
      ll x = accumulate(dp.begin(), dp.begin()+n+1, 0LL);
      if (!x) break;
      ans += x;
      ans %= MOD;
    }
    cout << ans << endl;
    return 0;
  }
  else {
    cout << dfs(n, k)-1 << endl;
  }
}