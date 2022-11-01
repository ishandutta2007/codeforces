#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, q, a[2][N], ver, ang;

int main() {
  cin >> n >> q;
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y); --x;
    if (a[x][y]) {
      a[x][y] = 0;
      if (a[x ^ 1][y]) --ver;
      if (y > 1 and a[x ^ 1][y - 1]) --ang;
      if (y < n and a[x ^ 1][y + 1]) --ang;
    } else {
      a[x][y] = 1;
      if (a[x ^ 1][y]) ++ver;
      if (y > 1 and a[x ^ 1][y - 1]) ++ang;
      if (y < n and a[x ^ 1][y + 1]) ++ang;
    }
    puts(ver or ang ? "No" : "Yes");
  }
  return 0;
}