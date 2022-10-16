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

const int maxn = 1005;
char tmp[maxn * maxn];
int n, l, k;
string s;

bool read() {
  if (scanf("%d%d%d", &n, &l, &k) < 3) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

const int sigma = 26;
int cnt[sigma];
char ans[maxn][maxn];

void solve() {
  for (int i = 0; i < sigma; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < sz(s); i++) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l; j++) {
      ans[i][j] = ' ';
    }
  }
  int p = 0;
  int pos = 0;
  for (int i = 0; i < l; i++) {
    for (int j = pos; j < k; j++) {
      while (!cnt[p]) {
        p++;
      }
      ans[j][i] = (char) ('a' + p);
      cnt[p]--;
    }
    while (ans[pos][i] != ans[k - 1][i]) {
      pos++;
    }
  }
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < n; j++) {
      if (ans[j][i] != ' ') {
        continue;
      }
      while (!cnt[p]) {
        p++;
      }
      ans[j][i] = (char) ('a' + p);
      cnt[p]--;
    }
  }
  for (int i = 0; i < n; i++) {
    ans[i][l] = 0;
    printf("%s\n", ans[i]);
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