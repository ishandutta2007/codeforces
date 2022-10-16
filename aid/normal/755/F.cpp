#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e6 + 5;
int n, k;
int p[maxn];

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  return true;
}

int used[maxn];
vector<int> c;
bitset<maxn> dp;

void getMin() {
  map<int, int> mpc;
  for (int i = 0; i < sz(c); i++) {
    mpc[c[i]]++;
  }
  for (auto it = mpc.begin(); it != mpc.end(); it++) {
    int len = it->first, cnt = it->second;
    int nlen = 2 * len, ncnt = (cnt - 1) / 2;
    if (ncnt) {
      it->second -= 2 * ncnt;
      mpc[nlen] += ncnt;
    }
  }
  dp.reset();
  dp[0] = true;
  for (auto it = mpc.begin(); it != mpc.end(); it++) {
    int len = it->first, cnt = it->second;
    for (int it = 0; it < cnt; it++) {
      dp = (dp | (dp << len));
    }
  }
  int res = (dp[k] ? k : k + 1);
  printf("%d ", res);
}

void getMax() {
  int res = 0;
  int cur = k;
  for (int i = 0; i < sz(c) && cur; i++) {
    int x = min(cur, c[i] / 2);
    cur -= x;
    res += 2 * x;
  }
  for (int i = 0; i < sz(c) && cur; i++) {
    if (c[i] & 1) {
      cur--;
      res++;
    }
  }
  printf("%d\n", res);
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  c.clear();
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    int v = i, len = 0;
    while (!used[v]) {
      used[v] = true;
      len++;
      v = p[v];
    }
    c.push_back(len);
  }
  getMin();
  getMax();
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}