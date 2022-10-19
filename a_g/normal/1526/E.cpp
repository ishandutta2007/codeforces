#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 4e5+5;
int fact[N];
int invfact[N];
int a[N];
int b[N];

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
  int n, k;
  cin >> n >> k;
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[N-1] = inversemod(fact[N-1], MOD);
  for (int i = N-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]] = i;
  }
  int c = 0;
  for (int i = 0; i < n-1; i++) {
    int x = a[i];
    int y = a[i+1];
    int u = (x < n-1 ? b[x+1] : -1);
    int v = (y < n-1 ? b[y+1] : -1);
    if (u > v) c++;
  }

  if (k < c+1) {
    cout << "0\n";
    return 0;
  }
  int ans = 1;
  for (int m: {fact[n+k-c-1], invfact[n], invfact[k-c-1]}) {
    ans = 1LL * ans * m % MOD;
  }
  cout << ans << '\n';
}