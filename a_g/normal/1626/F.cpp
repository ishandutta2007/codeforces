#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+2;
const int MOD = 998244353;
const int K = 17;
const int L = 720720; // lcm(1, ..., 17)
int a[N];
int dp[2][L];
int pown[K+1];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, x, y, k, M;
  cin >> n >> a[0] >> x >> y >> k >> M;

  for (int i = 1; i < n; i++) {
    a[i] = (1LL*a[i-1]*x+y) % M;
  }
  pown[0] = 1;
  for (int i = 1; i <= K; i++) {
    pown[i] = 1LL*n*pown[i-1] % MOD;
  }

  for (int i = 1; i <= L; i++) {
    dp[0][i] = i % MOD;
  }
  for (int j = k-1; j >= 1; j--) {
    int z = (k-j)&1;
    for (int i = 0; i < L; i++) {
      dp[z][i] = (1LL*pown[k-j]*i + dp[1-z][i-i%j] + 1LL*(n-1)*dp[1-z][i]) % MOD;
    }
  }

  int ans = 0;
  int base = 1LL * L * (1LL * k * pown[k-1] % MOD) % MOD;
  int z = (k-1)&1;
  for (int i = 0; i < n; i++) {
    ans += 1LL * base * (a[i]/L) % MOD;
    ans %= MOD;
    ans += dp[z][a[i]%L];
    ans %= MOD;
  }
  cout << ans << '\n';
}