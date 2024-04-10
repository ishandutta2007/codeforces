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

const int maxn = (int) 4e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  return true;
}

int dep[maxn];
vector<pair<int, int>> st;

void solve() {
  int s = 0;
  for (int i = 0; i < n; i++) {
    a[n + i] = a[i];
    if (a[i] < a[s]) {
      s = i;
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    dep[i] = 0;
  }
  st.clear();
  st.push_back(make_pair(s, 0));
  int d = 1;
  dep[s + 1] = max(dep[s + 1], d);
  for (int i = s + 1; i < s + n; i++) {
    int cur = 0;
    while (a[st.back().first] > a[i]) {
      cur = max(cur, st.back().second) + 1;
      st.pop_back();
    }
    st.push_back(make_pair(i, cur));
    d = max(d, sz(st) + cur);
    dep[i + 1] = max(dep[i + 1], d);
  }
  st.clear();
  st.push_back(make_pair(s, 0));
  d = 1;
  dep[s + n] = max(dep[s + n], d);
  for (int i = s + n - 1; i >= s + 1; i--) {
    int cur = 0;
    while (a[st.back().first] > a[i]) {
      cur = max(cur, st.back().second) + 1;
      st.pop_back();
    }
    st.push_back(make_pair(i, cur));
    d = max(d, sz(st) + cur);
    dep[i] = max(dep[i], d);
  }
  int mn = inf, sh = -1;
  for (int i = s + 1; i <= s + n; i++) {
    if (dep[i] < mn) {
      mn = dep[i];
      sh = i;
    }
  }
  sh %= n;
  printf("%d %d\n", mn, sh);
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