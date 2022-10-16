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

const int maxn = (int) 2e5 + 5;
int n, q;
char s[maxn];

int read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  scanf("%s", s);
  return true;
}

const int k = 3;
const string t = "201";

struct node {
  int dp[k][k];
  int dp6[k];
  int dp67[k];
  int c6;
  int c7;
};

node st[4 * maxn];

void recalc(node &v, const node &vl, const node &vr) {
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      v.dp[i][j] = inf;
      if (j < i) {
        continue;
      }
      for (int l = i; l <= j; l++) {
        v.dp[i][j] = min(v.dp[i][j], vl.dp[i][l] + vr.dp[l][j]);
      }
    }
  }
  for (int i = 0; i < k; i++) {
    v.dp6[i] = min(inf, vl.dp6[i] + vr.c6);
    for (int j = i; j < k; j++) {
      v.dp6[i] = min(v.dp6[i], vl.dp[i][j] + vr.dp6[j]);
    }
  }
  for (int i = 0; i < k; i++) {
    v.dp67[i] = min(inf, vl.dp67[i] + vr.c6);
    if (vr.c7) {
      v.dp67[i] = min(v.dp67[i], vl.dp6[i] + vr.c6);
    }
    for (int j = i; j < k; j++) {
      v.dp67[i] = min(v.dp67[i], vl.dp[i][j] + vr.dp67[j]);
    }
  }
  v.c6 = vl.c6 + vr.c6;
  v.c7 = vl.c7 + vr.c7;
}

void buildst(int v, int tl, int tr) {
  if (tl == tr - 1) {
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        st[v].dp[i][j] = inf;
      }
      st[v].dp6[i] = inf;
      st[v].dp67[i] = inf;
      if (s[tl] == t[i]) {
        st[v].dp[i][i] = 1;
        if (i + 1 < k) {
          st[v].dp[i][i + 1] = 0;
        } else {
          st[v].dp6[i] = 0;
        }
      } else {
        st[v].dp[i][i] = 0;
      }
    }
    st[v].c6 = (s[tl] == '6');
    st[v].c7 = (s[tl] == '7');
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  recalc(st[v], st[2 * v], st[2 * v + 1]);
}

node get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v];
  }
  int tm = (tl + tr) / 2;
  if (r <= tm) {
    return get(2 * v, tl, tm, l, r);
  }
  if (l >= tm) {
    return get(2 * v + 1, tm, tr, l, r);
  }
  node vl = get(2 * v, tl, tm, l, min(r, tm)), vr = get(2 * v + 1, tm, tr, max(l, tm), r);
  node res;
  recalc(res, vl, vr);
  return res;
}

void solve() {
  buildst(1, 0, n);
  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    int res = get(1, 0, n, l, r).dp67[0];
    if (res == inf) {
      res = -1;
    }
    printf("%d\n", res);
  }
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