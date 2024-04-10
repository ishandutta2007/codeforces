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

const int maxn = 5005;
const int maxm = 1005;
int n, m;
map<string, int> ids;
int c[maxn][maxm];
int op[maxn], lop[maxn], rop[maxn];
char tmp[maxm];

int getId(const string &s) {
  if (s == "?") {
    return -1;
  }
  auto it = ids.find(s);
  if (it == ids.end()) {
    int id = sz(ids);
    ids[s] = id;
    return id;
  }
  return it->second;
}

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  ids.clear();
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    string name = tmp;
    int id = getId(name);
    assert(id == i);
    scanf("%s ", tmp);
    int ch = getchar();
    ungetc(ch, stdin);
    if (ch == '0' || ch == '1') {
      op[i] = -1;
      scanf("%s", tmp);
      for (int j = 0; j < m; j++) {
        c[i][j] = tmp[j] - '0';
      }
    } else {
      scanf("%s", tmp);
      string l = tmp;
      lop[i] = getId(l);
      scanf("%s", tmp);
      op[i] = (tmp[0] == 'A' ? 0 : (tmp[0] == 'O' ? 1 : 2));
      scanf("%s", tmp);
      string r = tmp;
      rop[i] = getId(r);
    }
  }
  return true;
}

int ans[2][maxm];
int a[maxn];

int getVal(int bit, int x) {
  for (int i = 0; i < n; i++) {
    if (op[i] == -1) {
      a[i] = c[i][bit];
    } else {
      int l = (lop[i] == -1 ? x : a[lop[i]]);
      int r = (rop[i] == -1 ? x : a[rop[i]]);
      if (op[i] == 0) {
        a[i] = (l & r);
      } else if (op[i] == 1) {
        a[i] = (l | r);
      } else {
        a[i] = (l ^ r);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    res += a[i];
  }
  return res;
}

void solve() {
  for (int bit = 0; bit < m; bit++) {
    int val[] = {getVal(bit, 0), getVal(bit, 1)};
    if (val[0] < val[1]) {
      ans[0][bit] = 0;
      ans[1][bit] = 1;
    } else if (val[1] < val[0]) {
      ans[0][bit] = 1;
      ans[1][bit] = 0;
    } else {
      ans[0][bit] = 0;
      ans[1][bit] = 0;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d", ans[i][j]);
    }
    printf("\n");
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