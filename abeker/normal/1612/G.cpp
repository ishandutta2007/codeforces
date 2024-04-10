#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INV = (MOD + 1) / 2;

int M;
int cnt[MAX];
int fact[MAX];

void load() {
  scanf("%d", &M);
  while (M--) {
    int c;
    scanf("%d", &c);
    cnt[--c]++;
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

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int gauss(int n) {
  return mul(mul(n, add(n, 1)), INV);
}

void solve() {
  fact[0] = 1;
  for (int i = 1; i < MAX; i++)
    fact[i] = mul(fact[i - 1], i);
  for (int i = MAX - 3; i >= 0; i--)
    cnt[i] += cnt[i + 2];
  int sum = 0, ways = 1, pos = 0;
  for (int i = 1 - MAX; i < MAX; i++) {
    int curr_cnt = cnt[abs(i)];
    int nxt_pos = add(pos, curr_cnt);
    sum = add(sum, mul(i, add(gauss(nxt_pos), -gauss(pos))));
    ways = mul(ways, fact[curr_cnt]);
    pos = nxt_pos;
  }
  printf("%d %d\n", sum, ways);
}

int main() {
  load();
  solve();
  return 0;
}