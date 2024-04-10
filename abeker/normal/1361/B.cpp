#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MOD[] = {1000000007, 68405159, 60632783, 77059739, 86003231, 92587463};

int N, P;
int ex[MAXN];

void load() {
  scanf("%d%d", &N, &P);
  for (int i = 0; i < N; i++)
    scanf("%d", ex + i);
}

inline void add(int &x, int y, int mod) {
  x += y;
  if (x >= mod)
    x -= mod;
  else if (x < 0)
    x += mod;
}

inline int mul(int x, int y, int mod) {
  return (long long)x * y % mod;
}

int pot(int x, int y, int mod) {
  int res = 1;
  for (; y; y /= 2) {
    if (y % 2)
      res = mul(res, x, mod);
    x = mul(x, x, mod);
  }
  return res;
}

int solve() {
  sort(ex, ex + N);
  ex[N] = ex[N - 1];
  int coef[2] = {0};
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < 2; j++)
      coef[j] = mul(coef[j], pot(P, ex[i + 1] - ex[i], MOD[j]), MOD[j]);
    bool subtract = coef[0] || coef[1];
    for (int j = 0; j < 2; j++)
      add(coef[j], subtract ? -1 : 1, MOD[j]);
  }
  return mul(coef[0], pot(P, ex[0], MOD[0]), MOD[0]);
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