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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 2e5 + 5;
int n, k;
int a[maxn];

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int s[maxn];
map<int, int> cnt;

void solve() {
  int x = (1 << k) - 1;
  s[0] = 0;
  for (int i = 0; i < n; i++) {
    s[i + 1] = (s[i] ^ a[i]);
  }
  cnt.clear();
  for (int i = 0; i <= n; i++) {
    int cur = s[i];
    if (cur & 1) {
      cur ^= x;
    }
    cnt[cur]++;
  }
  long long res = 0;
  int was = 0;
  for (auto it = cnt.begin(); it != cnt.end(); it++) {
    int cur = it->second;
    res += (long long) cur * was;
    res += (long long) (cur / 2) * ((cur + 1) / 2);
    was += cur;
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