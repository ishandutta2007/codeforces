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

const int maxn = (int) 1e5 + 5;
int lDiv[maxn], cDiv[maxn];
vector<int> pr;
int good[8][8][8];

void precalc() {
  for (int i = 2; i < maxn; i++) {
    if (!lDiv[i]) {
      lDiv[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < sz(pr) && pr[j] <= lDiv[i]; j++) {
      int x = pr[j] * i;
      if (x >= maxn) {
        break;
      }
      lDiv[x] = pr[j];
    }
  }
  cDiv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    int x = i;
    int p = 0;
    while (!(x % lDiv[i])) {
      x /= lDiv[i];
      p++;
    }
    cDiv[i] = cDiv[x] * (p + 1);
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        auto &cur = good[i][j][k];
        cur = false;
        vector<int> p = {0, 1, 2};
        while (true) {
          bool ok = true;
          for (int it = 0; it < 3; it++) {
            int x = (it == 0 ? i : (it == 1 ? j : k));
            if (!(x & (1 << p[it]))) {
              ok = false;
              break;
            }
          }
          if (ok) {
            cur = true;
            break;
          }
          if (!next_permutation(p.begin(), p.end())) {
            break;
          }
        }
      }
    }
  }
}

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
}

int a, b, c;

int read() {
  if (scanf("%d%d%d", &a, &b, &c) < 3) {
    return false;
  }
  return true;
}

int gs[8];
int cnt[8];

void solve() {
  int ab = gcd(a, b), bc = gcd(b, c), ac = gcd(a, c);
  int abc = gcd(ab, c);
  gs[0] = 1;
  gs[1] = a;
  gs[2] = b;
  gs[3] = ab;
  gs[4] = c;
  gs[5] = ac;
  gs[6] = bc;
  gs[7] = abc;
  for (int i = 0; i < 3; i++) {
    {
      auto &cur = cnt[1 << i];
      cur = cDiv[gs[1 << i]];
      for (int j = 0; j < 3; j++) {
        if (j == i) {
          continue;
        }
        cur -= cDiv[gs[(1 << i) + (1 << j)]];
      }
      cur += cDiv[gs[7]];
    }
    {
      auto &cur = cnt[7 - (1 << i)];
      cur = cDiv[gs[7 - (1 << i)]];
      cur -= cDiv[gs[7]];
    }
  }
  cnt[7] = cDiv[gs[7]];
  int res = 0;
  for (int i = 1; i < 8; i++) {
    for (int j = i; j < 8; j++) {
      for (int k = j; k < 8; k++) {
        if (!good[i][j][k]) {
          continue;
        }
        if (i == j) {
          if (j == k) {
            res += (cnt[i] + 2) * (cnt[i] + 1) * cnt[i] / 6;
          } else {
            res += ((cnt[i] + 1) * cnt[i] / 2) * cnt[k];
          }
        } else {
          if (j == k) {
            res += cnt[i] * ((cnt[j] + 1) * cnt[j] / 2);
          } else {
            res += cnt[i] * cnt[j] * cnt[k];
          }
        }
      }
    }
  }
  printf("%d\n", res);
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