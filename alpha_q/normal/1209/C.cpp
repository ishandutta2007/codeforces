#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int t, n;
char s[N];
bitset <N> vis;

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %s", &n, s + 1);
    s[0] = '0', s[n + 1] = '9';
    int found = 0;
    for (int d = 0; d <= 9; ++d) {
      bool good = 1;
      for (int i = 0; i <= n + 1; ++i) {
        vis[i] = 0;
      }
      vector <int> one;
      one.emplace_back(0);
      int last = -1;
      for (int i = 1; i <= n; ++i) {
        if (s[i] - '0' < d) {
          if (s[i] - '0' < last) {
            good = 0; break;
          }
          one.emplace_back(i);
          last = s[i] - '0';
        }
      }
      if (!good) continue;
      one.emplace_back(n + 1);
      int sz = one.size();
      for (int i = 0; i + 1 < sz; ++i) {
        if (!(s[one[i]] - '0' <= d and d <= s[one[i + 1]] - '0')) continue;
        for (int j = one[i] + 1; j < one[i + 1]; ++j) {
          if (s[j] - '0' == d) one.emplace_back(j);
        }
      }
      for (int x : one) vis[x] = 1;
      last = -1;
      for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        if (s[i] - '0' < last) {
          good = 0; break;
        }
        last = s[i] - '0';
      }
      if (good) {
        found = 1;
        for (int i = 1; i <= n; ++i) {
          putchar(vis[i] ? '1' : '2');
        }
        puts("");
        break;
      }
    }
    if (!found) puts("-");
  }
  return 0;
}