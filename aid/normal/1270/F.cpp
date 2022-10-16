#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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

int nxt[maxn];
const int K = 50;
map<int, int> mp[K];

void solve() {
  nxt[n] = n;
  for (int i = n - 1; i >= 0; i--) {
    nxt[i] = (s[i] == '1' ? i : nxt[i + 1]);
  }
  for (int i = 1; i < K; i++) {
    mp[i].clear();
    mp[i][0]++;
  }
  long long res = 0;
  int ones = 0;
  for (int i = n - 1; i >= 0; i--) {
    ones += (s[i] == '1');
    int pos = i;
    int cnt = 0;
    while (true) {
      pos = nxt[pos];
      cnt++;
      if (pos >= n || i + cnt * K > n) {
        break;
      }
      pos++;
      int npos = nxt[pos];
      int l = (pos - i + cnt - 1) / cnt, r = (npos - i) / cnt;
      l = max(l, K);
      if (l <= r) {
        res += (r - l + 1);
      }
    }
    for (int k = 1; k < K; k++) {
      int cur = (n - i) - ones * k;
      auto &val = mp[k][cur];
      res += val;
      val++;
    }
  }
  printf("%lld\n", res);
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