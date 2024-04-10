#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
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

const int maxn = (int) 5e4 + 5;
int n;
set<int> st;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  st.clear();
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    st.insert(a);
  }
  return true;
}

void solve() {
  while (true) {
    auto xit = st.end();
    xit--;
    int x = *xit, xx = x;
    st.erase(xit);
    x /= 2;
    while (st.find(x) != st.end()) {
      x /= 2;
    }
    if (x == 0) {
      st.insert(xx);
      break;
    } else {
      st.insert(x);
    }
  }
  for (auto it = st.begin(); it != st.end(); it++) {
    printf("%d ", *it);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}