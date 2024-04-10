#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
const int MOD = 998244353;

int N, K;
int a[MAXN];
int dp[MAXN][MAXN];

void load() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++)
    scanf("%d", a + i);
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  return x;
}  

int solve() {
  sort(a, a + N);
  int sol = 0, limit = (a[N - 1] - a[0]) / (K - 1);
  for (int v = 1; v <= limit; v++) {
    int ptr = 0;
    vector <int> pos(N);
    for (int i = 0; i < N; i++) {
      while (ptr < N && a[ptr] < a[i] + v)
        ptr++;
      pos[i] = ptr;
    }
    dp[N][0] = 1;
    for (int i = N - 1; i >= 0; i--) {
      dp[i][0] = 1;
      for (int j = 1; j <= K; j++)
        dp[i][j] = add(dp[i + 1][j], dp[pos[i]][j - 1]);
    }
    sol = add(sol, dp[0][K]);
  }
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}