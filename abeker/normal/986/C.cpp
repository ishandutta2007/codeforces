#include <bits/stdc++.h>
using namespace std;

const int MAXN = 22;
const int MAXM = 1 << MAXN;

int N, M;
int a[MAXM];
int comp[MAXM];
bool bio[MAXM][MAXN];
int dad[MAXM], rnk[MAXM];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; i++)
    scanf("%d", a + i);
}

int find(int x) {
  return dad[x] == x ? x : dad[x] = find(dad[x]);
}

int join(int x, int y) {
  if (!x || !y)
    return x ^ y;
  x = find(x);
  y = find(y);
  if (rnk[x] > rnk[y])
    swap(x, y);
  dad[x] = y;
  rnk[y] += rnk[x] == rnk[y];
  return y;
}

void dfs(int mask, int len) {
  if (bio[mask][len] || len == N)
    return;
  bio[mask][len] = true;
  dfs(mask, len + 1);
  if (mask >> len & 1)
    dfs(mask ^ 1 << len, len + 1);
}

int solve() {
  int all = (1 << N) - 1;
  for (int i = 1; i <= M; i++) {
    comp[a[i]] = i;
    a[i] ^= all;
    dfs(a[i], 0);
    dad[i] = i;
  }
  for (int j = N - 1; j >= 0; j--) 
    for (int i = all; i >= 0; i--)
      if (!bio[i][j])
        comp[i] = 0;
      else if (i >> j & 1)
        comp[i] = join(comp[i], comp[i ^ 1 << j]);
  for (int i = 1; i <= M; i++)
    join(i, comp[a[i]]);
  int sol = 0;
  for (int i = 1; i <= M; i++)
    sol += find(i) == i;
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}