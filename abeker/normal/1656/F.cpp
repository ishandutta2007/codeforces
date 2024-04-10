#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N;
int a[MAXN];
ll pref[MAXN], suff[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
}

void solve() {
  sort(a + 1, a + N + 1);
  for (int i = 1; i <= N; i++)
    pref[i] = pref[i - 1] + a[i];
  suff[N + 1] = 0;
  for (int i = N; i; i--)
    suff[i] = suff[i + 1] + a[i];
  if ((ll)(N - 1) * a[1] + suff[2] > 0 || (ll)(N - 1) * a[N] + pref[N - 1] < 0) {
    puts("INF");
    return;
  }
  ll sol = -1e18;
  auto f = [&](int x, int t) -> ll {
    return a[1] * suff[x + 1] + a[N] * pref[x] - (ll)a[1] * a[N] + ((ll)(N - x - 1) * a[1] + (ll)(x - 1) * a[N] + suff[1]) * t;
  };
  for (int i = 1; i < N; i++)
    sol = max(sol, max(f(i, -a[i]), f(i, -a[i + 1])));
  printf("%lld\n", sol);
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