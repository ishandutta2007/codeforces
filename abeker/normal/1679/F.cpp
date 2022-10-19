#include <bits/stdc++.h>
using namespace std;

const int D = 10;
const int MOD = 998244353;

int N, M;
int bigger[D], smaller[D];
int dp[2][1 << D];

void load() {
  scanf("%d%d", &N, &M);
  while (M--) {
    int u, v;
    scanf("%d%d", &u, &v);
    bigger[u] |= 1 << v;
    smaller[v] |= 1 << u;
  }
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  return x;
}

inline void inc(int &x, int y) {
  x = add(x, y);
}

int solve() {
  int *curr = dp[0], *nxt = dp[1];
  curr[0] = 1;
  while (N--) {
    memset(nxt, 0, sizeof(int) << D);
    for (int i = 0; i < 1 << D; i++)
      for (int j = 0; j < D; j++)
        if (!(i & smaller[j]))
          inc(nxt[(i & bigger[j]) | (1 << j)], curr[i]);
    swap(curr, nxt);
  }
  return accumulate(curr, curr + (1 << D), 0, add);
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}