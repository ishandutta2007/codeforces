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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

pair<int, int> gcd(int a, int b) {
  if (!b) {
    return make_pair(1, 0);
  }
  pair<int, int> p = gcd(b, a % b);
  return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
  return ((gcd(x, mod).first % mod) + mod) % mod;
}

const int maxr = 105;
int r;
int p[4];

int read() {
  if (scanf("%d", &r) < 1) {
    return false;
  }
  for (int i = 0; i < 4; i++) {
    scanf("%d", &p[i]);
  }
  return true;
}

const int gox[] = {-1, 0, 1, 0};
const int goy[] = {0, -1, 0, 1};

vector<pair<int, int>> ps;
vector<vector<int>> a;

void solve() {
  {
    int s = 0;
    for (int i = 0; i < 4; i++) {
      add(s, p[i]);
    }
    int sinv = inv(s);
    for (int i = 0; i < 4; i++) {
      p[i] = mul(p[i], sinv);
    }
  }
  ps.clear();
  for (int x = -r; x <= r; x++) {
    for (int y = -r; y <= r; y++) {
      if (x * x + y * y <= r * r) {
        ps.push_back(make_pair(x, y));
      }
    }
  }
  int n = sz(ps);
  a.clear();
  a.resize(n, vector<int>(n + 1, 0));
  for (int i = 0; i < n; i++) {
    a[i][i] = 1;
    for (int dir = 0; dir < 4; dir++) {
      pair<int, int> to = make_pair(ps[i].first + gox[dir], ps[i].second + goy[dir]);
      int j = lower_bound(ps.begin(), ps.end(), to) - ps.begin();
      if (j >= sz(ps) || ps[j] != to) {
        continue;
      }
      a[i][j] = mul(mod - 1, p[dir]);
    }
  }
  {
    int id = lower_bound(ps.begin(), ps.end(), make_pair(0, 0)) - ps.begin();
    assert(id < sz(ps) && ps[id] == make_pair(0, 0));
    a[id][n] = 1;
  }
  for (int i = 0; i < n; i++) {
    assert(a[i][i]);
    int ainv = inv(a[i][i]);
    for (int j = i; j < i + maxr && j < n; j++) {
      a[i][j] = mul(a[i][j], ainv);
    }
    a[i][n] = mul(a[i][n], ainv);
    for (int j = i + 1; j < i + maxr && j < n; j++) {
      int t = a[j][i];
      for (int k = i; k < i + maxr && k < n; k++) {
        add(a[j][k], mod - mul(t, a[i][k]));
      }
      add(a[j][n], mod - mul(t, a[i][n]));
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i - 1; j > i - maxr && j >= 0; j--) {
      int t = a[j][i];
      a[j][i] = 0;
      add(a[j][n], mod - mul(t, a[i][n]));
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    add(res, a[i][n]);
  }
  printf("%d\n", res);
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