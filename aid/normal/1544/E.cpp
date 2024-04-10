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

const int maxn = (int) 1e5 + 5;
char tmp[maxn];
int n;
string s;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

const int sigma = 26;
int cnt[sigma];

void solve() {
  for (int i = 0; i < sigma; ++i) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i] - 'a'];
  }
  int a = 0;
  while (!cnt[a]) {
    ++a;
  }
  if (cnt[a] == n) {
    printf("%s\n", s.c_str());
    return;
  }
  for (int c = 0; c < sigma; ++c) {
    if (cnt[c] == 1) {
      s = "";
      s += (char) ('a' + c);
      --cnt[c];
      for (int i = 0; i < sigma; ++i) {
        while (cnt[i]) {
          s += (char) ('a' + i);
          --cnt[i];
        }
      }
      printf("%s\n", s.c_str());
      return;
    }
  }
  if (cnt[a] - 2 <= (n - 2) / 2) {
    s = "";
    s += (char) ('a' + a);
    s += (char) ('a' + a);
    cnt[a] -= 2;
    for (int i = 0; i < sigma; ++i) {
      if (i == a) {
        continue;
      }
      while (cnt[i]) {
        s += (char) ('a' + i);
        --cnt[i];
        if (cnt[a]) {
          s += (char) ('a' + a);
          --cnt[a];
        }
      }
    }
    printf("%s\n", s.c_str());
    return;
  }
  int b = a + 1;
  while (!cnt[b]) {
    ++b;
  }
  s = "";
  s += (char) ('a' + a);
  --cnt[a];
  s += (char) ('a' + b);
  --cnt[b];
  int c = b + 1;
  while (c < sigma && !cnt[c]) {
    ++c;
  }
  if (c < sigma) {
    while (cnt[a]) {
      s += (char) ('a' + a);
      --cnt[a];
    }
    s += (char) ('a' + c);
    --cnt[c];
    for (int i = 0; i < sigma; ++i) {
      while (cnt[i]) {
        s += (char) ('a' + i);
        --cnt[i];
      }
    }
    printf("%s\n", s.c_str());
    return;
  }
  while (cnt[b]) {
    s += (char) ('a' + b);
    --cnt[b];
  }
  while (cnt[a]) {
    s += (char) ('a' + a);
    --cnt[a];
  }
  printf("%s\n", s.c_str());
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}