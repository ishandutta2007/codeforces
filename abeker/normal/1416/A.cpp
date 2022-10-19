#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;

int N;
int a[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
}

void solve() {
  vector <vector <int>> occ(N + 1, vector <int>{0});
  for (int i = 1; i <= N; i++)
    occ[a[i]].push_back(i);
  vector <int> ans(N + 1, N + 1);
  for (int i = 1; i <= N; i++) {
    int gap = 0;
    occ[i].push_back(N + 1);
    for (int j = 1; j < occ[i].size(); j++)
      gap = max(gap, occ[i][j] - occ[i][j - 1]);
    ans[gap] = min(ans[gap], i);
  }
  for (int i = 1; i <= N; i++) {
    ans[i] = min(ans[i], ans[i - 1]);
    printf("%d ", ans[i] == N + 1 ? -1 : ans[i]);
  }
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