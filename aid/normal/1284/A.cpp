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

const int maxn = 25;
char tmp[maxn];
int n, m;
string s[maxn], t[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    s[i] = tmp;
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", tmp);
    t[i] = tmp;
  }
  return true;
}

string ans[maxn * maxn];

void solve() {
  for (int i = 0; i < n * m; i++) {
    ans[i] = s[i % n] + t[i % m];
  }
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    int x;
    scanf("%d", &x);
    x--;
    x %= (n * m);
    printf("%s\n", ans[x].c_str());
  }
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