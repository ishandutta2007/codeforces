#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int MAXK = 12;

int N, K;
int a[MAXN];
int freq[MAXN];
ll fact[MAXK];
int sum[1 << MAXK];
vector <int> dp[MAXN], inv[MAXN];
int vertices[MAXN], edges[MAXN];
int cnt, ways = 1;
int dad[MAXN];

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  return x;
}

inline int mul(int x, int y) {
  return (ll)x * y % MOD;
}

int inverse(int x) {
  int res = 1;
  for (int y = MOD - 2; y; y /= 2) {
    if (y % 2)
      res = mul(res, x);
    x = mul(x, x);
  }
  return res;
}

void load() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= N; i++)
    scanf("%d", a + i);
}

int find(int x) {
  return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    if (vertices[x] > vertices[y])
      swap(x, y);
    dad[x] = y;
    vertices[y] += vertices[x];
    edges[y] += edges[x];
  }
  edges[y]++;
}

void change_cycle(int len, int v) {
  int &ref = freq[len];
  ways = mul(ways, inv[len][ref + 1]);
  ref += v;
  if (len > 2)
    cnt += v;
  if (ref + 1 == dp[len].size()) {
    dp[len].push_back(mul(len, add(dp[len][ref], mul(ref - 1, dp[len][ref - 1]))));
    inv[len].push_back(inverse(dp[len][ref + 1]));
  }
  ways = mul(ways, dp[len][ref + 1]);
}

inline int lobit(int x) {
  return x & -x;
}

int go(short mask, ll prod) {
  if (!mask)
    return mul(cnt ? ways : 1, prod % MOD);
  int res = 0;
  short lowest = lobit(mask);
  mask ^= lowest;
  for (short nxt = mask; ; nxt = nxt - 1 & mask) {
    short tmp = nxt ^ lowest;
    change_cycle(sum[tmp], 1);
    res = add(res, go(mask ^ nxt, prod * fact[__builtin_popcount(nxt)]));
    change_cycle(sum[tmp], -1);
    if (!nxt)
      break;
  }
  return res;
}

int solve() {
  for (int i = 1; i <= N; i++) {
    dp[i] = inv[i] = {0, 1};
    vertices[i] = 1;
    dad[i] = i;
  }
  for (int i = 1; i <= N; i++)
    if (a[i])
      join(i, a[i]);
  vector <int> chains;
  for (int i = 1; i <= N; i++)
    if (find(i) == i) {
      if (edges[i] == vertices[i]) 
        change_cycle(vertices[i], 1);
      else
        chains.push_back(vertices[i]);
    }
  for (int i = 0; i < K; i++) {
    fact[i] = i ? fact[i - 1] * i : 1;
    sum[1 << i] = chains[i];
  }
  for (int i = 1; i < 1 << K; i++) {
    int lowest = lobit(i);
    sum[i] = sum[i ^ lowest] + sum[lowest];
  }
  return go((1 << K) - 1, 1);
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}