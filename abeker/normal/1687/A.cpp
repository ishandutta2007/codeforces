#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N, K;
ll a[MAXN];

void load() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; i++) {
    scanf("%lld", a + i);
    a[i] += a[i - 1];
  }
}

ll solve() {
  ll sol = 0;
  int len = min(N, K);
  for (int i = 1; i + len - 1 <= N; i++)
    sol = max(sol, a[i + len - 1] - a[i - 1]);
  return sol + (ll)len * (2 * K - len - 1) / 2;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%lld\n", solve());
  }
  return 0;
}