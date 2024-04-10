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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = 5005;
int n;
string s;
char tmp[maxn];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

const int sigma = 26;
vector<int> ps[sigma];
int cnt[sigma];

void solve() {
  s = s + s;
  for (int i = 0; i < sigma; i++) {
    ps[i].clear();
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    ps[s[i] - 'a'].push_back(i);
  }
  int res = 0;
  for (int c = 0; c < sigma; c++) {
    if (ps[c].empty()) {
      continue;
    }
    if (sz(ps[c]) == 1) {
      res++;
      continue;
    }
    int cur = 0;
    for (int i = 1; i < n; i++) {
      for (int it = 0; it < sz(ps[c]); it++) {
        int pos = ps[c][it];
        cnt[s[pos + i] - 'a']++;
      }
      int x = 0;
      for (int it = 0; it < sz(ps[c]); it++) {
        int pos = ps[c][it];
        if (cnt[s[pos + i] - 'a'] == 1) {
          x++;
        }
      }
      cur = max(cur, x);
      for (int it = 0; it < sz(ps[c]); it++) {
        int pos = ps[c][it];
        cnt[s[pos + i] - 'a']--;
      }
    }
    res += cur;
  }
  printf("%.12f\n", (double) res / n);
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