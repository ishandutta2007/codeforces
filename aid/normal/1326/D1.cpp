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

const int sigma = 26;
int len[maxn], link[maxn];
int go[maxn][sigma];
int vs;

int newNode(int l, int lnk) {
  len[vs] = l;
  link[vs] = lnk;
  for (int i = 0; i < sigma; i++) {
    go[vs][i] = -1;
  }
  return vs++;
}

string getMaxPal() {
  int l = 0;
  vs = 0;
  newNode(-1, -1);
  int v = newNode(0, 0);
  for (int i = 0; i < sz(s); i++) {
    while (i - len[v] - 1 < 0 || s[i] != s[i - len[v] - 1]) {
      v = link[v];
    }
    if (go[v][s[i] - 'a'] != -1) {
      v = go[v][s[i] - 'a'];
      if (len[v] == i + 1) {
        l = max(l, i + 1);
      }
      continue;
    }
    int u = newNode(len[v] + 2, 1);
    go[v][s[i] - 'a'] = u;
    v = link[v];
    while (v >= 0 && (i - len[v] - 1 < 0 || s[i] != s[i - len[v] - 1])) {
      v = link[v];
    }
    if (v != -1) {
      link[u] = go[v][s[i] - 'a'];
    }
    if (len[u] == i + 1) {
      l = max(l, i + 1);
    }
    v = u;
  }
  if (len[v] > l) {
    return s.substr(sz(s) - len[v], len[v]);
  }
  return s.substr(0, l);
}

void solve() {
  string pref;
  int l = 0, r = n;
  while (l < r - 1 && s[l] == s[r - 1]) {
    pref += s[l];
    l++;
    r--;
  }
  s = s.substr(l, r - l);
  string t = getMaxPal();
  string suff = pref;
  reverse(suff.begin(), suff.end());
  t = pref + t + suff;
  printf("%s\n", t.c_str());
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