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

const int maxn = (int) 1e5 + 5, maxdim = 60, mod = (int) 1e9 + 7;
int n, m;
int p2[maxdim];
vector< pair<int, long long> > g[maxn];

void precalc() {
  p2[0] = 1;
  for (int i = 1; i < maxdim; i++) {
    p2[i] = p2[i - 1] * 2 % mod;
  }
}

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    long long t;
    scanf("%d%d%lld", &v, &u, &t);
    v--;
    u--;
    g[v].push_back(make_pair(u, t));
    g[u].push_back(make_pair(v, t));
  }
  return true;
}

int used[maxn];
long long s[maxn];
int cnt[maxdim][2];
int zero[maxdim];
vector<long long> b;

int getDim() {
  for (int i = 0; i < maxdim; i++) {
    zero[i] = true;
  }
  int dim = 0;
  for (int i = 0; i < sz(b); i++) {
    if (!b[i]) {
      continue;
    }
    dim++;
    int bit = 0;
    while (!(b[i] & (1ll << (long long) bit))) {
      bit++;
    }
    for (int j = bit; j < maxdim; j++) {
      if (b[i] & (1ll << (long long) j)) {
        zero[j] = false;
      }
    }
    for (int j = i + 1; j < sz(b); j++) {
      if (b[j] & (1ll << (long long) bit)) {
        b[j] ^= b[i];
      }
    }
  }
  return dim;
}

int dfs(int v) {
  int res = 1;
  used[v] = true;
  for (int i = 0; i < maxdim; i++) {
    if (s[v] & (1ll << (long long) i)) {
      cnt[i][1]++;
    } else {
      cnt[i][0]++;
    }
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first;
    long long t = g[v][i].second;
    if (used[u]) {
      b.push_back(s[u] ^ s[v] ^ t);
    } else {
      s[u] = (s[v] ^ t);
      res += dfs(u);
    }
  }
  return res;
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  int ans = 0;
  for (int r = 0; r < n; r++) {
    if (!used[r]) {
      s[r] = 0;
      b.clear();
      for (int i = 0; i < maxdim; i++) {
        cnt[i][0] = 0;
        cnt[i][1] = 0;
      }
      int cs = dfs(r);
      int k = getDim();
      for (int i = 0; i < maxdim; i++) {
        int add;
        if (zero[i]) {
          add = (long long) p2[k] * cnt[i][0] % mod * cnt[i][1] % mod;
        } else {
          add = p2[k - 1] * (((long long) cs * (cs - 1) / 2) % mod) % mod;
        }
        add = (long long)add * p2[i] % mod;
        ans += add;
        if (ans >= mod) {
          ans -= mod;
        }
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  precalc();
#ifdef LOCAL
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