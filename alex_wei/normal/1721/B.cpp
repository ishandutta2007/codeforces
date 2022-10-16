#include <bits/stdc++.h>
using namespace std;
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  while(T--) {
    int n, m, x, y, d;
    cin >> n >> m >> x >> y >> d;
    bool ok = 1;
    for(int i = 1; i <= n; i++) ok &= abs(i - x) + abs(1 - y) > d;
    for(int i = 1; i <= m; i++) ok &= abs(n - x) + abs(i - y) > d;
    if(ok) {
      cout << n + m - 2 << "\n";
      continue;
    }
    ok = 1;
    for(int i = 1; i <= m; i++) ok &= abs(1 - x) + abs(i - y) > d;
    for(int i = 1; i <= n; i++) ok &= abs(i - x) + abs(m - y) > d;
    if(ok) cout << n + m - 2 << "\n";
    else cout << "-1\n";
  }
  return 0;
}