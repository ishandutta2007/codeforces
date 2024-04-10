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

const int maxn = (int) 1e5 + 5;
int n;
long long s;

bool read() {
  if (scanf("%d%lld", &n, &s) < 2) {
    return false;
  }
  return true;
}

long long get(int d) {
  long long res = 1;
  int dep = 1;
  long long k = d;
  int rem = n - 1;
  while (rem) {
    dep++;
    int take = min((long long) rem, k);
    res += (long long) take * dep;
    k = (long long) take * d;
    rem -= take;
  }
  return res;
}

int cnt[maxn];
int p[maxn];
vector<int> vs[maxn];
vector<int> g[maxn];

void solve() {
  if (s < 2 * n - 1 || s > (long long) n * (n + 1) / 2) {
    printf("No\n");
    return;
  }
  int l = 0, r = n - 1;
  while (l < r - 1) {
    int m = (l + r) / 2;
    if (get(m) <= s) {
      r = m;
    } else {
      l = m;
    }
  }
  int d = r;
  for (int i = 0; i <= n; i++) {
    cnt[i] = 0;
  }
  {
    s -= 1;
    cnt[1] = 1;
    int dep = 1;
    long long k = d;
    int rem = n - 1;
    while (rem) {
      dep++;
      int take = min((long long) rem, k);
      s -= (long long) take * dep;
      cnt[dep] = take;
      k = (long long) take * d;
      rem -= take;
    }
    for (int i = n; i > 0 && s; i--) {
      while (cnt[i] > 1 && s) {
        int j = min((long long) dep + 1, i + s);
        cnt[i]--;
        cnt[j]++;
        dep = max(dep, j);
        s -= (j - i);
      }
    }
  }
  {
    int cur = 0;
    for (int i = 0; i <= n; i++) {
      vs[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      while (cnt[i]) {
        vs[i].push_back(cur++);
        cnt[i]--;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  p[0] = -1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < sz(vs[i]); j++) {
      int v = vs[i][j];
      while (sz(g[vs[i - 1].back()]) >= d) {
        vs[i - 1].pop_back();
      }
      int u = vs[i - 1].back();
      g[u].push_back(v);
      p[v] = u;
    }
  }
  printf("Yes\n");
  for (int i = 1; i < n; i++) {
    printf("%d ", p[i] + 1);
  }
  printf("\n");
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