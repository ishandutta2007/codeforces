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

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
}

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

set<int> st, alive;
vector<int> ans;

int getNxt(int i) {
  auto it = alive.upper_bound(i);
  if (it == alive.end()) {
    it = alive.begin();
  }
  return *it;
}

void solve() {
  st.clear();
  alive.clear();
  ans.clear();
  for (int i = 0; i < n; ++i) {
    alive.insert(i);
    int j = (i + 1) % n;
    if (gcd(a[i], a[j]) == 1) {
      st.insert(i);
    }
  }
  int pos = -1;
  while (!st.empty()) {
    auto it = st.upper_bound(pos);
    if (it == st.end()) {
      it = st.begin();
    }
    int i = *it;
    int j = getNxt(i);
    ans.push_back(j);
    alive.erase(j);
    pos = j;
    if (i == j) {
      break;
    }
    int k = getNxt(j);
    auto del = it;
    ++it;
    st.erase(del);
    if (it == st.end()) {
      it = st.begin();
    }
    if (!st.empty() && *it == j) {
      st.erase(it);
    }
    if (gcd(a[i], a[k]) == 1) {
      st.insert(i);
    }
  }
  printf("%d ", sz(ans));
  for (int i = 0; i < sz(ans); ++i) {
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