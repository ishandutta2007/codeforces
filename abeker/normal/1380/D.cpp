#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N, M, K;
ll X, Y;
int power[MAXN], pos[MAXN];
ll ans;

void bye() {
  puts("-1");
  exit(0);
}

void solve(int from, int to) {
  if (from > to)
    bye();
  int len = to - from - 1;
  if (!len)
    return;
  ll best = len / K * X + len % K * Y;
  bool all_small = *max_element(power + from + 1, power + to) < max(power[from], power[to]);
  if (all_small)
    best = min(best, len * Y);
  else {
    if (len < K)
      bye();
    best = min(best, (len - K) * Y + X);
  }
  ans += best;
}

int main() {
  scanf("%d%d", &N, &M);
  scanf("%lld%d%lld", &X, &K, &Y);
  for (int i = 1; i <= N; i++) {
    scanf("%d", power + i);
    pos[power[i]] = i;
  }
  
  int prev = 0;
  while (M--) {
    int target;
    scanf("%d", &target);
    solve(prev, pos[target]);
    prev = pos[target];
  }
  solve(prev, N + 1);
  
  printf("%lld\n", ans);
  
  return 0;
}