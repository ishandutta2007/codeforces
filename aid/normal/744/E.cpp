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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 35, maxlen = (int) 1e5 + 5;
int n;
string s[maxn];
char tmp[maxlen];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    s[i] = tmp;
  }
  return true;
}

int z[2 * maxlen];

void getz(const string &s) {
  int n = sz(s);
  z[0] = 0;
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i < r && i + z[i - l] < r) {
      z[i] = z[i - l];
    } else {
      l = i;
      r = max(r, i);
      while (r < n && s[r] == s[r - l]) {
        r++;
      }
      z[i] = r - l;
    }
  }
}

vector<int> g[maxlen];
int ss[maxn];
int used[maxlen];

bool dfs(int v) {
  used[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[u] == 2) {
      continue;
    }
    if (used[u] == 1 || dfs(u)) {
      return true;
    }
  }
  used[v] = 2;
  return false;
}

bool check(int l, int r) {
  ss[l] = 1;
  for (int i = l; i < r; i++) {
    ss[i + 1] = ss[i] + sz(s[i]) - 1;
  }
  for (int i = 0; i < ss[r]; i++) {
    g[i].clear();
  }
  for (int i = l; i < r; i++) {
    for (int j = l; j < r; j++) {
      getz(s[i] + "#" + s[j]);
      for (int pos = 0; pos < sz(s[j]); pos++) {
        int v = (pos ? ss[j] + pos - 1 : 0);
        if (z[sz(s[i]) + 1 + pos] == sz(s[i])) {
          if (pos + z[sz(s[i]) + 1 + pos] == sz(s[j])) {
            if (v) {
              int u = 0;
              g[v].push_back(u);
            }
          } else {
            int u = ss[j] + pos + sz(s[i]) - 1;
            g[v].push_back(u);
          }
        } else {
          if (pos + z[sz(s[i]) + 1 + pos] == sz(s[j])) {
            int u = ss[i] + z[sz(s[i]) + 1 + pos] - 1;
            g[v].push_back(u);
          }
        }
      }
    }
  }
  for (int i = 0; i < ss[r]; i++) {
    used[i] = 0;
  }
  for (int i = 0; i < ss[r]; i++) {
    if (!used[i] && dfs(i)) {
      return false;
    }
  }
  return true;
}

void solve() {
  int res = 0;
  for (int l = 0, r = 0; l < n; l++) {
    while (r < n && check(l, r + 1)) {
      r++;
    }
    res += r - l;
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