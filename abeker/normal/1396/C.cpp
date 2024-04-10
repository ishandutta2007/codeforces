#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 5;
const ll INF = 1e18;

int N, D;
int pistol, laser, awp;
int monsters[MAXN];
ll opt1[MAXN], opt2[MAXN];
ll dp[MAXN][2][2];

void load() {
  scanf("%d%d%d%d%d", &N, &pistol, &laser, &awp, &D);
  for (int i = 1; i <= N; i++)
    scanf("%d", monsters + i);
}

ll solve() {
  for (int i = 1; i <= N; i++) {
    opt1[i] = (ll)monsters[i] * pistol + awp;
    opt2[i] = min((ll)(monsters[i] + 1) * pistol, (ll)laser) + pistol;
    opt2[i] = min(opt2[i], opt1[i]);
  }
  
  dp[0][1][0] = dp[0][1][1] = INF;
  for (int i = 1; i <= N; i++) {
    ll even = min(dp[i - 1][0][0], dp[i - 1][1][0]);
    dp[i][0][0] = min(even, dp[i - 1][1][1] + 2 * D) + opt1[i];
    dp[i][1][0] = dp[i - 1][1][1] + opt2[i] + D;
    dp[i][1][1] = even + opt2[i] + D;
  }
  
  ll sum = 0, sol = INF;
  for (int i = N; i; i--) {
    sol = min(sol, sum + (i == N ? min(dp[i][0][0], min(dp[i][1][0], dp[i][1][1] + 2 * D)) : dp[i][0][0] - opt1[i] + opt2[i]));
    sum += min(opt2[i] + 2 * (i == N) * D, opt1[i]) + D;
  }
  
  return sol + (ll)(N - 1) * D;
}

int main() {
  load();
  printf("%lld\n", solve());
  return 0;
}