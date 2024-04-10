#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 45;
const int MOD = 1e9 + 7;

int N, L;
int perm[MAXN];
bool bio[MAXN];
int prod[MAXN];
vector <int> dp;
vector <pii> occ;
int fact[MAXN], inv[MAXN];
int ways[MAXN];

void load() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", perm + i);
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

int pot(int x, int y) {
  int r = 1;
  for (; y; y /= 2) {
    if (y % 2)
      r = mul(r, x);
    x = mul(x, x);
  }
  return r;
}

int choose(int n, int k) {
  return mul(fact[n], mul(inv[k], inv[n - k]));
}

int rec(int state);

int go(int pos, int nodes, int sum, int rest, int mask, int coef, const vector <int> &seq) {
  int res = 0;
  if (pos == L) {
    if (!sum)
      return 0;
    res = mul(rec(mask), mul(coef, pot(ways[rest], sum)));
    return nodes % 2 ? res : add(0, -res);
  }
  for (int i = 0; i <= seq[pos]; i++)
    res = add(res, go(pos + 1, nodes + i, sum + i * occ[pos].first, rest - i * occ[pos].first, mask - i * prod[pos], mul(coef, choose(seq[pos], i)), seq));
  return res;
}

int rec(int state) {
  int &ref = dp[state];
  if (ref != -1)
    return ref;
  if (!state)
    return ref = 1;
  int tot = 0;
  vector <int> curr(L);
  for (int i = 0; i < L; i++) {
    curr[i] = state / prod[i] % (occ[i].second + 1);
    tot += curr[i] * occ[i].first;
  }
  return ref = go(0, 0, 0, tot, state, 1, curr);
}

int solve() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = mul(fact[i - 1], i);
    inv[i] = pot(fact[i], MOD - 2);
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j <= i; j++)
      ways[i] = add(ways[i], mul(choose(i, j), mul(fact[j], fact[N - j - 1])));
  map <int, int> cnt;
  for (int i = 1; i <= N; i++)
    if (!bio[i]) {
      int len = 0;
      for (int j = i; !bio[j]; j = perm[j]) {
        bio[j] = true;
        len++;
      }
      cnt[len]++;
    }
  for (auto it : cnt)
    occ.push_back(it);
  L = occ.size();
  prod[0] = 1;
  for (int i = 0; i < L; i++)
    prod[i + 1] = prod[i] * (occ[i].second + 1);
  dp.resize(prod[L], -1);
  return rec(prod[L] - 1);
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}