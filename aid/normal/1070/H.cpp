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

const int maxn = (int) 1e4 + 5;
int n;
string f[maxn];
char tmp[100];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", tmp);
    f[i] = tmp;
  }
  return true;
}

map<string, pair<int, int>> mp;

void solve() {
  mp.clear();
  for (int i = 0; i < n; i++) {
    set<string> used;
    for (int l = 0; l < sz(f[i]); l++) {
      for (int r = l + 1; r <= sz(f[i]); r++) {
        string cur = f[i].substr(l, r - l);
        if (used.count(cur)) {
          continue;
        }
        used.insert(cur);
        auto &p = mp[cur];
        p.first++;
        p.second = i;
      }
    }
  }
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    scanf("%s", tmp);
    string s = tmp;
    auto p = mp[s];
    int cnt = p.first;
    int id = (cnt ? p.second : -1);
    printf("%d %s\n", cnt, (id == -1 ? "-" : f[id].c_str()));
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