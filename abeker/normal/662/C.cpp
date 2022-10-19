#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 21;
const int MAXM = 1e5 + 5;

int N, M;
int mask[MAXM];
ll f[1 << MAXN];
ll c[1 << MAXN];
int moves[1 << MAXN];
int choose[MAXN][MAXN];
int trans[MAXN][MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    char row[MAXM];
    scanf("%s", row);
    for (int j = 0; j < M; j++)
      if (row[j] == '1')
        mask[j] |= 1 << i;
  }
}

void fwht(ll* a, int len) {
  if (len == 1)
    return;
  len /= 2;
  fwht(a, len);
  fwht(a + len, len);
  for (int i = 0; i < len; i++) {
    ll tmp = a[i + len];
    a[i + len] = a[i] - tmp;
    a[i] += tmp;
  }
}

void convolution(int ones) {
  for (int i = 0; i < 1 << N; i++)
    c[i] = f[i] * trans[ones][__builtin_popcount(i)];
  fwht(c, 1 << N);
  for (int i = 0; i < 1 << N; i++)
    c[i] >>= N;
}

int solve() {
  for (int i = 0; i <= N; i++) {
    choose[i][0] = 1;
    for (int j = 1; j <= i; j++)
      choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
  }
  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= N; j++) {
      for (int k = max((i + j - N + 1) / 2, 0); k <= min(i, j) / 2; k++)
        trans[i][j] += 2 * choose[j][2 * k] * choose[N - j][i - 2 * k];
      trans[i][j] -= choose[N][i];
    }
  for (int i = 0; i < M; i++)
    f[mask[i]]++;
  fwht(f, 1 << N);
  for (int j = 0; j <= N; j++) {
    convolution(j);
    for (int i = 0; i < 1 << N; i++)
      moves[i] += c[i] * min(j, N - j);
  }
  return *min_element(moves, moves + (1 << N));
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}