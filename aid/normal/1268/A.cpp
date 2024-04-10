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

const int maxn = (int) 2e5 + 5;
char tmp[maxn];
int n, k;
string s;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

void solve() {
  {
    string t;
    for (int i = 0; i < n; i++) {
      t += s[i % k];
    }
    if (t >= s) {
      printf("%d\n", n);
      printf("%s\n", t.c_str());
      return;
    }
  }
  int pos = k - 1;
  while (s[pos] == '9') {
    pos--;
  }
  string t;
  for (int i = 0; i < pos; i++) {
    t += s[i];
  }
  t += (char) (s[pos] + 1);
  for (int i = pos + 1; i < k; i++) {
    t += '0';
  }
  for (int i = k; i < n; i++) {
    t += t[i % k];
  }
  printf("%d\n", n);
  printf("%s\n", t.c_str());
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