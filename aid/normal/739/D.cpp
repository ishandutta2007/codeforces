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

const int maxn = 305;
int n;
int p[maxn], c[maxn];

void readInt(int &res) {
  scanf(" ");
  int ch = getchar();
  if (ch == '?') {
    res = -1;
    return;
  }
  ungetc(ch, stdin);
  scanf("%d", &res);
}

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    readInt(p[i]);
    readInt(c[i]);
  }
  return true;
}

bool eq(int a, int b) {
  return a == b || a == -1 || b == -1;
}

int cnt[maxn];
int needc[maxn];
int maxpc[maxn];
int used[maxn];
int q[maxn];
vector<int> g[maxn];

bool dfs(int v, int col) {
  used[v] = col;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (q[u] == -1) {
      q[u] = v;
      return true;
    }
  }
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[q[u]] != col && dfs(q[u], col)) {
      q[u] = v;
      return true;
    }
  }
  return false;
}

vector<int> vs[maxn];
int ans[maxn];

void getAns() {
  for (int i = 0; i < n; i++) {
    ans[i] = -1;
  }
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i < n; i++) {
      vs[i].clear();
    }
    for (int i = 0; i < n; i++) {
      if (c[i] == len) {
        vs[p[i]].push_back(i);
      }
    }
    assert(!(sz(vs[0]) % len));
    for (int i = 0; i < sz(vs[0]); i += len) {
      for (int j = 0; j < len; j++) {
        ans[vs[0][i + j]] = (j + 1 < len ? vs[0][i + j + 1] : vs[0][i]);
      }
    }
    for (int i = 1; i < n; i++) {
      if (vs[i].empty()) {
        break;
      }
      for (int j = 0; j < sz(vs[i]); j++) {
        ans[vs[i][j]] = vs[i - 1][0];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    assert(ans[i] != -1);
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
}

void solve() {
  int maxp = 0;
  for (int i = 0; i < n; i++) {
    maxp = max(maxp, p[i]);
  }
  for (int maxc = 1; maxc <= n; maxc++) {
    for (int i = 1; i <= n; i++) {
      cnt[i] = 0;
      needc[i] = false;
      maxpc[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      if (p[i] == 0 && c[i] != -1) {
        cnt[c[i]]++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (c[i] != -1) {
        needc[c[i]] = true;
        maxpc[c[i]] = max(maxpc[c[i]], p[i]);
      }
    }
    needc[maxc] = true;
    maxpc[maxc] = maxp;
    vector< pair<int, int> > need;
    for (int i = 1; i <= n; i++) {
      if (needc[i]) {
        int cycle = (cnt[i] ? (i - cnt[i] % i) % i : i);
        for (int j = 0; j < cycle; j++) {
          need.push_back(make_pair(0, i));
        }
        for (int j = 1; j <= maxpc[i]; j++) {
          need.push_back(make_pair(j, i));
        }
      }
    }
    if (sz(need) > n) {
      continue;
    }
    for (int i = 0; i < sz(need); i++) {
      g[i].clear();
      used[i] = -1;
    }
    for (int i = 0; i < n; i++) {
      q[i] = -1;
    }
    for (int i = 0; i < sz(need); i++) {
      for (int j = 0; j < n; j++) {
        if (p[j] == 0 && c[j] != -1) {
          continue;
        }
        if (eq(need[i].first, p[j]) && eq(need[i].second, c[j])) {
          g[i].push_back(j);
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < sz(need); i++) {
      if (!dfs(i, i)) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (q[i] != -1) {
        p[i] = need[q[i]].first;
        c[i] = need[q[i]].second;
      } else {
        if (p[i] == -1) {
          if (c[i] == -1) {
            p[i] = 0;
            c[i] = 1;
          } else {
            p[i] = 1;
          }
        } else {
          if (c[i] == -1) {
            if (p[i]) {
              c[i] = maxc;
            } else {
              c[i] = 1;
            }
          }
        }
      }
    }
    getAns();
    return;
  }
  printf("-1\n");
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