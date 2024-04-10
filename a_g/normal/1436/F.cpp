#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
const int MOD = 998244353;
ll s0[N];
int s1[N];
int s2[N];
int S[N];

int expmod(ll a, ll b, int m) {
  int res = 1;
  a = a % m; 
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = (a*a) % m;
  }
  return res;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int m;
  cin >> m;
  while (m--) {
    int a, f;
    cin >> a >> f;
    s0[a] = f;
    s1[a] = 1LL * a * f % MOD;
    s2[a] = f * (1LL * a  * a % MOD) % MOD;
  }
  for (int i = 1; i < N; i++) {
    for (int j = 2*i; j < N; j += i) {
      s0[i] += s0[j];
      s1[i] = (s1[i] + s1[j]) % MOD;
      s2[i] = (s2[i] + s2[j]) % MOD;
    }
  }
  for (int i = 1; i < N; i++) {
    ll k = s0[i];
    if (k < 2) continue;
    int c1 = expmod(2, k-2, MOD);
    int c2 = 0;
    if (k > 2) {
      int d = 1LL * ((k-2) % MOD) * expmod(2, k-3, MOD) % MOD;
      c1 = (c1 + d) % MOD;
      c2 = (c2 + d) % MOD;
    }
    S[i] = ((1LL * c2 * s2[i]) + (c1 * (1LL * s1[i] * s1[i] % MOD))) % MOD;
  }
  for (int i = N-1; i >= 1; i--) {
    for (int j = 2*i; j < N; j += i) {
      S[i] = (S[i]-S[j]) % MOD;
    }
  }

  cout << (S[1]+MOD)%MOD << endl;
}