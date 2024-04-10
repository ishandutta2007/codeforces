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
string s[maxn];
char tmp[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    s[i] = tmp;
  }
  return true;
}

bool check(const string &s) {
  int bal = 0;
  for (int i = 0; i < sz(s); i++) {
    bal += (s[i] == '(' ? 1 : -1);
    if (bal < 0) {
      return false;
    }
  }
  return true;
}

int cnt[maxn];

void solve() {
  memset(cnt, 0, sizeof(cnt));
  int res = 0;
  for (int it = 0; it < n; it++) {
    string t = s[it];
    int bal = 0;
    for (int i = 0; i < sz(t); i++) {
      bal += (t[i] == '(' ? 1 : -1);
    }
    if (bal < 0) {
      reverse(t.begin(), t.end());
      for (int i = 0; i < sz(t); i++) {
        if (t[i] == '(') {
          t[i] = ')';
        } else {
          t[i] = '(';
        }
      }
    }
    if (!check(t)) {
      continue;
    }
    if (bal == 0) {
      if (cnt[0]) {
        cnt[0]--;
        res++;
      } else {
        cnt[0]++;
      }
      continue;
    }
    if (bal > 0) {
      if (cnt[bal] < 0) {
        res++;
      }
      cnt[bal]++;
    } else {
      if (cnt[-bal] > 0) {
        res++;
      }
      cnt[-bal]--;
    }
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