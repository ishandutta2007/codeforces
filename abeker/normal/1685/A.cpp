#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
int a[MAXN], b[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

bool check(int x, int y, int z) {
  return (x > y && y < z) || (x < y && y > z);
}

void solve() {
  if (N % 2) {
    puts("NO");
    return;
  }
  sort(a, a + N);
  for (int i = 0; i < N; i++)
    b[i] = i % 2 ? a[(i + N) / 2] : a[i / 2];
  for (int i = 0; i < N; i++)
    if (!check(b[(i + N - 1) % N], b[i], b[(i + 1) % N])) {
      puts("NO");
      return;
    }
  puts("YES");
  for (int i = 0; i < N; i++)
    printf("%d ", b[i]);
  puts("");
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