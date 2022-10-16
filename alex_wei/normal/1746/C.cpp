#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 5;
int n, a[N], rev[N];
void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i], rev[a[i]] = i;
  for(int i = 1; i <= n; i++) cout << min(n, rev[i] + 1) << " ";
  cout << "\n";
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