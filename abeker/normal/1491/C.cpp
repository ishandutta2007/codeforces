#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int N;
    scanf("%d", &N);
    vector <int> a(N);
    for (auto &it : a)
      scanf("%d", &it);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
      ll sum = 0;
      for (int j = 0; j <= i; j++)
        sum += max(a[j] + j - i, 0);
      ans = max(ans, sum);
    }
    printf("%lld\n", ans - 1);
  }
  return 0;
}