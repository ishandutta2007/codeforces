#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <complex>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define FOR(i, a, b) for(int i(a), _b(b); i < _b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i(a), _b(b); i >= _b; --i)
#define CL(a, v) memset(a, v, sizeof a)
#define UNIQUE(a) sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1000000000;
const ll INFLL = 1000000000000000000LL;

const int mod = 1000000007;

int mul(int a, int b) { return ll(a)*b % mod; }
int add(int a, int b) { a+=b; if(a>=mod) a-=mod; return a; }

int qpow(int a, int p) {
  int res = 1;
  while(p) {
    if(p&1) res = mul(res, a);
    a = mul(a, a);
    p>>=1;
  }
  return res;
}

int inv(int a) { return qpow(a, mod-2); }

const int h = 1000011, N=1011;
int f[h], invf[h], dp[N][N], p[N];

int C(int n, int k) {
  if(k>n || k<0) return 0;
  return mul(f[n], inv(mul(f[k], f[n-k])));
}

int C(int n, int k1, int k2, int k3) {
  if(k1+k2+k3>n) return 0;
  return mul(f[n], mul(mul(invf[k1], invf[k2]), mul(invf[k3], invf[n-k1-k2-k3])));
}

int A(int n, int k) {
  if(k>n || k<0) return 0;
  return mul(f[n], inv(f[n-k]));
}

int n,m, k, res=0;

int main () {
#ifdef LocalHost
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
  //REP(i, 10) { REP(j, 10) printf("%d ", dp[i][j]); printf("\n"); }
  scanf("%d%d%d", &n, &m, &k);
  f[0] = 1;
  REP(i, k) f[i+1] = mul(f[i], i+1);
  REP(i, k+1) if(i<=2*N || i+3*N>=k) invf[i] = inv(f[i]);

  dp[0][0] = 1;
  FOR(i, 1, n+1) FOR(j, 1, i+1)
    dp[i][j] = add(dp[i-1][j-1], mul(j, dp[i-1][j]));
//  REP(i, n+1) REP(j, i+1) dp[n][i] = mul(dp[n][i], f[i]);

  if(m==1) {
    printf("%d\n", qpow(k, n));
    return 0;
  }

  REP(j, N) p[j] = qpow(j, n*(m-2));

  FOR(i, 1, min(n, k)+1) REP(j, i+1) if(2*i-j<=k) {
    //printf("%d, %d: %d %d\n", i, j, A(k, 2*i-j), dp[n][i]);
    res = add(res, mul(mul(C(k, j, i-j, i-j), p[j]), qpow(mul(f[i], dp[n][i]), 2)));
  }
  printf("%d\n", res);
#ifdef LocalHost
  cout << endl << "Time: " << clock() << endl;
#endif
  return 0;
}