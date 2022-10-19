#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int maxn = 1007;
int fact[maxn];
int invfact[maxn];

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int k = q/p;
  int b = inversemod(q-k*p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
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

  int n, x, pos;
  cin >> n >> x >> pos;
  int larger = 0;
  int smaller = 0;
  int l = 0;
  int r = n;
  while (l < r) {
    int m = (l+r)/2;
    if (m > pos) {
      larger++;
      r = m;
    }
    else if (m < pos) {
      smaller++;
      l = m+1;
    }
    else {
      l = m+1;
    }
  }

  if (larger > n-x || smaller > x-1) {
    cout << 0 << endl;
    return 0;
  }

  int ans = 1;
  for (int u: {fact[x-1], invfact[x-1-smaller], fact[n-x], invfact[n-x-larger], fact[n-1-smaller-larger]}) {
    ans = 1LL * u * ans % MOD;
  }
  cout << ans << endl;
}