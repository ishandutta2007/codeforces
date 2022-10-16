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

const int maxn = 505;
int n, k;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

int a[maxn];

int ask(const vector<int> &q) {
  printf("? ");
  for (int i = 0; i < sz(q); i++) {
    printf("%d ", q[i] + 1);
  }
  printf("\n");
  fflush(stdout);
  int pos, val;
  scanf("%d%d", &pos, &val);
  pos--;
  a[pos] = val;
  return pos;
}

void solve() {
  for (int i = 0; i < n; i++) {
    a[i] = -1;
  }
  vector<int> q;
  for (int i = 0; i < k; i++) {
    q.push_back(i);
  }
  int x = ask(q);
  q.erase(q.begin() + x);
  q.push_back(k);
  int y = ask(q);
  q.erase(find(q.begin(), q.end(), y));
  if (a[x] > a[y]) {
    swap(x, y);
  }
  int res = 0;
  for (int i = 0; i < sz(q); i++) {
    vector<int> qq;
    for (int j = 0; j < sz(q); j++) {
      if (j != i) {
        qq.push_back(q[j]);
      }
    }
    qq.push_back(x);
    qq.push_back(y);
    if (ask(qq) == y) {
      res++;
    }
  }
  printf("! %d\n", res + 1);
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