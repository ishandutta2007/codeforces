#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

bool solve() {
  int N;
  scanf("%d", &N);
  vector <vector <int>> cnt(2);
  for (int i = 0; i < 2; i++) {
    cnt[i].resize(2 * MAX + 1);
    for (int j = 0; j < N; j++) {
      int x;
      scanf("%d", &x);
      cnt[i][x + MAX]++;
    }
  }
  for (int i = 0; i < 2 * MAX; i++) {
    if (cnt[1][i] < 0)
      return false;
    cnt[0][i] -= cnt[1][i];
    if (cnt[0][i] < 0)
      return false;
    cnt[1][i + 1] -= cnt[0][i];
  }
  return true;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    puts(solve() ? "YES" : "NO");
  return 0;
}