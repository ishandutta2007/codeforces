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

const int P = (int) 1e9, L = 9;
const int maxn = 2005;

struct Num {
  vector<int> a;

  Num() {}

  Num(const string &s) {
    for (int i = sz(s); i > 0; i -= L) {
      int cur = 0;
      int ii = max(i - L, 0);
      for (int j = ii; j < i; j++) {
        cur = cur * 10 + (s[j] - '0');
      }
      a.push_back(cur);
    }
    while (!a.empty() && !a.back()) {
      a.pop_back();
    }
  }

  int operator % (int k) const {
    int res = 0;
    for (int i = sz(a) - 1; i >= 0; i--) {
      res = ((long long) res * P + a[i]) % k;
    }
    return res;
  }

  void operator /= (int k) {
    long long carry = 0;
    for (int i = sz(a) - 1; i >= 0; i--) {
      carry = carry * P + a[i];
      a[i] = carry / k;
      carry %= k;
    }
    while (!a.empty() && !a.back()) {
      a.pop_back();
    }
  }
};

bitset<maxn> toBin(Num &x) {
  bitset<maxn> ans;
  const int k = 25;
  for (int i = 0; i < maxn; i += k) {
    int val = x % (1 << k);
    for (int j = 0; j < k; j++) {
      if (i + j < maxn) {
        ans[i + j] = ((val >> j) & 1);
      }
    }
    x /= (1 << k);
  }
  return ans;
}

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

bitset<maxn> a[maxn];
bitset<maxn> b[maxn];
int id[maxn];
char tmp[maxn];

void solve() {
  for (int i = 0; i < n; i++) {
    {
      scanf("%s", tmp);
      string s = tmp;
      Num x(s);
      a[i] = toBin(x);
      b[i].reset();
      b[i][i] = true;
    }
    for (int j = 0; j < i; j++) {
      if (id[j] == -1) {
        continue;
      }
      if (a[i][id[j]]) {
        a[i] ^= a[j];
        b[i] ^= b[j];
      }
    }
    id[i] = maxn - 1;
    while (id[i] >= 0 && !a[i][id[i]]) {
      id[i]--;
    }
    if (id[i] == -1) {
      vector<int> ans;
      for (int j = 0; j < i; j++) {
        if (b[i][j]) {
          ans.push_back(j);
        }
      }
      printf("%d ", sz(ans));
      for (int j = 0; j < sz(ans); j++) {
        printf("%d ", ans[j]);
      }
      printf("\n");
    } else {
      printf("0\n");
    }
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