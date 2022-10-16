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

const int maxn = 2005;
int n;
int deg[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &deg[i]);
  }
  return true;
}

vector<pair<int, int>> es;

void solve() {
  es.clear();
  int s = 0, odd = 0;;
  for (int i = 0; i < n; i++) {
    s += deg[i];
    odd += (deg[i] & 1);
  }
  if (s & 1 || s < 2 * n - 2 || s > 3 * n - 3 - odd / 2) {
    printf("-1\n");
    return;
  }
  while (true) {
    int leaf = -1;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 1) {
        leaf = i;
        break;
      }
    }
    if (leaf != -1) {
      bool found = false;
      for (int i = 0; i < n; i++) {
        if (deg[i] > 1 && (deg[i] & 1)) {
          es.push_back(make_pair(leaf, i));
          deg[leaf]--;
          deg[i]--;
          s -= 2;
          found = true;
          break;
        }
      }
      if (found) {
        continue;
      }
      for (int i = 0; i < n; i++) {
        if (deg[i] > 2) {
          es.push_back(make_pair(leaf, i));
          deg[leaf]--;
          deg[i]--;
          s -= 2;
          found = true;
          break;
        }
      }
      if (found) {
        continue;
      }
      for (int i = 0; i < n; i++) {
        if (deg[i] > 1) {
          es.push_back(make_pair(leaf, i));
          deg[leaf]--;
          deg[i]--;
          s -= 2;
          found = true;
          break;
        }
      }
      if (found) {
        continue;
      }
      //assert(s == 2);
      if (s != 2) {
        printf("-1\n");
        return;
      }
      for (int i = 0; i < n; i++) {
        if (deg[i] == 1 && i != leaf) {
          es.push_back(make_pair(leaf, i));
          deg[leaf]--;
          deg[i]--;
          s -= 2;
          found = true;
          break;
        }
      }
      assert(found);
      break;
    }
    int v = -1;
    for (int i = 0; i < n; i++) {
      if (deg[i] > 2) {
        v = i;
        break;
      }
    }
    if (v == -1) {
      vector<int> c;
      for (int i = 0; i < n; i++) {
        assert(deg[i] == 0 || deg[i] == 2);
        if (deg[i] == 2) {
          c.push_back(i);
        }
      }
      //assert(sz(c) >= 3);
      if (sz(c) < 3) {
        printf("-1\n");
        return;
      }
      for (int i = 0; i < sz(c); i++) {
        int v = c[i], u = c[(i + 1) % sz(c)];
        es.push_back(make_pair(v, u));
        deg[v]--;
        deg[u]--;
        s -= 2;
      }
      break;
    }
    int c[2] = {-1, -1};
    for (int i = 0; i < n; i++) {
      if (deg[i] == 2) {
        if (c[0] == -1) {
          c[0] = i;
        } else {
          c[1] = i;
          break;
        }
      }
    }
    //assert(c[1] != -1);
    if (c[1] == -1) {
      printf("-1\n");
      return;
    }
    es.push_back(make_pair(c[0], c[1]));
    es.push_back(make_pair(c[1], v));
    es.push_back(make_pair(v, c[0]));
    deg[c[0]] -= 2;
    deg[c[1]] -= 2;
    deg[v] -= 2;
    s -= 6;
  }
  printf("%d\n", sz(es));
  for (int i = 0; i < sz(es); i++) {
    printf("2 %d %d\n", es[i].first + 1, es[i].second + 1);
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