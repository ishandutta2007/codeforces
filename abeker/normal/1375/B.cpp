#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e2 + 5;

int N, M;
int a[MAXN][MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      scanf("%d", a[i] + j);
}

bool ok(int x, int y) {
  return x >= 0 && y >= 0 && x < N && y < M;
}

int neighbours(int x, int y) {
  int res = 0;
  res += ok(x - 1, y);
  res += ok(x + 1, y);
  res += ok(x, y - 1);
  res += ok(x, y + 1);
  return res;
}

void solve() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      int tmp = neighbours(i, j);
      if (a[i][j] > tmp) {
        puts("NO");
        return;
      }
      a[i][j] = tmp;
    }
  puts("YES");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      printf("%d ", a[i][j]);
    puts("");
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    solve();
  }
  return 0;
}