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

const int maxn = 2005;
int n, k;
char tmp[maxn];
string s;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  return true;
}

string t;
vector<pair<int, int>> ans;

void solve() {
  t = "";
  for (int i = 0; i < k - 1; i++) {
    t += "()";
  }
  t += "(";
  for (int i = 0; i < n / 2 - k; i++) {
    t += "()";
  }
  t += ")";
  ans.clear();
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) {
      continue;
    }
    int j = i + 1;
    while (s[j] != t[i]) {
      j++;
    }
    ans.push_back(make_pair(i, j));
    reverse(s.begin() + i, s.begin() + (j + 1));
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  }
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