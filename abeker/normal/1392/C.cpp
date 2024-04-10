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
    long long ans = 0;
    for (int i = 1; i < N; i++)
      if (a[i - 1] > a[i])
        ans += a[i - 1] - a[i];
    printf("%lld\n", ans);
  }
  return 0;
}