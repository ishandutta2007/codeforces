#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e5 + 5;
constexpr int mod = 998244353;
int ksm(int a, int b) {
  int s = 1;
  while(b) {
    if(b & 1) s = 1ll * s * a % mod;
    a = 1ll * a * a % mod, b >>= 1;
  }
  return s;
}
int fc[N], ifc[N], pw[N];
int bin(int n, int m) {return 1ll * fc[n] * ifc[m] % mod * ifc[n - m] % mod;}
ll n, a[N], pre[N], suf[N];
void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  suf[n] = 0;
  for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
  for(int i = n - 1; ~i; i--) suf[i] = suf[i + 1] + a[i + 1];
  int l = 1, r = n - 1, ans = 1;
  while(l <= r) {
    if(pre[l] < suf[r]) {l++; continue;}
    if(pre[l] > suf[r]) {r--; continue;}
    if(pre[r] - pre[l] == 0) {
      ans = 1ll * ans * pw[r - l + 1] % mod;
      break;
    }
    int lr = l, rl = r;
    while(pre[lr + 1] == pre[l]) lr++;
    while(suf[rl - 1] == suf[r]) rl--;
    int coef = 0, lenl = lr - l + 1, lenr = r - rl + 1;
    for(int p = 0; p <= min(lenl, lenr); p++)
      coef = (coef + 1ll * bin(lenl, p) * bin(lenr, p)) % mod;
    // cout << lenl << " " << lenr << " " << coef << "\n";
    // cout << l << " " << lr << " " << r << " " << rl << "\n";
    ans = 1ll * ans * coef % mod;
    l = lr + 1, r = rl - 1;
  }
  cout << ans << "\n";
}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  for(int i = fc[0] = 1; i < N; i++) fc[i] = 1ll * fc[i - 1] * i % mod;
  ifc[N - 1] = ksm(fc[N - 1], mod - 2);
  for(int i = N - 2; ~i; i--) ifc[i] = 1ll * ifc[i + 1] * (i + 1) % mod;
  for(int i = pw[0] = 1; i < N; i++) pw[i] = 2ll * pw[i - 1] % mod;
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}