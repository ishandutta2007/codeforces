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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 1e6 + 5;
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

vector<int> a;
vector<pair<int, pair<int, int>>> st;

void solve() {
  int l = 0;
  while (l < n && s[l] == '0') {
    ++l;
  }
  if (l >= n) {
    printf("%d\n", n);
    return;
  }
  int r = n;
  while (s[r - 1] == '0') {
    --r;
  }
  a.clear();
  int p = -1;
  for (int i = l; i < r; ++i) {
    if (s[i] == '1') {
      if (p != -1) {
        a.push_back(i - p - 1);
      }
      p = i;
    }
  }
  st.clear();
  for (int i = 0; i < sz(a); ++i) {
    int dp = (st.empty() ? 1 : st.back().second.first);
    int cur = mul(a[i] + 1, dp);
    add(cur, 1);
    int p = -1;
    if (!st.empty()) {
      add(st.back().second.first, mod - 1);
    }
    while (!st.empty() && st.back().first <= a[i]) {
      p = st.back().first;
      st.pop_back();
    }
    if (!st.empty()) {
      add(st.back().second.first, mod - mul(a[i] - p, st.back().second.second));
      add(cur, st.back().second.first);
    }
    st.push_back(make_pair(a[i], make_pair(cur, dp)));
  }
  int res = st.back().second.first;
  res = mul(res, l + 1);
  res = mul(res, n - r + 1);
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