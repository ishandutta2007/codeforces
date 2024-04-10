#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;
const ll INF = 1e18;

int N, M, G;
int a[MAXN];
ll dp[2][MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
  G = 0;
  while (M--) {
    int b;
    scanf("%d", &b);
    G = __gcd(G, b);
  }
}

ll solve() {
  for (int i = 0; i < G; i++) {
    dp[0][i] = 0;
    dp[1][i] = -INF;
  }
  for (int i = 0; i < N; i++) {
    int r = i % G;
    vector <ll> nxt(2);
    for (int j = 0; j < 2; j++)
      nxt[j] = max(dp[j][r] + a[i], dp[j ^ 1][r] - a[i]);
    for (int j = 0; j < 2; j++)
      dp[j][r] = nxt[j];
  }
  ll sol = -INF;
  for (int j = 0; j < 2; j++)
    sol = max(sol, accumulate(dp[j], dp[j] + G, 0ll));
  return sol;
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