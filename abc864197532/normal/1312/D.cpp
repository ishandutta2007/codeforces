#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
#define endl '\n'
const int mod = 998244353;

lli modpow(lli a, int b) {
  if (b < 0) return 0;
  lli ans = 1;
  for (; b; b >>= 1, a = a * a % mod) {
    if (b & 1) ans = ans * a % mod;
  }
  return ans;
}

int main () {
  int n, m;
  cin >> n >> m;
  lli frac[200087];
  frac[0] = 1;
  fop (i,1,200087) frac[i] = frac[i - 1] * i % mod;
  lli ans = frac[m] * modpow(frac[n - 1], mod - 2) % mod * modpow(frac[m - n + 1], mod - 2) % mod;
  ans = ans * (n - 2) % mod;
  cout << ans * modpow(2, n - 3) % mod << endl;
}