#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int t, n; 
char g[N][N];
bitset <N> h[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      scanf("%s", g[i] + 1);
    }
    for (int dig = 0; dig < 10; ++dig) {
      int tot = 0, upP = n, downP = 1, leftP = n, rightP = 1;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          h[i][j] = (g[i][j] == '0' + dig);
          if (h[i][j]) upP = min(upP, i), downP = max(downP, i), leftP = min(leftP, j), rightP = max(rightP, j);
        }
        tot += h[i].count();
      }
      if (tot < 2) {
        printf("0 ");
        continue;
      }
      int ans = 0;
      for (int i = 1; i <= n; ++i) {
        int l = 1, r = n;
        while (l <= n and !h[i][l]) ++l;
        while (r >= 1 and !h[i][r]) --r;
        if (l <= r) {
          ans = max(ans, (r - l) * max(i - 1, n - i));
          ans = max(ans, (n - l) * max(i - upP, downP - i));
          ans = max(ans, (r - 1) * max(i - upP, downP - i));
        }
      }
      for (int i = 1; i <= n; ++i) {
        int l = 1, r = n;
        while (l <= n and !h[l][i]) ++l;
        while (r >= 1 and !h[r][i]) --r;
        if (l <= r) {
          ans = max(ans, (r - l) * max(i - 1, n - i));
          ans = max(ans, (n - l) * max(i - leftP, rightP - i));
          ans = max(ans, (r - 1) * max(i - leftP, rightP - i));
        }
      }
      printf("%d ", ans);
    }
    cout << '\n';
  }
  return 0;
}