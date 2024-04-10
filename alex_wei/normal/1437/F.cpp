#include <bits/stdc++.h>
using namespace std;
bool Mbe;
constexpr int N = 5e3 + 5;
constexpr int mod = 998244353;
int ksm(int a, int b) {
  int s = 1;
  while(b) {
    if(b & 1) s = 1ll * s * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return s;
}
int n, a[N], p[N], f[N], fc[N], ifc[N];
int A(int n, int m) {return 1ll * fc[n] * ifc[n - m] % mod;}
bool Med;
int main() {
  fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
#ifdef ALEX_WEI
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
#endif
  for(int i = fc[0] = 1; i < N; i++) fc[i] = 1ll * fc[i - 1] * i % mod;
  ifc[N - 1] = ksm(fc[N - 1], mod - 2);
  for(int i = N - 2; ~i; i--) ifc[i] = 1ll * ifc[i + 1] * (i + 1) % mod;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  if(a[n - 1] * 2 > a[n]) puts("0"), exit(0);
  for(int i = 2; i <= n; i++) {
    p[i] = p[i - 1];
    while(a[p[i] + 1] * 2 <= a[i]) p[i]++;
  }
  for(int i = 1; i <= n; i++) {
    f[i] = A(n - 1, p[i]);
    for(int j = 1; j < i; j++)
      if(a[j] * 2 <= a[i])
        f[i] = (f[i] + 1ll * f[j] * A(n - 2 - p[j], p[i] - 1 - p[j])) % mod;
  }
  cout << f[n] << endl;
  return 0;
}
/*
2022/6/16
start coding at 13:25
finish debugging at 13:33
*/