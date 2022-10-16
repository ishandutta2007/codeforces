#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 5;
int n, a[N], s[N];
void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
  int ans = N;
  for(int i = 0; i <= n; i++) ans = min(ans, s[i] + max(0, (n - i) - (s[n] - s[i]) - s[i]));
  cout << ans << "\n";
}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}