#include <bits/stdc++.h>
using namespace std;

/*  Call a vertex "cool" if every vertex is friends with it.
 *
 *  1) There is a cool vertex. (While u is not cool, find v which is not
 *  friends with u and replace u by the mutual friend.)
 * 
 *  2) The cool vertices form a path, with binary trees hanging off the ends.
 *  (Special case: there is one cool vertex and only one side, but that one
 *  side has 3 children at the root.)
 *
 *  How to count? Root at the topmost cool vertex. We attach two binary trees
 *  above and below. The one above should not have one child at the root, and
 *  they cannot both have two children at the root.
 */

const int N = 1e6+2;
const int MOD = 998244353;
int dp[N][3];
// dp[i][0] = number of binary trees with depth at most i (empty counts)
// dp[i][1] = number of binary trees with depth equal to i
// dp[i][2] = number of binary trees with depth equal to i and 2 children at the root

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

const int sixth = inversemod(6, MOD);

int g(int d) {
  // how many nonempty unlabeled binary trees of depth at most d but root has 3 children
  if (d == 0) return 1;
  int k = dp[d-1][0]-1; // no nonempty allowed
  int ans = 1LL*k*k % MOD; // either 1 or 2 distinct children
  ans += ((1LL*k*(k-1)) % MOD) * (1LL*sixth*(k-2) % MOD) % MOD; // 3 distinct children
  return ans % MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  dp[0][0] = 2;
  dp[0][1] = 1;
  for (int i = 1; i < N; i++) {
    dp[i][0] = 1+(1LL*dp[i-1][0]*(dp[i-1][0]+1))/2 % MOD;
    dp[i][1] = (dp[i][0]-dp[i-1][0]) % MOD;
    dp[i][2] = (dp[i][1]-dp[i-1][1]) % MOD;
  }

  int n;
  cin >> n;
  if (n == 1) {
    cout << "5\n";
    return 0;
  }
  int ans = 2LL*(g(n)-g(n-1)) % MOD;
  for (int d = 0; d <= n; d++) {
    // up: d levels
    // down: n-d levels
    ans += 1LL * (d ? dp[d][2] : 1) * (dp[n-d][1])  % MOD;
    ans %= MOD;
    ans -= 1LL * dp[d][2] * dp[n-d][2] % MOD;
    ans %= MOD;
  }
  cout << (ans+MOD)%MOD << '\n';
}