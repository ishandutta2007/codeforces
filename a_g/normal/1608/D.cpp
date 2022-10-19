#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6;
int fact[maxn];
int invfact[maxn];

const int MOD = 998244353;

ll inversemod(ll p, ll q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  ll k = q/p;
  ll b = inversemod(q-k*p, p);
  ll a = (1-b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (1LL*invfact[k]*invfact[n-k] % MOD) % MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[maxn-1] = inversemod(fact[maxn-1], MOD);
  for (int i = maxn-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }

  int n;
  cin >> n;
  vector<string> d(n);

  int e = 0;
  int k = 0;
  // count configurations where WW = BB
  for (int i = 0 ; i < n; i++) {
    string s;
    cin >> s;
    d[i] = s;
    int w = 0;
    int b = 0;
    for (char c: s) {
      if (c == '?') e++;
      if (c == 'W') w++;
      if (c == 'B') b++;
    }
    if (b == 2) k++;
    if (w == 2) k--;
    if (w == 0 && b <= 1) k++;
  }
  int ans = binommod(e, k);
  // subtract configurations where only WB or BW, add configurations where all
  // WB or all BW
  int wb = 1;
  int bw = 1;
  int bad = 1;
  for (int i = 0; i < n; i++) {
    string s = d[i];
    if (s[0] == 'B' || s[1] == 'W') wb = 0;
    if (s[0] == 'W' || s[1] == 'B') bw = 0;
    if (s[0] == s[1] && s[0] != '?') bad = 0;
    if (s[0] == s[1] && s[0] == '?') bad = 2*bad % MOD;
  }
  ans -= (bad-wb-bw);
  ans %= MOD;
  cout << (ans+MOD)%MOD << endl;
}