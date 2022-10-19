#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll INF = (ll)1e18;

const int len[] = {1, 90, 1440};
const int cost[] = {20, 50, 120};

int N;
int t[MAXN];
ll dp[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", t + i);
}

void solve() {
  for (int i = 1; i <= N; i++) {
    dp[i] = INF;
    for (int j = 0; j < 3; j++) {
      int pos = lower_bound(t + 1, t + N + 1, t[i] - len[j] + 1) - t - 1;
      dp[i] = min(dp[i], dp[pos] + cost[j]);
    }
    printf("%lld\n", dp[i] - dp[i - 1]);
  }
}

int main() {
  load();
  solve();
  return 0;
}