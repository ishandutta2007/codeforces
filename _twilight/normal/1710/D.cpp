#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;

int T;
int n;
char buf[N];
bool f[N][N];

void dividing(int l, int r) {
  bool flg = true;
  for (int l0 = l + 1, r0 = r; l0 <= r; l0 = r0 + 1, r0 = r) {
    while (!f[l0][r0]) r0--;
    dividing(l0, r0);
    for (int i = l0; i <= r; i++) {
      if (f[l][i]) {
        if (i > r0) {
          if (flg) {
            printf("%d %d\n", r0, i);
            flg = false;
          } else {
            printf("%d %d\n", l, l0);
          }
        } else {
          flg = true;
          printf("%d %d\n", l, i);
        }
        break;
      }
    }
  }
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", buf + i);
    for (int j = i; j <= n; j++) {
      f[i][j] = (buf[j] == '1');
    }
  }
  dividing(1, n);
}

int main() {
  scanf("%d", &T);
  while (T--) {
    solve();
  }
  return 0;
}