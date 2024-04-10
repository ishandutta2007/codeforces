#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 2005;

int sct[N];
// probability of strongly connected tournaments if n players
int dp[N];

int powq[N*N], powp[N*N];
int qC[N][N];

int add(int x, int y) {
  x += y;
  return (x >= MOD ? x-MOD : x);
}

int sub(int x, int y) {
  x -= y;
  return (x < 0 ? x+MOD : x);
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
  int n, a, b;
  cin >> n >> a >> b;
  int q = 1LL*a*inversemod(b-a, MOD) % MOD;
  int p = 1LL*(b-a)*inversemod(b, MOD) % MOD;
  powq[0] = 1;
  powp[0] = 1;
  for (int i = 1; i < N*N; i++) {
    powq[i] = 1LL*q*powq[i-1] % MOD;
    powp[i] = 1LL*p*powp[i-1] % MOD;
  }

  for (int i = 0; i < N; i++) {
    qC[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      qC[i][j] = (1LL*powq[j]*qC[i-1][j] + qC[i-1][j-1]) % MOD;
    }
  }
  
  for (int i = 1; i < N; i++) {
    dp[i] = i*(i-1)/2;
    sct[i] = 1;
    for (int j = 1; j < i; j++) {
      // the top component has j people
      int prob = qC[i][j]*(1LL*sct[j]*powp[j*(i-j)] % MOD) % MOD;
      int contrib = add(dp[j], dp[i-j]-(i-j)*(i-j-1)/2);
      if (contrib < 0) contrib += MOD;
      sct[i] = sub(sct[i], prob);
      dp[i] = add(dp[i], 1LL*prob*contrib % MOD);
    }
    if (i != 1) {
      dp[i] = 1LL*inversemod(MOD+1-sct[i], MOD)*dp[i] % MOD;
    }
  }
  cout << dp[n] << '\n';
}