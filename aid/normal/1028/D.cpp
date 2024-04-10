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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

const int maxn = (int) 4e5 + 5;
int n;
int ts[maxn];
int xs[maxn];
char tmp[100];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s%d", tmp, &xs[i]);
    ts[i] = (tmp[1] == 'C');
  }
  return true;
}

set<int> st;

void solve() {
  st.clear();
  st.insert(-inf);
  st.insert(inf);
  int l = -inf, r = inf;
  int res = 1;
  for (int i = 0; i < n; i++) {
    auto x = xs[i];
    if (!ts[i]) {
      st.insert(x);
    } else {
      if (x < l || x > r) {
        printf("0\n");
        return;
      }
      if (l < x && x < r) {
        res = mul(res, 2);
      }
      auto it = st.find(x);
      auto nxt = it;
      nxt++;
      r = *nxt;
      auto prv = it;
      prv--;
      l = *prv;
      st.erase(it);
    }
  }
  int cnt = 0;
  for (auto it = st.begin(); it != st.end(); it++) {
    if (l < *it && *it < r) {
      cnt++;
    }
  }
  res = mul(res, cnt + 1);
  printf("%d\n", res);
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