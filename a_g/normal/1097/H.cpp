#include <bits/stdc++.h>
using namespace std;

int d, m, n;
vector<int> gen;
map<long long, vector<long long>> dp;

int f(long long x) {
  int ans = 0;
  while (x) {
    ans += gen[x%d];
    x /= d;
  }
  return ans%m;
}

void calc(long long r) {
  if (dp.count(r)) return;
  dp[r] = vector<long long>(m, 0);
  calc(r/d);
  for (int v = 0; v < m; v++) {
    for (int k = 0; k < d; k++) {
      dp[r][(v+gen[k])%m] += dp[r/d][v];
    }
  }
  int v = f(r/d);
  for (int k = 0; k < r%d; k++) {
    dp[r][(v+gen[k])%m]++;
  }
}

long long shift(long long mask, int k) {
  return ((mask>>k)|((mask&((1LL<<k)-1))<<(m-k)));
}

long long solve(long long r, vector<long long> b) {
  // for how many x < r is f(x+i) in B_i for 0 <= i < n
  while (b.size() && b.back() == (1LL<<m)-1) b.pop_back();
  int n = (int)b.size();
  if (n == 0 || r == 0) return r;
  if (*min_element(b.begin(), b.end()) == 0) return 0;
  long long ans = 0;
  if (n == 1) {
    calc(r);
    for (int i = 0; i < m; i++) {
      if (b[0]&(1LL<<i)) ans += dp[r][i];
    }
    return ans;
  }
  for (int k = 0; k < d; k++) {
    vector<long long> new_b((k+n-1)/d+1, (1LL<<m)-1);
    for (int i = 0; i < n; i++) {
      new_b[(k+i)/d] &= shift(b[i], gen[(k+i)%d]);
    }
    ans += solve((r-k+d-1)/d, new_b);
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> d >> m;
  gen.resize(d);
  for (int& x: gen) cin >> x;
  cin >> n;
  vector<long long> b(n);
  for (long long& x: b) {
    int k;
    cin >> k;
    x = (1LL<<(k+1))-1;
  }
  int z = 0;
  while (z < n && b[z] == (1LL<<m)-1) z++;
  for (int i = 0; i+z < n; i++) {
    b[i] = b[i+z];
  }
  b.resize(n-z);
  long long l, r;
  cin >> l >> r;
  l += z, r += z;
  cout << solve(r-n+1, b)-solve(l-1, b) << '\n';
}