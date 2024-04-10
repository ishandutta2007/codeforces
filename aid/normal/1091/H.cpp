#ifdef DEBUG
//#define _GLIBCXX_DEBUG
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

const int maxn = (int) 2e5 + 5;
int lDiv[maxn];
vector<int> pr;
vector<int> pr2;

void precalc() {
  for (int i = 2; i < maxn; i++) {
    if (!lDiv[i]) {
      lDiv[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < sz(pr) && pr[j] <= lDiv[i]; j++) {
      int p = i * pr[j];
      if (p >= maxn) {
        break;
      }
      lDiv[p] = pr[j];
    }
  }
  for (int i = 2; i < maxn; i++) {
    if (lDiv[i] == i) {
      pr2.push_back(i);
    } else {
      int x = i / lDiv[i];
      if (lDiv[x] == x) {
        pr2.push_back(i);
      }
    }
  }
}

int n, f;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &f) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    a[2 * i] = y - x - 1;
    a[2 * i + 1] = z - y - 1;
  }
  n *= 2;
  return true;
}

const int maxx = 100;
int gr[maxn];
bitset<maxn> bs[maxx];
bitset<maxn> ps;

void solve() {
  ps.reset();
  for (int i = 0; i < sz(pr2); i++) {
    if (pr2[i] == f) {
      continue;
    }
    ps[pr2[i]] = true;
  }
  int mx = -1;
  for (int i = 0; i < maxn; i++) {
    auto &cur = gr[i];
    cur = 0;
    while (bs[cur][i]) {
      cur++;
    }
    mx = max(mx, cur);
    bs[cur] |= (ps << i);
  }
  for (int i = 0; i <= mx; i++) {
    bs[i].reset();
  }
  int x = 0;
  for (int i = 0; i < n; i++) {
    x ^= gr[a[i]];
  }
  if (x) {
    printf("Alice\nBob\n");
  } else {
    printf("Bob\nAlice\n");
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