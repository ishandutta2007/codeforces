#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 5;
int n, q, nxt[N], exceed[N], tr[N][26];
char s[N], t[15];
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  scanf("%s%d", s + 1, &q);
  n = strlen(s + 1);
  for(int i = 2, p = 0; i <= n; i++) {
    while(p && s[p + 1] != s[i]) p = nxt[p];
    nxt[i] = p += s[p + 1] == s[i];
  }
  for(int i = 0; i <= n; i++) {
    for(int S = 0; S < 26; S++) {
      if(i < n && s[i + 1] - 'a' == S) tr[i][S] = i + 1;
      else if(i) tr[i][S] = tr[nxt[i]][S];
    }
  }
  for(int i = 1; i <= q; i++) {
    scanf("%s", t + 1);
    int m = strlen(t + 1);
    for(int j = 1, p = nxt[n]; j <= m; j++) {
      bool trans = 0;
      while(p) {
        char nxc = p < n ? s[p + 1] : t[p + 1 - n];
        if(nxc == t[j]) {
          p++, trans = 1;
          break;
        }
        if(p > n) p = exceed[p - n];
        else {
          p = tr[p][t[j] - 'a'], trans = 1;
          break;
        }
      }
      if(!trans) p = s[1] == t[j];
      exceed[j] = p;
      cout << p << " ";
    }
    cout << "\n";
  }
  return 0;
}