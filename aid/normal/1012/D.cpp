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

const int maxn = (int) 2e5 + 5;
string s, t;
char tmp[maxn];

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  scanf("%s", tmp);
  t = tmp;
  return true;
}

vector<pair<int, int>> ans;

int get(const string &s) {
  int res = 0;
  for (int i = 0; i + 1 < sz(s); i++) {
    res += (s[i] != s[i + 1]);
  }
  return res;
}

void solve2(string s, string t) {
  bool inv = true;
  if (get(s) < get(t)) {
    swap(s, t);
    inv = false;
  }
  int j = sz(t) - 1;
  for (int i = sz(s) - 1; i > 0; i--) {
    if (s[i] == s[i - 1]) {
      continue;
    }
    if (j >= 0 && t[j] == s[i]) {
      ans.push_back(inv ? make_pair(j + 1, i) : make_pair(i, j + 1));
      inv = !inv;
      continue;
    }
    while (j > 0 && t[j] == t[j - 1]) {
      j--;
    }
    ans.push_back(inv ? make_pair(max(0, j), i) : make_pair(i, max(0, j)));
    inv = !inv;
    j--;
  }
  while (true) {
    while (j > 0 && t[j] == t[j - 1]) {
      j--;
    }
    if (j <= 0) {
      break;
    }
    ans.push_back(inv ? make_pair(j, 0) : make_pair(0, j));
    inv = !inv;
    j--;
  }
}

int solve1(const string &s, const string &t, bool topr, bool inv) {
  int x = 0;
  for (int i = 0; i < sz(s); i++) {
    if (s[i] != (char) ('a' + (x & 1))) {
      x++;
    }
  }
  x++;
  int y = 0;
  for (int i = 0; i < sz(t); i++) {
    if (t[i] != (char) ('a' + ((y & 1) ^ 1))) {
      y++;
    }
  }
  y++;
  if (x == 1) {
    if (y == 1) {
      if (topr) {
        printf("0\n");
      }
      return 0;
    }
    int bi = 1;
    for (int i = 3; i < y; i += 2) {
      if (max(y - i, i) < max(y - bi, bi)) {
        bi = i;
      }
    }
    if (topr) {
      ans.clear();
      int cur = 0;
      for (int i = 0; i < sz(t); i++) {
        if (t[i] != (char) ('a' + ((cur & 1) ^ 1))) {
          cur++;
        }
        if (cur == bi) {
          ans.push_back(make_pair(sz(s), i));
          string ns = s + t.substr(i);
          string nt = t.substr(0, i);
          solve2(ns, nt);
          break;
        }
      }
      if (inv) {
        for (int i = 0; i < sz(ans); i++) {
          swap(ans[i].first, ans[i].second);
        }
      }
      printf("%d\n", sz(ans));
      for (int i = 0; i < sz(ans); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
      }
      assert(sz(ans) == max(y - bi, bi));
    }
    return max(y - bi, bi);
  }
  if (y == 1) {
    int bi = 1;
    for (int i = 3; i < x; i += 2) {
      if (max(x - i, i) < max(x - bi, bi)) {
        bi = i;
      }
    }
    if (topr) {
      ans.clear();
      int cur = 0;
      for (int i = 0; i < sz(s); i++) {
        if (s[i] != (char) ('a' + (cur & 1))) {
          cur++;
        }
        if (cur == bi) {
          ans.push_back(make_pair(i, sz(t)));
          string ns = s.substr(0, i);
          string nt = t + s.substr(i);
          solve2(ns, nt);
          break;
        }
      }
      if (inv) {
        for (int i = 0; i < sz(ans); i++) {
          swap(ans[i].first, ans[i].second);
        }
      }
      printf("%d\n", sz(ans));
      for (int i = 0; i < sz(ans); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
      }
      assert(sz(ans) == max(x - bi, bi));
    }
    return max(x - bi, bi);
  }
  int bi = 1, bj = 1;
  for (int i = 3; i < x; i += 2) {
    if (max(x - i, y + i - 2) < max(x - bi + bj - 1, y + bi - bj - 1)) {
      bi = i;
      bj = 1;
    }
  }
  for (int i = 3; i < y; i += 2) {
    if (max(x + i - 2, y - i) < max(x - bi + bj - 1, y + bi - bj - 1)) {
      bi = 1;
      bj = i;
    }
  }
  if (topr) {
    ans.clear();
    int cur = 0;
    int ps = -1;
    for (int i = 0; i < sz(s); i++) {
      if (s[i] != (char) ('a' + (cur & 1))) {
        cur++;
      }
      if (cur == bi) {
        ps = i;
        break;
      }
    }
    int pt = -1;
    cur = 0;
    for (int i = 0; i < sz(t); i++) {
      if (t[i] != (char) ('a' + ((cur & 1) ^ 1))) {
        cur++;
      }
      if (cur == bj) {
        pt = i;
        break;
      }
    }
    ans.push_back(make_pair(ps, pt));
    string ns = s.substr(0, ps) + t.substr(pt);
    string nt = t.substr(0, pt) + s.substr(ps);
    solve2(ns, nt);
    if (inv) {
      for (int i = 0; i < sz(ans); i++) {
        swap(ans[i].first, ans[i].second);
      }
    }
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); i++) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
    assert(sz(ans) == max(x - bi + bj - 1, y + bi - bj - 1));
  }
  return max(x - bi + bj - 1, y + bi - bj - 1);
}

void solve() {
  if (solve1(s, t, false, false) < solve1(t, s, false, true)) {
    solve1(s, t, true, false);
  } else {
    solve1(t, s, true, true);
  }
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