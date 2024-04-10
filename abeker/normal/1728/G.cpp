#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MAXM = 18;
const int MOD = 998244353;

int D, N, M, Q;
int sum[MAXM][MAXM];
int trans[MAXM][MAXM];
int lantern[MAXN];
int point[MAXM];

void load() {
  scanf("%d%d%d", &D, &N, &M);
  for (int i = 0; i < N; i++)
    scanf("%d", lantern + i);
  for (int i = 1; i <= M; i++)
    scanf("%d", point + i);
}

inline void add(int &x, int y) {
  x += y;
  if (x >= MOD)
    x -= MOD;
  else if (x < 0)
    x += MOD;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

inline int dist(int x, int y) {
  return abs(lantern[x] - point[y]);
}

inline int closer(int x, int y, int z) {
  return min(dist(x, y), dist(x, z));
}

inline bool in_range(int x, int y, int z) {
  return lantern[x] > point[y] && lantern[x] < point[z];
}

void solve() {
  point[0] = -3 * MAXN;
  point[M + 1] = 3 * MAXN;
  sort(point + 1, point + M + 1);
  for (int i = 0; i <= M; i++)
    for (int j = i + 1; j <= M + 1; j++) {
      trans[i][j] = 1;
      for (int k = 0; k < N; k++)
        if (in_range(k, i, j))
          trans[i][j] = mul(trans[i][j], closer(k, i, j));
    }
  int pot = 1;
  for (int i = 0; i <= N; i++)
    pot = mul(pot, D + 1);
  for (int i = 1; i < 1 << M; i++) {
    vector <int> bits = {0};
    for (int j = 0; j < M; j++)
      if (i >> j & 1)
        bits.push_back(j + 1);
    bits.push_back(M + 1);
    int prod = bits.size() % 2 ? MOD - 1 : 1;
    for (int j = 1; j < bits.size(); j++)
      prod = mul(prod, trans[bits[j - 1]][bits[j]]);
    for (int j = 1; j < bits.size(); j++)
      add(sum[bits[j - 1]][bits[j]], prod);
  }
  scanf("%d", &Q);
  while (Q--) {
    int ans = pot;
    scanf("%d", lantern + N);
    for (int i = 0; i <= M; i++)
      for (int j = i + 1; j <= M + 1; j++)
        if (in_range(N, i, j))
          add(ans, mul(closer(N, i, j), sum[i][j]));
    printf("%d\n", ans);
  }
}

int main() {
  load();
  solve();
  return 0;
}