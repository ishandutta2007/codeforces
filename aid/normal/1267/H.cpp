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

const int maxn = 8505;
int n;
int p[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  return true;
}

int ans[maxn];
set<int> st;

void solve() {
  for (int i = 0; i < n; i++) {
    ans[i] = -1;
  }
  for (int c = 0;; c++) {
    st.clear();
    for (int i = 0; i < n; i++) {
      if (ans[i] == -1) {
        st.insert(i);
      }
    }
    if (st.empty()) {
      break;
    }
    for (int i = n - 1; i >= 0; i--) {
      int x = p[i];
      if (ans[x] != -1) {
        continue;
      }
      if (!st.count(x)) {
        continue;
      }
      ans[x] = c;
      auto it = st.lower_bound(x);
      auto todel = it;
      it++;
      st.erase(todel);
      if (it != st.end()) {
        todel = it;
        it++;
        st.erase(todel);
      }
      if (it != st.begin()) {
        it--;
        st.erase(it);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
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