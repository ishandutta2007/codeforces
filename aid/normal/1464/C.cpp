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
long long t;
string s;

bool read() {
  if (scanf("%d%lld", &n, &t) < 2) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

const int maxk = 55;
int cnt[maxk];

void solve() {
  for (int i = 0; i < maxk; ++i) {
    cnt[i] = 0;
  }
  t -= (1 << (s[n - 1] - 'a'));
  t += (1 << (s[n - 2] - 'a'));
  n -= 2;
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i] - 'a'];
  }
  int carry = 0;
  for (int i = 0; i < maxk; ++i) {
    cnt[i] += carry;
    carry = cnt[i] / 2;
    cnt[i] = (cnt[i] & 1);
  }
  for (int i = maxk - 1; i >= 0; --i) {
    if (!cnt[i]) {
      continue;
    }
    if (t > 0) {
      t -= (1ll << i);
    } else {
      t += (1ll << i);
    }
  }
  if (!t) {
    printf("Yes\n");
  } else {
    printf("No\n");
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