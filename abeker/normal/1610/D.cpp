#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int LOG = 30;

int N;
int cnt[LOG];
int pot[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int x;
    scanf("%d", &x);
    int v2 = 0;
    for (; !(x % 2); x /= 2)
      v2++;
    cnt[v2]++;
  }
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}

int solve() {
  pot[0] = 1;
  for (int i = 1; i <= N; i++)
    pot[i] = add(pot[i - 1], pot[i - 1]);
  int sofar = 0;
  int sol = add(pot[N], -1);
  for (int i = LOG - 1; i; i--) {
    if (cnt[i])
      sol = add(sol, -pot[sofar + cnt[i] - 1]);
    sofar += cnt[i];
  }
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}