#include <bits/stdc++.h>
using namespace std;

char nxt[256], pre[256], t[256];

char tail(char c) {
  return (nxt[c] ? t[c] = tail(nxt[c]) : c);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    for (char c = 'a'; c <= 'z'; c++) {
      nxt[c] = 0;
      pre[c] = 0;
      t[c] = c;
    }
    string ans(n, ' ');
    int edges = 0;
    for (int i = 0; i < n; i++) {
      if (!nxt[s[i]]) {
        for (char c = 'a'; c <= 'z'; c++) {
          if (pre[c]) continue;
          if (tail(c) == s[i] && edges != 25) continue;
          nxt[s[i]] = c;
          pre[c] = s[i];
          edges++;
          break;
        }
      }
      ans[i] = nxt[s[i]];
    }
    cout << ans << '\n';
  }
}