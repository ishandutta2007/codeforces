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
int n, m;
vector<int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back((u - v + n) % n);
    g[u].push_back((v - u + n) % n);
  }
  return true;
}

pair<vector<int>, int> tosort[maxn];
int a[maxn];
int cs;
int pr[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    sort(g[i].begin(), g[i].end());
    tosort[i] = make_pair(g[i], i);
  }
  sort(tosort, tosort + n);
  cs = 0;
  for (int j = 0; j < n;) {
    int i = j;
    while (j < n && tosort[j].first == tosort[i].first) {
      j++;
    }
    for (int k = i; k < j; k++) {
      int id = tosort[k].second;
      a[id] = cs;
    }
    cs++;
  }
  pr[0] = -1;
  for (int i = 0; i < n; i++) {
    auto &cur = pr[i + 1];
    for (cur = pr[i]; cur >= 0 && a[i] != a[cur]; cur = pr[cur]) ;
    cur++;
  }
  int per = n - pr[n];
  if (n % per || per >= n) {
    printf("No\n");
    return;
  }
  printf("Yes\n");
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