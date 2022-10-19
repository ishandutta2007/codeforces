#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int offset = 1 << 19;
const int MOD = 998244353;

struct Node {
  int first, last;
  int dp[2][2];
  int* operator [](int x) {
    return dp[x];
  }
};

int N, M;
char s[MAXN];
Node tour[2 * offset];

void load() {
  scanf("%d%d%s", &N, &M, s);
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

inline int ways(int a, int b) {
  return a ? max(19 - 10 * a - b, 0) : 0;
}

Node merge(Node l, Node r) {
  if (l.first == -1)
    return r;
  if (r.first == -1)
    return l;
  Node res;
  res.first = l.first;
  res.last = r.last;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) 
      res[i][j] = add(mul(l[i][0], r[0][j]), mul(ways(l.last, r.first), mul(l[i][1], r[1][j])));
  return res;
}

void modify(int pos, int digit) {
  tour[pos + offset] = {digit, digit, {{digit + 1, 1}, {1, 0}}};
}

void update(int x, int d) {
  modify(x, d);
  x += offset;
  for (x /= 2; x; x /= 2)
    tour[x] = merge(tour[2 * x], tour[2 * x + 1]);
}

void solve() {
  for (int i = 0; i < offset; i++) {
    tour[i + offset] = {-1, -1, {{0, 0}, {0, 0}}};
    if (i < N) 
      modify(i, s[i] - '0');
  }
  for (int i = offset - 1; i >= 0; i--)
    tour[i] = merge(tour[2 * i], tour[2 * i + 1]);
  
  while (M--) {
    int x, d;
    scanf("%d%d", &x, &d);
    update(--x, d);
    printf("%d\n", tour[1][0][0]);
  }
}

int main() {
  load();
  solve();
  return 0;
}