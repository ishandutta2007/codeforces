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

const int maxn = (int) 1e5 + 5;
int n, m;
char tmp[maxn];
string s;

int read() {
  if (scanf("%d", &m) < 1) {
    return false;
  }
  scanf("%s", tmp);
  s = tmp;
  n = sz(s);
  return true;
}

vector<int> segs, p, segs0;
string ans;

void solve() {
  segs.clear();
  for (int i = 0; i + m <= n; i++) {
    segs.push_back(i);
  }
  ans.clear();
  for (char c = 'a'; c <= 'z'; c++) {
    p.clear();
    for (int i = 0; i < n; i++) {
      if (s[i] == c) {
        p.push_back(i);
      }
    }
    bool can = true;
    for (int i = 0, j = 0; i < sz(segs); i++) {
      while (j < sz(p) && p[j] < segs[i]) {
        j++;
      }
      if (j == sz(p) || p[j] >= segs[i] + m) {
        can = false;
        break;
      }
    }
    if (can) {
      int pos = -1;
      for (int i = 0, j = 0; i < sz(segs); i++) {
        if (segs[i] <= pos) {
          continue;
        }
        while (j + 1 < sz(p) && p[j + 1] < segs[i] + m) {
          j++;
        }
        ans += c;
        pos = p[j];
      }
      break;
    } else {
      segs0.clear();
      for (int i = 0, j = 0; i < sz(segs); i++) {
        while (j < sz(p) && p[j] < segs[i]) {
          j++;
        }
        if (j == sz(p) || p[j] >= segs[i] + m) {
          segs0.push_back(segs[i]);
        }
      }
      segs = segs0;
      for (int i = 0; i < sz(p); i++) {
        ans += c;
      }
    }
  }
  printf("%s\n", ans.c_str());
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