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

const int maxn = (int) 1e6 + 5;
char tmp[maxn];
string s, t;

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  scanf("%s", tmp);
  t = tmp;
  return true;
}

const int sigma = 26;
int cnt[sigma];
vector<int> qs;

void solve() {
  for (int i = 0; i < sigma; i++) {
    cnt[i] = 0;
  }
  qs.clear();
  for (int i = 0; i < sz(s); i++) {
    if (s[i] == '?') {
      qs.push_back(i);
    } else {
      cnt[s[i] - 'a']++;
    }
  }
  while (true) {
    bool ok = true;
    for (int i = 0; i < sz(t); i++) {
      if (cnt[t[i] - 'a']) {
        cnt[t[i] - 'a']--;
      } else if (!qs.empty()) {
        s[qs.back()] = t[i];
        qs.pop_back();
      } else {
        ok = false;
      }
    }
    if (!ok) {
      break;
    }
  }
  printf("%s\n", s.c_str());
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