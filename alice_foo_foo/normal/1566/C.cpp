#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;

char a[maxN], b[maxN];
int T, n;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%s%s", &n, a + 1, b + 1);
    int ans = 0, flag = 0;
    for (int i = 1; i <= n; i++) {
      int cnt0 = (a[i] == '0') + (b[i] == '0');
      if (cnt0 == 1) {
        ans += 2;
        flag = 0;
      }
      if (cnt0 == 0) {
        if (flag == 2) {
          ++ans;
          flag = 0;
        } else flag = 1;
      }
      if (cnt0 == 2) {
        ++ans;
        if (flag == 1) {
          ++ans;
          flag = 0;
        } else flag = 2;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}