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

long long gcd(long long a, long long b) {
  return (b ? gcd(b, a % b) : a);
}

vector<long long> a[2];

bool read() {
  for (int t = 0; t < 2; t++) {
    a[t].resize(4);
    for (int i = 0; i < 4; i++) {
      if (scanf("%lld", &a[t][i]) < 1) {
        return false;
      }
    }
  }
  return true;
}

void move(int i, int j, vector<long long> &a, vector<pair<long long, long long>> &ans) {
  if (a[i] == a[j]) {
    return;
  }
  ans.push_back(make_pair(a[i], a[j]));
  a[i] = 2 * a[j] - a[i];
}

void shrink(vector<long long> &a, vector<pair<long long, long long>> &ans) {
  while (true) {
    sort(a.begin(), a.end());
    if (a[3] - a[0] <= 1) {
      break;
    }
    long long d = max(1ll, (a[3] - a[0]) / 3);
    long long l = a[0] + d, r = a[3] - d;
    while (true) {
      sort(a.begin(), a.end());
      if (l <= a[1] && a[1] <= r) {
        move(0, 1, a, ans);
        break;
      }
      if (l <= a[2] && a[2] <= r) {
        move(3, 2, a, ans);
        break;
      }
      if (a[1] > r) {
        move(3, 1, a, ans);
        continue;
      }
      if (a[2] < l) {
        move(0, 2, a, ans);
        continue;
      }
      if (a[1] - a[0] < a[3] - a[2]) {
        move(1, 2, a, ans);
        move(1, 3, a, ans);
      } else {
        move(2, 1, a, ans);
        move(2, 0, a, ans);
      }
    }
  }
  sort(a.begin(), a.end());
  if (a[0] & 1) {
    long long x = a[3];
    for (int i = 0; i < 4; i++) {
      if (a[i] < x) {
        move(i, 3, a, ans);
      }
    }
  }
  sort(a.begin(), a.end());
}

void shift(vector<long long> &a, long long dx, vector<pair<long long, long long>> &ans) {
  bool b = false;
  sort(a.begin(), a.end());
  if (a[1] == a[3]) {
    move(0, 3, a, ans);
    b = true;
  }
  while (dx >= 4) {
    sort(a.begin(), a.end());
    long long d = a[3] - a[0];
    if (4 * d > dx) {
      move(3, 2, a, ans);
      continue;
    }
    if (4 * (d + a[3] - a[1]) <= dx) {
      move(1, 3, a, ans);
      continue;
    }
    for (int it = 0; it < 2; it++) {
      move(0, 3, a, ans);
      move(1, 0, a, ans);
      move(2, 0, a, ans);
      move(3, 0, a, ans);
    }
    dx -= 4 * d;
  }
  while (true) {
    sort(a.begin(), a.end());
    long long d = a[3] - a[0];
    if (d == 1) {
      break;
    }
    move(3, 2, a, ans);
  }
  if (dx) {
    for (int it = 0; it < 2; it++) {
      sort(a.begin(), a.end());
      long long x = a[3];
      for (int i = 0; i < 4; i++) {
        if (a[i] < x) {
          move(i, 3, a, ans);
        }
      }
    }
    dx -= 2;
  }
  if (b) {
    sort(a.begin(), a.end());
    move(3, 0, a, ans);
  }
  sort(a.begin(), a.end());
  assert(!dx);
}

vector<pair<long long, long long>> ans, ans1, ans2;

void solve() {
  long long g[2] = {0ll, 0ll}, r[2] = {0ll, 0ll};
  int odd[2] = {0, 0};
  for (int t = 0; t < 2; t++) {
    sort(a[t].begin(), a[t].end());
    for (int i = 0; i < 3; i++) {
      g[t] = gcd(g[t], a[t][i + 1] - a[t][i]);
    }
    if (!g[t]) {
      r[t] = a[t][0];
      continue;
    }
    r[t] = ((a[t][0] % g[t]) + g[t]) % g[t];
    for (int i = 0; i < 4; i++) {
      a[t][i] = (a[t][i] - r[t]) / g[t];
      odd[t] += (a[t][i] & 1);
    }
  }
  if (g[0] != g[1] || r[0] != r[1] || odd[0] != odd[1]) {
    printf("-1\n");
    return;
  }
  if (!g[0]) {
    printf("0\n");
    return;
  }
  ans.clear();
  ans1.clear();
  shrink(a[0], ans);
  shrink(a[1], ans2);
  if (a[0][0] <= a[1][0]) {
    shift(a[0], a[1][0] - a[0][0], ans1);
    for (int i = 0; i < sz(ans1); i++) {
      ans.push_back(ans1[i]);
    }
  } else {
    shift(a[1], a[0][0] - a[1][0], ans1);
    for (int i = sz(ans1) - 1; i >= 0; i--) {
      long long x = ans1[i].first, y = ans1[i].second;
      ans.push_back(make_pair(2 * y - x, y));
    }
  }
  for (int i = 0; i < 4; i++) {
    assert(a[0][i] == a[1][i]);
  }
  for (int i = sz(ans2) - 1; i >= 0; i--) {
    long long x = ans2[i].first, y = ans2[i].second;
    ans.push_back(make_pair(2 * y - x, y));
  }
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    long long x = ans[i].first, y = ans[i].second;
    x = x * g[0] + r[0];
    y = y * g[0] + r[0];
    printf("%lld %lld\n", x, y);
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