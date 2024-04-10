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

const int maxn = (int) 1e6 + 5;
int n, k;
string s, a, b;
char tmp[maxn];

bool read() {
  if (scanf("%d", &k) < 1) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  n = sz(s);
  scanf("%s", tmp);
  a = tmp;
  scanf("%s", tmp);
  b = tmp;
  return true;
}

const int sigma = 26;
int p[sigma];
int used[sigma];

bool rec1(int i, bool isb) {
  if (i >= n) {
    return true;
  }
  int cur = (s[i] - 'a');
  if (p[cur] != -1) {
    char toc = 'a' + p[cur];
    if (!isb) {
      if (toc < a[i]) {
        return false;
      }
      if (a[i] < toc) {
        return true;
      }
      return rec1(i + 1, isb);
    } else {
      if (toc > b[i]) {
        return false;
      }
      if (toc < b[i]) {
        return true;
      }
      return rec1(i + 1, isb);
    }
  }
  int l, r;
  if (!isb) {
    l = (a[i] - 'a') + 1;
    r = k;
  } else {
    l = 0;
    r = (b[i] - 'a');
  }
  for (int c = l; c < r; c++) {
    if (!used[c]) {
      p[cur] = c;
      used[c] = true;
      return true;
    }
  }
  int need = ((!isb ? a[i] : b[i]) - 'a');
  if (used[need]) {
    return false;
  }
  p[cur] = need;
  used[need] = true;
  if (rec1(i + 1, isb)) {
    return true;
  }
  p[cur] = -1;
  used[need] = false;
  return false;
}

bool rec2(int i) {
  if (i >= n) {
    return true;
  }
  int cur = (s[i] - 'a');
  if (p[cur] != -1) {
    char toc = 'a' + p[cur];
    if (toc < a[i] || toc > b[i]) {
      return false;
    }
    if (a[i] < toc) {
      if (toc < b[i]) {
        return true;
      }
      return rec1(i + 1, true);
    } else {
      if (toc < b[i]) {
        return rec1(i + 1, false);
      }
      return rec2(i + 1);
    }
  }
  for (int c = (a[i] - 'a') + 1; c < (b[i] - 'a'); c++) {
    if (!used[c]) {
      p[cur] = c;
      used[c] = true;
      return true;
    }
  }
  if (a[i] == b[i]) {
    if (used[a[i] - 'a']) {
      return false;
    }
    p[cur] = a[i] - 'a';
    used[a[i] - 'a'] = true;
    if (rec2(i + 1)) {
      return true;
    }
    p[cur] = -1;
    used[a[i] - 'a'] = false;
    return false;
  }
  if (!used[a[i] - 'a']) {
    p[cur] = a[i] - 'a';
    used[a[i] - 'a'] = true;
    if (rec1(i + 1, false)) {
      return true;
    }
    p[cur] = -1;
    used[a[i] - 'a'] = false;
  }
  if (!used[b[i] - 'a']) {
    p[cur] = b[i] - 'a';
    used[b[i] - 'a'] = true;
    if (rec1(i + 1, true)) {
      return true;
    }
    p[cur] = -1;
    used[b[i] - 'a'] = false;
  }
  return false;
}

void solve() {
  for (int i = 0; i < k; i++) {
    p[i] = -1;
    used[i] = false;
  }
  if (!rec2(0)) {
    printf("NO\n");
    return;
  }
  for (int i = 0; i < k; i++) {
    if (p[i] != -1) {
      continue;
    }
    for (int j = 0; j < k; j++) {
      if (!used[j]) {
        p[i] = j;
        used[j] = true;
        break;
      }
    }
  }
  string ans;
  for (int i = 0; i < k; i++) {
    ans += (char) ('a' + p[i]);
  }
  printf("YES\n");
  printf("%s\n", ans.c_str());
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