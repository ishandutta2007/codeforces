#include <bits/stdc++.h>
using namespace std;

// based on https://codeforces.com/contest/1474/submission/149248060
const int MOD = 998244353;
const int N = 52;
int inv[N];

using state = pair<long long, long long>;
// first: length of longest increasing subsequence ending here
// second: number of such sequences

int add(int x, int y) {
  x += y;
  return (x >= MOD ? x-MOD : x);
}

state operator + (state a, state b) {
  if (a.first != b.first) return max(a, b);
  return make_pair(a.first, add(a.second, b.second));
}

int binom(int x, int y) {
  int ans = 1;
  for (int i = 1; i <= y; i++) {
    ans = 1LL*(x+1-i)*ans % MOD;
    ans = 1LL*inv[i]*ans % MOD;
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }
  int n, _x;
  cin >> n >> _x;
  vector<long long> a(n+1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i+1] = a[i]+x;
  }
  vector<long long> c = a;
  sort(c.begin(), c.end());
  c.resize(unique(c.begin(), c.end())-c.begin());
  auto compress = [&] (long long x) {
    return lower_bound(c.begin(), c.end(), x)-c.begin();
  };
  
  vector<vector<int>> t((int)c.size()-1, vector<int>(N));
  for (int i = 0; i < (int)c.size()-1; i++) {
    int d = c[i+1]-c[i];
    for (int j = 0; j < N; j++) {
      // Given the sequence 0, 1, ..., d, d-1, ..., 0, ..., d with z descents and
      // z+1 ascents, how many longest increasing subsequences start on the first
      // term and end on the last?
      //
      // This is a_1+b_1+...+b_z+a_{z+1} = d-1 with 0 <= b_i <= 1.
      // Sum over k, the number of b_i equal to 1.
      for (int k = 0; k <= min(j, d-1); k++) {
        t[i][j] = add(t[i][j], 1LL*binom(j, k)*binom(d-1-k+j, j)%MOD);
      }
    }
  }

  vector<int> b(1, compress(a[0]));
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[i-1]) {
      for (int j = compress(a[i-1])+1; j <= compress(a[i]); j++) {
        b.push_back(j);
      }
    }
    else {
      for (int j = compress(a[i-1])-1; j >= compress(a[i]); j--) {
        b.push_back(j);
      }
    }
  }

  int m = b.size();
  vector<state> dp(m, make_pair(1, 1));
  for (int i = 1; i < m; i++) {
    // seek a transition from b[i]-1
    int descents = 0;
    for (int j = i-1; j >= 0; j--) {
      if (b[j] == b[i] && b[j+1] == b[i]-1) descents++;
      if (b[j] == b[i]-1) {
        dp[i] = dp[i] +
          make_pair(dp[j].first+c[b[i]]-c[b[j]],
              1LL*t[b[j]][descents]*dp[j].second % MOD);
      }
    }
  }
  state ans = make_pair(0, 0);
  for (state& s: dp) {
    ans = ans+s;
  }
  if (ans.first == 1) ans.second = (1-a[n])%MOD;
  cout << ans.first << " " << ans.second << '\n';
}