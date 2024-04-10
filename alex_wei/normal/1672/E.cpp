#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
inline int read() {
  int x = 0;
  char s = getchar();
  while(!isdigit(s)) s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return x;
}
int query(int x) {return cout << "? " << x << endl, read();}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  int n = read();
  int l = 1, r = 1e7;
  while(l < r) {
    int m = l + r >> 1;
    if(query(m) != 1) l = m + 1;
    else r = m;
  }
  int ans = l;
  for(int i = 1; i <= n; i++) {
    int res = query(l / i);
    if(res) ans = min(ans, res * (l / i));
  }
  cout << "! " << ans << endl;
  return 0;
}
///