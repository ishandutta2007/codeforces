#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1005;
int dp[N][N], expp[N];
// (# of 'a', # of 'ab')

void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int k, pa, pb;
  cin >> k >> pa >> pb;
  int q = 1LL*pb*inversemod(pa+pb, MOD) % MOD;
  int p = 1LL*pa*inversemod(pa+pb, MOD) % MOD;
  int qinv = inversemod(q, MOD);
  expp[0] = 1;
  for (int i = 1; i < N; i++) {
    expp[i] = 1LL*expp[i-1]*p % MOD;
  }

  int ans = 0;
  dp[1][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (dp[i][j]) {
        int z = 0;
        for (; j+i+z < k; z++) {
          // 'a'*z + 'b'
          add(dp[i+z][j+i+z], dp[i][j]*(1LL*q*expp[z] % MOD) % MOD);
        }
        // p^z*q*(j+i+z)+p^{z+1}*q*(j+i+z+1)+...
        int term = MOD-1;
        for (int x: {expp[z], int((1LL*p*z-p-z)%MOD), qinv}) {
          term = 1LL*term*x % MOD;
        }
        if (term < 0) term += MOD;
        add(term, 1LL*(i+j)*expp[z] % MOD);
        term = 1LL*dp[i][j]*term % MOD;
        add(ans, term);
      }
    }
  }
  assert(ans >= 0 && ans < MOD);
  cout << ans << '\n';
}