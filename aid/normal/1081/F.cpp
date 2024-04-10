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

const int maxn = 305;
int n, t;

bool read() {
  if (scanf("%d%d", &n, &t) < 2) {
    return false;
  }
  return true;
}

int ask(int l, int r) {
  printf("? %d %d\n", l + 1, r);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}

int pref[maxn], suff[maxn];

void solve() {
  if (n & 1) {
    pref[0] = 0;
    for (int i = 2; i < n; i += 2) {
      while (true) {
        int val = ask(0, i);
        if (val == n - t) {
          ask(0, n);
          continue;
        }
        int x = (t + i - val) / 2;
        pref[i] = x;
        while (ask(0, i) == n - val) {
          ask(0, n);
        }
        break;
      }
    }
    pref[n] = t;
    suff[n] = 0;
    for (int i = 2; i < n; i += 2) {
      while (true) {
        int val = ask(n - i, n);
        if (val == n - t) {
          ask(0, n);
          continue;
        }
        int x = (t + i - val) / 2;
        suff[n - i] = x;
        while (ask(n - i, n) == n - val) {
          ask(0, n);
        }
        break;
      }
    }
    suff[0] = t;
    string ans;
    for (int i = 0; i < n; i++) {
      int val;
      if (i & 1) {
        val = pref[i + 1] + suff[i] - t;
      } else {
        val = t - suff[i + 1] - pref[i];
      }
      ans += (char) ('0' + val);
    }
    printf("! %s\n", ans.c_str());
    fflush(stdout);
    return;
  }
  pref[0] = 0;
  for (int i = 1; i < n; i += 2) {
    while (true) {
      int val = ask(0, i);
      if (val == n - t) {
        ask(0, n);
        continue;
      }
      int x = (t + i - val) / 2;
      pref[i] = x;
      while (ask(0, i) == n - val) {
        ask(0, n);
      }
      break;
    }
  }
  pref[n] = t;
  bool inv = false;
  for (int i = n - 2; i > 0; i -= 2) {
    while (true) {
      int val = ask(1, i);
      if ((val & 1) != (t & 1)) {
        while (ask(1, n) == n - val) {
          ask(0, n);
        }
        continue;
      }
      int x = (t + i - val) / 2;
      pref[i] = (inv ? i - x : x);
      inv = !inv;
      t = val;
      break;
    }
  }
  string ans;
  for (int i = 0; i < n; i++) {
    int val = pref[i + 1] - pref[i];
    ans += (char) ('0' + val);
  }
  printf("! %s\n", ans.c_str());
  fflush(stdout);
}

int main() {
  precalc();
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}