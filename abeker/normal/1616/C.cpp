#include <bits/stdc++.h>
using namespace std;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    vector <int> a(N);
    for (auto &it : a)
      scanf("%d", &it);
    int ans = N - 1;
    auto attempt = [&](int x, int y) {
      int changes = 0;
      for (int i = 0; i < N; i++)
        changes += (a[x] - a[i]) * (x - y) != (a[x] - a[y]) * (x - i);
      ans = min(ans, changes);
    };
    for (int i = 0; i < N; i++)
      for (int j = 0; j < i; j++)
        attempt(i, j);
    printf("%d\n", ans);
  }
  return 0;
}