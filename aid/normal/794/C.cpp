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

const int maxn = (int) 3e5 + 5;
int n;
string s[2];
char tmp[maxn];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s[0] = tmp;
  scanf("%s", tmp);
  s[1] = tmp;
  n = sz(s[0]);
  assert(sz(s[1]) == n);
  return true;
}

void solve() {
  sort(s[0].begin(), s[0].end());
  sort(s[1].begin(), s[1].end(), greater<char>());
  s[0].resize((n + 1) / 2);
  s[1].resize(n / 2);
  int l[2] = {0, 0};
  int r[2] = {sz(s[0]), sz(s[1])};
  string res(n, ' ');
  int resl = 0, resr = sz(res);
  for (int i = 0; i < n - 1; i++) {
    int t = (i & 1);
    if (s[0][l[0]] < s[1][l[1]]) {
      res[resl++] = s[t][l[t]++];
    } else {
      res[--resr] = s[t][--r[t]];
    }
  }
  {
    int t = ((n - 1) & 1);
    res[resl++] = s[t][l[t]++];
  }
  assert(l[0] == r[0]);
  assert(l[1] == r[1]);
  assert(resl == resr);
  printf("%s\n", res.c_str());
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