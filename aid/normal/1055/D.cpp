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

const int maxn = 3005;
int n;
string s[maxn], t[maxn];
char tmp[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    s[i] = tmp;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    t[i] = tmp;
  }
  return true;
}

int z[2 * maxn];

void getZ(const string &s) {
  for (int i = 1, l = 0, r = -1; i < sz(s); i++) {
    if (i + z[i - l] < r) {
      z[i] = z[i - l];
    } else {
      l = i;
      r = max(r, i);
      while (r < sz(s) && s[r] == s[r - l]) {
        r++;
      }
      z[i] = r - l;
    }
  }
}

int getPos(const string &s, const string &t) {
  getZ(t + "#" + s);
  for (int i = 0; i < sz(s); i++) {
    if (z[sz(t) + 1 + i] >= sz(t)) {
      return i;
    }
  }
  return -1;
}

int ls[maxn], rs[maxn];

void solve() {
  string from, to;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) {
      ls[i] = -1;
      rs[i] = -1;
      continue;
    }
    auto &l = ls[i], &r = rs[i];
    l = 0;
    r = sz(s[i]);
    while (s[i][l] == t[i][l]) {
      l++;
    }
    while (s[i][r - 1] == t[i][r - 1]) {
      r--;
    }
    string curs = s[i].substr(l, r - l), curt = t[i].substr(l, r - l);
    if (from.empty()) {
      from = curs;
      to = curt;
    }
    if (from != curs || to != curt) {
      printf("NO\n");
      return;
    }
  }
  while (true) {
    char c = 0;
    bool bad = false;
    for (int i = 0; i < n; i++) {
      if (ls[i] == -1) {
        continue;
      }
      if (ls[i] == 0) {
        bad = true;
        break;
      }
      if (!c) {
        c = s[i][ls[i] - 1];
      }
      if (c != s[i][ls[i] - 1]) {
        bad = true;
        break;
      }
    }
    if (bad) {
      break;
    }
    from.insert(from.begin(), c);
    to.insert(to.begin(), c);
    for (int i = 0; i < n; i++) {
      if (ls[i] == -1) {
        continue;
      }
      ls[i]--;
    }
  }
  while (true) {
    char c = 0;
    bool bad = false;
    for (int i = 0; i < n; i++) {
      if (ls[i] == -1) {
        continue;
      }
      if (rs[i] >= sz(s[i])) {
        bad = true;
        break;
      }
      if (!c) {
        c = s[i][rs[i]];
      }
      if (c != s[i][rs[i]]) {
        bad = true;
        break;
      }
    }
    if (bad) {
      break;
    }
    from += c;
    to += c;
    for (int i = 0; i < n; i++) {
      if (ls[i] == -1) {
        continue;
      }
      rs[i]++;
    }
  }
  for (int i = 0; i < n; i++) {
    int pos = getPos(s[i], from);
    if (ls[i] == -1) {
      if (pos != -1) {
        printf("NO\n");
        return;
      }
    } else {
      if (pos != ls[i]) {
        printf("NO\n");
        return;
      }
    }
  }
  printf("YES\n");
  printf("%s\n%s\n", from.c_str(), to.c_str());
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