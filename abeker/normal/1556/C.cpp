#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int N;
  scanf("%d", &N);
  vector <int> c(N);
  for (auto &it : c)
    scanf("%d", &it);
  ll ans = 0;
  for (int i = 0; i < N; i += 2) {
    ll sum = 0, mini = 1e18;
    for (int j = i + 1; j < N; j++) {
      if (j % 2) {
        ll lb = max(-mini, 1ll - min(sum, 0ll));
        ll ub = min((ll)c[i], c[j] - sum);
        ans += max(ub - lb + 1, 0ll);
      }
      sum += j % 2 ? -c[j] : c[j];
      mini = min(mini, sum);
    }
  }
  printf("%lld\n", ans);
  return 0;
}