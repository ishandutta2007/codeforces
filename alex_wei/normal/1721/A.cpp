#include <bits/stdc++.h>
using namespace std;
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  while(T--) {
    char a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    sort(a, a + 4);
    int ans = 0;
    for(int i = 1; i < 4; i++) ans += a[i] != a[i - 1];
    cout << ans << "\n";
  }
  return 0;
}