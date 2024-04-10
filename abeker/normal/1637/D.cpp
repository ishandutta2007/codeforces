#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 5;

int N;
int a[MAXN], b[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
  for (int i = 0; i < N; i++)
    scanf("%d", b + i);
}

int sqr(int x) {
  return x * x;
}

int solve() {
  int sum = 0, sq = 0;
  bitset <MAXN * MAXN> dp;
  dp.set(0);
  for (int i = 0; i < N; i++) {
    sum += a[i] + b[i];
    sq += sqr(a[i]) + sqr(b[i]);
    dp = (dp << a[i]) | (dp << b[i]);
  }
  int sol = 1e9;
  for (int i = 0; i <= sum / 2; i++)
    if (dp.test(i)) 
      sol = min(sol, sqr(i) + sqr(sum - i));
  return sol + (N - 2) * sq;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    load();
    printf("%d\n", solve());
  }
  return 0;
}