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
int n;
int a[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

int nl[maxn], nr[maxn];
int l[maxn], r[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    nl[i] = -1;
    nr[i] = n;
  }
  for (int bit = 0; bit < 30; bit++) {
    int lst = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] & (1 << bit)) {
        lst = i;
      } else {
        nl[i] = max(nl[i], lst);
      }
    }
    lst = n;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] & (1 << bit)) {
        lst = i;
      } else {
        nr[i] = min(nr[i], lst);
      }
    }
  }
  {
    vector<int> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && a[st.back()] < a[i]) {
        st.pop_back();
      }
      if (st.empty()) {
        l[i] = -1;
      } else {
        l[i] = st.back();
      }
      st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && a[st.back()] <= a[i]) {
        st.pop_back();
      }
      if (st.empty()) {
        r[i] = n;
      } else {
        r[i] = st.back();
      }
      st.push_back(i);
    }
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    for (int it = 1; it < 4; it++) {
      int lcnt, rcnt;
      if (it & 1) {
        lcnt = max(0, nl[i] - l[i]);
      } else {
        lcnt = i - l[i];
      }
      if (it & 2) {
        rcnt = max(0, r[i] - nr[i]);
      } else {
        rcnt = r[i] - i;
      }
      long long toadd = (long long) lcnt * rcnt;
      if (it == 3) {
        toadd *= -1;
      }
      res += toadd;
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