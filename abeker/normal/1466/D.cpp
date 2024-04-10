#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  scanf("%d", &N);
  vector <int> weight(N);
  for (auto &it : weight)
    scanf("%d", &it);
  multiset <int, greater <int>> sorted;
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    sorted.insert(weight[--u]);
    sorted.insert(weight[--v]);
  }
  long long ans = 0;
  for (auto it : weight) {
    sorted.erase(sorted.find(it));
    ans += it;
  }
  for (auto it : sorted) {
    printf("%lld ", ans);
    ans += it;
  }
  printf("%lld\n", ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--)
    solve();
  return 0;
}