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

const int maxn = 2005;
int n;
string s, t;
char tmp[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  scanf("%s", tmp);
  t = tmp;
  return true;
}

const int sigma = 26;
int cnt[sigma];
vector<int> ans;

void sh(int k) {
  ans.push_back(k);
  string a = s.substr(0, n - k), b = s.substr(n - k, k);
  reverse(b.begin(), b.end());
  s = b + a;
}

void solve() {
  for (int i = 0; i < sigma; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  for (int i = 0; i < n; i++) {
    cnt[t[i] - 'a']--;
  }
  for (int i = 0; i < sigma; i++) {
    if (cnt[i]) {
      printf("-1\n");
      return;
    }
  }
  ans.clear();
  bool b = false;
  for (int i = 0; i < n; i++) {
    char need = t[n - 1 - i];
    int l, r;
    if (!b) {
      l = i;
      r = n;
    } else {
      l = 0;
      r = n - i;
    }
    int pos = -1;
    for (int j = l; j < r; j++) {
      if (s[j] == need) {
        pos = j;
        break;
      }
    }
    assert(pos != -1);
    if (!b) {
      sh(n - pos);
      sh(pos + 1);
      sh(n - pos - 1);
    } else {
      sh(n - pos - 1);
      sh(1);
    }
    b = !b;
  }
  if (b) {
    sh(n);
  }
  assert(s == t);
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
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