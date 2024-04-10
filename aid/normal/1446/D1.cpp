#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }
  return true;
}

const int K = 500;
vector<int> as[maxn];
vector<int> big;
int r[maxn];
int ps[maxn][2];
int cnt[maxn];
set<pair<int, int>, greater<pair<int, int>>> st;
vector<int> qs[maxn];
vector<pair<int, int>> evs, tmp0, tmp1;
int bals[2 * maxn];
int used[2 * maxn];
int curu;

void updatePs(int i) {
  int col = a[i];
  for (int k = 1; k < K && k <= cnt[col]; ++k) {
    int p = as[col][sz(as[col]) - cnt[col] + k - 1];
    if (ps[k][0] != -1 && a[ps[k][0]] == col) {
      ps[k][0] = p;
    } else if (ps[k][1] != -1 && a[ps[k][1]] == col) {
      ps[k][1] = p;
    } else if (ps[k][1] == -1 || p < ps[k][1]) {
      ps[k][1] = p;
    }
    if (ps[k][0] == -1 || (ps[k][1] != -1 && ps[k][1] < ps[k][0])) {
      swap(ps[k][0], ps[k][1]);
    }
  }
}

void solve() {
  for (int i = 0; i < maxn; ++i) {
    as[i].clear();
    qs[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    as[a[i]].push_back(i);
  }
  big.clear();
  for (int i = 0; i < maxn; ++i) {
    if (sz(as[i]) >= K) {
      big.push_back(i);
    }
  }
  for (int i = 0; i < maxn; ++i) {
    for (int j = 0; j < 2; ++j) {
      ps[i][j] = -1;
    }
  }
  for (int i = 0; i < maxn; ++i) {
    cnt[i] = 0;
  }
  st.clear();
  for (int i = n - 1; i >= 0; --i) {
    if (cnt[a[i]] > 0) {
      st.erase(make_pair(cnt[a[i]], a[i]));
    }
    ++cnt[a[i]];
    st.insert(make_pair(cnt[a[i]], a[i]));
    updatePs(i);
    int col = st.begin()->second;
    if (cnt[col] >= K) {
      qs[col].push_back(i);
    }
    r[i] = -1;
    for (int k = min(cnt[col], K - 1); k >= 1; --k) {
      int p = (k + 1 <= cnt[col] ? as[col][sz(as[col]) - cnt[col] + k] : n);
      if (ps[k][1] != -1 && ps[k][1] < p) {
        r[i] = p;
        break;
      }
    }
  }
  for (int bi = 0; bi < sz(big); ++bi) {
    int ci = big[bi];
    if (qs[ci].empty()) {
      continue;
    }
    reverse(qs[ci].begin(), qs[ci].end());
    for (int bj = 0; bj < sz(big); ++bj) {
      if (bj == bi) {
        continue;
      }
      int cj = big[bj];
      tmp0.clear();
      for (int i = 0; i < sz(as[ci]); ++i) {
        tmp0.push_back(make_pair(as[ci][i], 1));
      }
      tmp1.clear();
      for (int i = 0; i < sz(as[cj]); ++i) {
        tmp1.push_back(make_pair(as[cj][i], -1));
      }
      evs.clear();
      evs.resize(sz(tmp0) + sz(tmp1));
      merge(tmp0.begin(), tmp0.end(), tmp1.begin(), tmp1.end(), evs.begin());
      tmp0 = evs;
      tmp1.clear();
      for (int i = 0; i < sz(qs[ci]); ++i) {
        tmp1.push_back(make_pair(qs[ci][i], -inf));
      }
      evs.clear();
      evs.resize(sz(tmp0) + sz(tmp1));
      merge(tmp0.begin(), tmp0.end(), tmp1.begin(), tmp1.end(), evs.begin());
      ++curu;
      int bal = maxn;
      used[bal] = curu;
      bals[bal] = n;
      for (int i = sz(evs) - 1; i >= 0; --i) {
        if (evs[i].second == -inf) {
          if (used[bal] == curu) {
            r[evs[i].first] = max(r[evs[i].first], bals[bal]);
          }
        } else {
          bal += evs[i].second;
          if (used[bal] != curu) {
            bals[bal] = evs[i].first;
            used[bal] = curu;
          }
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res = max(res, r[i] - i);
    eprintf("%d: %d\n", i, r[i]);
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}