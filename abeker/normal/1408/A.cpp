#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;

int N;
int a[3][MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", a[i] + j);
}

void solve() {
  vector <int> ans(N);
  for (int j = 0; j < N; j++)
    for (int i = 0; i < 3; i++)
      if (a[i][j] != ans[(j - 1 + N) % N] && a[i][j] != ans[(j + 1) % N]) {
        ans[j] = a[i][j];
        break;
      }
  for (auto it : ans)
    printf("%d ", it);
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