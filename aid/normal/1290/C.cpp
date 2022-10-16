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

const int maxn = (int) 3e5 + 5;
char tmp[maxn];
int n, k;
string s;
vector<int> who[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  for (int i = 0; i < n; i++) {
    who[i].clear();
  }
  for (int i = 0; i < k; i++) {
    int l;
    scanf("%d", &l);
    for (int j = 0; j < l; j++) {
      int v;
      scanf("%d", &v);
      v--;
      who[v].push_back(i);
    }
  }
  return true;
}

#define fixed ffffffffff

int p[maxn], pe[maxn];
int ts[maxn][2], col[maxn], fixed[maxn];
int res;

pair<int, int> get(int x) {
  if (p[x] == x) {
    return make_pair(x, 0);
  }
  auto q = get(p[x]);
  q.second ^= pe[x];
  p[x] = q.first;
  pe[x] = q.second;
  return q;
}

void del(int x) {
  if (!fixed[x]) {
    res -= min(ts[x][0], ts[x][1]);
  } else {
    res -= ts[x][1];
  }
}

void add(int x) {
  if (!fixed[x]) {
    res += min(ts[x][0], ts[x][1]);
  } else {
    res += ts[x][1];
  }
}

void fix(int x, int c) {
  auto q = get(x);
  x = q.first;
  c ^= q.second;
  del(x);
  if (col[x] != c) {
    col[x] = c;
    swap(ts[x][0], ts[x][1]);
  }
  fixed[x] = true;
  add(x);
}

void unite(int x, int y, int w) {
  auto qx = get(x), qy = get(y);
  x = qx.first;
  y = qy.first;
  w ^= (qx.second ^ qy.second);
  if (x == y) {
    return;
  }
  if (ts[x][0] + ts[x][1] < ts[y][0] + ts[y][1]) {
    swap(x, y);
  }
  if (fixed[y]) {
    fix(x, (col[y] ^ w));
  }
  if ((col[x] ^ col[y]) != w) {
    fix(y, (col[x] ^ w));
  }
  del(x);
  del(y);
  p[y] = x;
  pe[y] = w;
  ts[x][0] += ts[y][0];
  ts[x][1] += ts[y][1];
  add(x);
}

void solve() {
  for (int i = 0; i < k; i++) {
    p[i] = i;
    pe[i] = 0;
    ts[i][0] = 1;
    ts[i][1] = 0;
    col[i] = 0;
    fixed[i] = false;
  }
  res = 0;
  for (int i = 0; i < n; i++) {
    assert(sz(who[i]) <= 2);
    if (sz(who[i]) == 1) {
      fix(who[i][0], !(s[i] - '0'));
    } else if (sz(who[i]) == 2) {
      unite(who[i][0], who[i][1], !(s[i] - '0'));
    }
    printf("%d\n", res);
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