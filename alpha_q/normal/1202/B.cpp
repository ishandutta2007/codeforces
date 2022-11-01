#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

char s[N];
int n, yo[N], ans[15][15], step[15][15][15];

int get (int x, int y) {
  int ret = 0;
  for (int i = 2; i <= n; ++i) {
    if (step[x][y][yo[i]] >= 6969) return -1;
    ret += step[x][y][yo[i]];
  }
  return ret;
}

int main() {
  memset(step, 63, sizeof step);
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int a = 0; a < 10; ++a) {
        for (int b = 0; b < 10; ++b) {
          if (a + b == 0) continue;
          int k = (a * i + b * j) % 10;
          step[i][j][k] = min(step[i][j][k], a + b - 1);
        }
      }
    }
  }
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 2; i <= n; ++i) {
    yo[i] = s[i] - s[i - 1];
    if (yo[i] < 0) yo[i] += 10;
  }
  for (int x = 0; x < 10; ++x) {
    for (int y = x; y < 10; ++y) {
      ans[x][y] = ans[y][x] = get(x, y);
    }
  }
  for (int x = 0; x < 10; ++x) {
    for (int y = 0; y < 10; ++y) {
      printf("%d ", ans[x][y]);
    }
    puts("");
  }
  return 0;
}