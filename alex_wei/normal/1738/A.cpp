#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e5 + 5;
ll n, a[N], ice[N], fire[N];
void solve() {
  cin >> n;
  int ci = 0, cf = 0;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) {
    ll b;
    cin >> b;
    if(a[i]) ice[++ci] = b;
    else fire[++cf] = b;
  }
  sort(ice + 1, ice + ci + 1);
  sort(fire + 1, fire + cf + 1);
  if(ci == cf) {
    ll ans = 0;
    for(int i = 1; i <= ci; i++) ans += ice[i];
    for(int i = 1; i <= cf; i++) ans += fire[i];
    cout << ans * 2 - min(ice[1], fire[1]) << "\n";
  }
  else {
    int cnt = min(ci, cf);
    ll ans = 0;
    for(int i = ci; i > ci - cnt; i--) ans += ice[i] * 2;
    for(int i = ci - cnt; i; i--) ans += ice[i];
    for(int i = cf; i > cf - cnt; i--) ans += fire[i] * 2;
    for(int i = cf - cnt; i; i--) ans += fire[i];
    cout << ans << "\n";
  }
}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}