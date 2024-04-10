#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1700000;
const int MOD = 1e9 + 7;
const ll P[] = {97, 1000003};

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

int pwr[2][N], inv[2][N];

void initHash() {
  for (int it = 0; it < 2; ++it) {
    pwr[it][0] = inv[it][0] = 1;
    ll INV_P = bigMod(P[it], -1);
    for (int i = 1; i < N; ++i) {
      pwr[it][i] = (ll) pwr[it][i - 1] * P[it] % MOD;
      inv[it][i] = (ll) inv[it][i - 1] * INV_P % MOD;
    }
  }
}

struct RangeHash {
  vector <int> h[2], rev[2];

  RangeHash (const string S, bool revFlag = 0) {
    for (int it = 0; it < 2; ++it) {
      h[it].resize(S.size() + 1, 0);
      for (int i = 0; i < S.size(); ++i) {
        h[it][i + 1] = (h[it][i] + (ll) pwr[it][i + 1] * (S[i] - 'a' + 1)) % MOD;
      }
      if (revFlag) {
        rev[it].resize(S.size() + 1, 0);
        for (int i = 0; i < S.size(); ++i) {
          rev[it][i + 1] = (rev[it][i] + (ll) inv[it][i + 1] * (S[i] - 'a' + 1)) % MOD;
        }
      }
    }
  }

  inline ll get (int l, int r) {
    if (l > r) return 0;
    ll one = (ll) (h[0][r + 1] - h[0][l]) * inv[0][l + 1] % MOD;
    ll two = (ll) (h[1][r + 1] - h[1][l]) * inv[1][l + 1] % MOD;
    if (one < 0) one += MOD; if (two < 0) two += MOD;
    return one << 31 | two;
  }

  inline ll getReverse (int l, int r) {
    if (l > r) return 0;
    ll one = (ll) (rev[0][r + 1] - rev[0][l]) * pwr[0][r + 1] % MOD;
    ll two = (ll) (rev[1][r + 1] - rev[1][l]) * pwr[1][r + 1] % MOD;
    if (one < 0) one += MOD; if (two < 0) two += MOD;
    return one << 31 | two;
  }
};

char tmp[N];
ll ans[N >> 4];
vector <ll> pf[69];
bitset <N + N> cnt;
vector <int> ind[69];
string big, cue[N >> 4];
int n, q, en[69], pos[N];
map <char, int> to[N + N];
int len[N + N], link[N + N], sz, last, id[N + N], dp[N + N];

inline void init() {
  len[0] = 0, link[0] = -1, sz = 1, last = 0, to[0].clear();
}

void feed (char c) {
  int cur = sz++, p = last;
  len[cur] = len[last] + 1, link[cur] = 0, to[cur].clear(), cnt[cur] = 1;
  while (~p and !to[p].count(c)) to[p][c] = cur, p = link[p];
  if (~p) {
    int q = to[p][c];
    if (len[q] - len[p] - 1) {
      int r = sz++;
      len[r] = len[p] + 1, to[r] = to[q], link[r] = link[q];
      while (~p and to[p][c] == q) to[p][c] = r, p = link[p];
      link[q] = link[cur] = r; 
    } else link[cur] = q;
  } last = cur;
}

int run (string &pat) {
  int u = 0;
  for (int i = 0; i < pat.size(); ++i) {
    if (!to[u].count(pat[i])) return 0;
    u = to[u][pat[i]];
  }
  return dp[u];
}

int main() {
  init();
  initHash();
  cin >> n >> q;
  scanf("%s", tmp);
  string s = tmp;
  scanf("%s", tmp);
  string t = tmp;
  int at = 0;
  big = s, en[0] = big.size();
  while (at < n and big.size() < 1000000) {
    big = big + t[at++] + big;
    en[at] = big.size();
  }
  for (int i = at; i < n; ++i) {
    ind[t[i] - 'a'].emplace_back(i);
  }
  for (int i = 0; i < 69; ++i) {
    if (ind[i].empty()) continue;
    pf[i].resize(ind[i].size() + 1, 0);
    for (int j = 0; j < ind[i].size(); ++j) {
      pf[i][j + 1] = (pf[i][j] + bigMod(2, MOD - 1 - ind[i][j])) % MOD;
    }
  }
  RangeHash bigHash(big);
  for (int idx = 0; idx < q; ++idx) {
    scanf("%d %s", pos + idx, tmp);
    cue[idx] = tmp;
    if (pos[idx] <= at) continue;
    RangeHash pat(cue[idx]);
    ll mul = bigMod(2, pos[idx] - 1);
    for (int i = 0; i < cue[idx].size(); ++i) {
      int ch = cue[idx][i] - 'a', tot = lower_bound(ind[ch].begin(), ind[ch].end(), pos[idx]) - ind[ch].begin();
      if (!tot) continue;
      if (pat.get(0, i - 1) == bigHash.get(big.size() - i, big.size() - 1) and pat.get(i + 1, cue[idx].size() - 1) == bigHash.get(0, (int) cue[idx].size() - i - 2)) {
        ans[idx] = (ans[idx] + mul * pf[ch][tot]) % MOD; 
      }
    }
  }
  for (int i = 0; i <= at; ++i) {
    for (int j = i ? en[i - 1] : 0; j < en[i]; ++j) feed(big[j]);
    for (int i = 0; i < sz; ++i) id[i] = i; 
    sort(id, id + sz, [] (int i, int j) {return len[i] > len[j];});
    for (int i = 0; i < sz; ++i) dp[i] = cnt[i];
    for (int i = 0; i < sz; ++i) if (~link[id[i]]) dp[link[id[i]]] += dp[id[i]];
    for (int j = 0; j < q; ++j) if (pos[j] == i) {
      ans[j] += run(cue[j]);
      if (ans[j] >= MOD) ans[j] -= MOD;
    }
  }
  for (int i = 0; i < q; ++i) if (pos[i] > at) {
    ans[i] = (ans[i] + run(cue[i]) * bigMod(2, pos[i] - at)) % MOD;
  }
  for (int i = 0; i < q; ++i) printf("%lld\n", ans[i]);
  return 0;
}