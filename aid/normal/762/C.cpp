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

const int maxn = (int) 1e5 + 5;
int n, m;
char tmp[maxn];
string s, t;

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  t = tmp;
  scanf("%s", tmp);
  s = tmp;
  n = sz(s);
  m = sz(t);
  return true;
}

int pref[maxn], suff[maxn];

void solve() {
  pref[0] = 0;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < m && t[j] != s[i]) {
      j++;
    }
    if (j < m) {
      j++;
    } else {
      j = inf;
    }
    pref[i + 1] = j;
  }
  suff[n] = m;
  for (int i = n - 1, j = m; i >= 0; i--) {
    while (j - 1 >= 0 && t[j - 1] != s[i]) {
      j--;
    }
    if (j > 0) {
      j--;
    } else {
      j = -inf;
    }
    suff[i] = j;
  }
  int res = n;
  int pos = 0;
  for (int i = 0, j = 0; i <= n; i++) {
    while (j < i || (j <= n && suff[j] < pref[i])) {
      j++;
    }
    if (j <= n) {
      if (j - i < res) {
        res = j - i;
        pos = i;
      }
    }
  }
  string ans = s.substr(0, pos) + s.substr(pos + res);
  if (ans.empty()) {
    ans = "-";
  }
  printf("%s\n", ans.c_str());
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