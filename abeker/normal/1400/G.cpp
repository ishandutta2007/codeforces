#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
const int MOD = 998244353;

class SosDp {
  int len;
  vector <vector <int>> dp;
public:
  SosDp(int _len) {
    len = _len;
    dp.resize(len + 1);
    for (auto &it : dp)
      it.resize(1 << len);
  }
  SosDp(){}
  void add(int x) {
    dp[len][x]++;
  }
  void build() {
    for (int i = len - 1; i >= 0; i--) 
      for (int j = 0; j < 1 << len; j++) {
        dp[i][j] = dp[i + 1][j];
        if (j >> i & 1)
          dp[i][j] += dp[i + 1][j ^ 1 << i];
      }
    dp.resize(1);
  }
  int getDp(int mask) const {
    return dp[0][mask];
  }
};

class Component {
  vector <SosDp> counter;
  unordered_map <int, int> idx;
public:
  Component(const vector <int> &nodes, vector <int> *graph) {
    int sz = nodes.size();
    for (int i = 0; i < sz; i++)
      idx[nodes[i]] = i;
    vector <int> neigh(sz);
    for (int i = 0; i < sz; i++)
      for (auto it : graph[nodes[i]])
        neigh[i] |= 1 << idx[it];
    counter.resize(sz + 1, SosDp(sz));
    for (int i = 0; i < 1 << sz; i++) {
      bool indep = true;
      for (int j = 0; j < sz; j++)
        if (i >> j & 1 && i & neigh[j]) {
          indep = false;
          break;
        }
      if (indep)
        counter[__builtin_popcount(i)].add(i);
    }
    for (int i = 0; i <= sz; i++)
      counter[i].build();
  }
  Component(){}
  vector <int> getPoly(int k, int *lo, int *hi) const {
    int mask = 0;
    for (auto it : idx)
      if (k >= lo[it.first] && k < hi[it.first])
        mask |= 1 << it.second;
    vector <int> res;
    int sz = __builtin_popcount(mask);
    for (int i = 0; i <= sz; i++)
      res.push_back(counter[i].getDp(mask));
    return res;
  }
};

int N, M;
int contain[MAXN];
int l[MAXN], r[MAXN];
int fact[MAXN], inv[MAXN];
vector <Component> comps;
vector <int> adj[MAXN];
vector <int> curr;
bool bio[MAXN];

void load() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) {
    scanf("%d%d", l + i, r + i);
    contain[l[i]]++;
    contain[++r[i]]--;
  }
  while (M--) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a); 
  }
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

int pot(int x, int y) {
  int res = 1;
  for (; y; y /= 2) {
    if (y % 2)
      res = mul(res, x);
    x = mul(x, x);
  }
  return res;
}

int choose(int n, int k) {
  if (k < 0 || n < k)
    return 0;
  return mul(fact[n], mul(inv[k], inv[n - k]));
}

void dfs(int x) {
  bio[x] = true;
  curr.push_back(x);
  for (auto it : adj[x])
    if (!bio[it])
      dfs(it);
}

vector <int> mult(const vector <int> &p, const vector <int> &q) {
  int deg_p = (int)p.size() - 1;
  int deg_q = (int)q.size() - 1;
  vector <int> r(deg_p + deg_q + 1);
  for (int i = 0; i <= deg_p; i++)
    for (int j = 0; j <= deg_q; j++)
      r[i + j] = add(r[i + j], mul(p[i], q[j]));
  return r;
}

int calc(int k) {
  int cnt = 0;
  vector <int> tot{1};
  for (auto it : comps) {
    vector <int> tmp = it.getPoly(k, l, r); 
    cnt += (int)tmp.size() - 1;
    tot = mult(tot, tmp);
  }
  int res = 0;
  for (int i = 0; i < tot.size(); i++)
    res = add(res, mul(tot[i], choose(contain[k] - cnt, k - i)));
  return res;
}

int solve() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = mul(fact[i - 1], i);
    inv[i] = pot(fact[i], MOD - 2);
    contain[i] += contain[i - 1];
    if (!adj[i].empty() && !bio[i]) {
      curr.clear();
      dfs(i);
      comps.push_back(Component(curr, adj));
    }
  }
  
  int sol = 0;
  for (int i = 1; i <= N; i++)
    sol = add(sol, calc(i));
  
  return sol;
}

int main() {
  load();
  printf("%d\n", solve());
  return 0;
}