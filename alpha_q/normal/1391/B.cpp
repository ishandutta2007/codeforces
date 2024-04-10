#include <bits/stdc++.h>

using namespace std;

const int N = 12345;

char s[N];
int t, n, m;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%s", s + 1);
      if (i == n) {
        for (int j = 1; j < m; ++j) {
          if (s[j] == 'D') ++ans;
        }
      } else {
        if (s[m] == 'R') ++ans;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}