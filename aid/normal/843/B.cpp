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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(time(0)); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 5e4 + 5;
int n, s, x;

int read() {
  if (scanf("%d%d%d", &n, &s, &x) < 3) {
    return false;
  }
  s--;
  return true;
}

pair<int, int> ask(int pos) {
  printf("? %d\n", pos + 1);
  fflush(stdout);
  pair<int, int> res;
  scanf("%d%d", &res.first, &res.second);
  if (res.second > 0) {
    res.second--;
  }
  return res;
}

const int K = 999;

void solve() {
  vector< pair<int, int> > a;
  for (int i = 0; i < K; i++) {
    int pos = rnd(n);
    pair<int, int> p = ask(pos);
    a.push_back(make_pair(p.first, pos));
  }
  sort(a.begin(), a.end());
  int pos = upper_bound(a.begin(), a.end(), make_pair(x, inf)) - a.begin() - 1;
  if (pos < 0) {
    pos = s;
  } else {
    pos = a[pos].second;
  }
  int res = -1;
  while (pos != -1) {
    pair<int, int> p = ask(pos);
    if (p.first >= x) {
      res = p.first;
      break;
    }
    pos = p.second;
  }
  printf("! %d\n", res);
  fflush(stdout);
}

int main() {
  precalc();
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}