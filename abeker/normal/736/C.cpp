#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXK = 25;
const int MOD = 1e9 + 7;

int N, K;
vector <int> adj[MAXN], ch[MAXN];
int dp_rec[MAXN][MAXK][MAXN];
int dp_sum[MAXN][MAXK][MAXN];
int max_dep[MAXN];

void load() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
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

int rec(int, int, int);
int sum(int, int, int);

int sum(int node, int covered, int highest) {
  covered = max(covered, 0);
  int &ref = dp_sum[node][covered][highest];
  if (ref != -1)
    return ref;
  if (highest > max_dep[node] + 1)
    return ref = 0;
  return ref = add(rec(node, covered, highest), sum(node, covered, highest + 1));
}

int rec(int node, int covered, int highest) {
  covered = max(covered, 0);
  int &ref = dp_rec[node][covered][highest];
  if (ref != -1)
    return ref;
  if (highest > max_dep[node])
    return ref = covered > max_dep[node];
  if (!covered && highest > K)  
    return ref = 0;
  if (!highest) {
    ref = 1;
    for (auto it : ch[node])
      ref = mul(ref, sum(it, K, 0));
    return ref;
  }
  vector <int> big;
  int nxt = max(covered - 1, K - highest);
  for (auto it : ch[node])
    if (max_dep[it] >= nxt)
      big.push_back(it);
  ref = 0;
  for (auto it : ch[node])
    if ((big.empty() || (big.size() == 1 && big[0] == it)) && highest <= max_dep[it] + 1)
      ref = add(ref, rec(it, covered - 1, highest - 1));
  for (int sec = highest; sec <= max_dep[node] + 1; sec++) 
    for (int val = sec; val <= sec + 1; val++) {
      int sz = ch[node].size();
      vector <int> suff(sz + 1);
      suff[sz] = 1;
      for (int i = sz - 1; i >= 0; i--)
        suff[i] = mul(suff[i + 1], sum(ch[node][i], nxt, min(val - 1, max_dep[ch[node][i]] + 1)));
      int pref = 1;
      for (int i = 0; i < sz; i++) {
        int tmp = mul(pref, suff[i + 1]);
        if (highest <= max_dep[ch[node][i]] + 1) 
          ref = add(ref, mul(rec(ch[node][i], max(covered - 1, K - sec), highest - 1), val == sec ? tmp : -tmp));
        pref = mul(pref, sum(ch[node][i], nxt, min(max(highest, val - 1), max_dep[ch[node][i]] + 1)));
      }
    }
  return ref;
}

int dfs(int x, int p) {
  int &ref = max_dep[x];
  for (auto it : adj[x])
    if (it != p) {
      ref = max(ref, dfs(it, x) + 1);
      ch[x].push_back(it);
    }
  return ref;
}

int solve() {
  memset(dp_rec, -1, sizeof dp_rec);
  memset(dp_sum, -1, sizeof dp_sum);
  dfs(1, 0);
  return sum(1, 0, 0);
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}