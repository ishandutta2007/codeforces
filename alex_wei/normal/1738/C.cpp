#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, o = 0, a;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a, o += a & 1;
  int z = n - o;
  o &= 3, z &= 1;
  if(!z) puts(o == 0 || o == 3 ? "Alice" : "Bob");
  else puts(o == 2 ? "Bob" : "Alice");
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