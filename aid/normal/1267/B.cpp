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

const int maxn = (int) 3e5 + 5;
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

vector<pair<char, int>> a;

void solve() {
  a.clear();
  a.push_back(make_pair(s[0], 1));
  for (int i = 1; i < n; i++) {
    if (s[i] == a.back().first) {
      a.back().second++;
    } else {
      a.push_back(make_pair(s[i], 1));
    }
  }
  int k = sz(a);
  if (!(k & 1)) {
    printf("0\n");
    return;
  }
  int m = k / 2;
  if (a[m].second <= 1) {
    printf("0\n");
    return;
  }
  int l = m - 1, r = m + 1;
  while (l >= 0) {
    if (a[l].first != a[r].first || a[l].second + a[r].second <= 2) {
      printf("0\n");
      return;
    }
    l--;
    r++;
  }
  printf("%d\n", a[m].second + 1);
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