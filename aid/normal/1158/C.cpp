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

const int maxn = (int) 5e5 + 5;
int n;
int nxt[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &nxt[i]);
    if (nxt[i] != -1) {
      nxt[i]--;
    }
  }
  return true;
}

vector<int> g[maxn];
vector<int> st;
int used[maxn];
vector<int> p;
int q[maxn];

bool dfs(int v) {
  used[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (used[u] == 2) {
      continue;
    }
    if (used[u] == 1) {
      return false;
    }
    if (!dfs(u)) {
      return false;
    }
  }
  p.push_back(v);
  used[v] = 2;
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  st.clear();
  for (int i = n - 1; i >= 0; i--) {
    if (nxt[i] == -1) {
      st.push_back(i);
      continue;
    }
    while (!st.empty() && st.back() < nxt[i]) {
      g[st.back()].push_back(i);
      st.pop_back();
    }
    if (st.empty()) {
      if (nxt[i] != n) {
        printf("-1\n");
        return;
      }
    } else {
      if (st.back() > nxt[i]) {
        printf("-1\n");
        return;
      }
      g[i].push_back(nxt[i]);
    }
    st.push_back(i);
  }
  for (int i = 0; i < n; i++) {
    used[i] = 0;
  }
  p.clear();
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    if (!dfs(i)) {
      printf("-1\n");
      return;
    }
  }
  reverse(p.begin(), p.end());
  for (int i = 0; i < n; i++) {
    q[p[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", q[i] + 1);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}