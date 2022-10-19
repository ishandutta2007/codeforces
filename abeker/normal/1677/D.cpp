#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 998244353;

int N, K;
int v[MAXN];

void load() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++)
    scanf("%d", v + i);
}

inline void mul(int &x, int y) {
  x = (long long)x * y % MOD;
}

int solve() {
  int sol = 1;
  for (int i = 0; i < N; i++) {
    int tmp = v[(i + N - K) % N];
    if (tmp == -1)
      mul(sol, i + 1);
    else if (tmp == 0)
      mul(sol, min(i, K) + 1);
    else if (tmp + K > i)
      return 0;
  }
  return sol;
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