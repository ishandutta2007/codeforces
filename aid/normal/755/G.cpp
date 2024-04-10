#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef double ld;

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

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int mod = 998244353;

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int base = (int) 5e4;

struct comp {
  ld x, y;

  comp(ld _x = 0, ld _y = 0): x(_x), y(_y) {}

  comp operator + (const comp &z) const {
    return comp(x + z.x, y + z.y);
  }

  comp operator - (const comp &z) const {
    return comp(x - z.x, y - z.y);
  }

  comp operator * (const comp &z) const {
    return comp(x * z.x - y * z.y, x * z.y + y * z.x);
  }

  comp conj() const {
    return comp(x, -y);
  }
};

int k;

namespace FFT {
  const int maxn = (1 << 17);
  int n, logn;
  int wasn = -1;
  int rev[maxn];

  comp w[maxn];

  void fft(comp a[]) {
    if (wasn != n) {
      wasn = n;
      rev[0] = 0;
      w[1] = 1;
      comp cur;
      for (int i = 1, j = -1; i < n; i++) {
        if (!(i & (i - 1))) {
          j++;
          cur = comp(cos(pi / 2 / i), sin(pi / 2 / i));
        }
        rev[i] = (rev[i ^ (1 << j)] ^ (1 << (logn - 1 - j)));
        if (2 * i < n) {
          w[2 * i] = w[i];
          w[2 * i + 1] = w[i] * cur;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (i < rev[i]) {
        swap(a[i], a[rev[i]]);
      }
    }
    for (int k = 1; k < n; k <<= 1) {
      for (int i = 0; i < n; i += k) {
        int pos = k;
        for (int it = 0, j = i + k; it < k; it++, j++, i++) {
          comp toadd = a[j] * w[pos++];
          a[j] = a[i] - toadd;
          a[i] = a[i] + toadd;
        }
      }
    }
  }

  comp a[maxn];

  vector<int> mul(const vector<int> &a0, const vector<int> &a1) {
    for (n = 1, logn = 0; n < sz(a0) + sz(a1) - 1; n <<= 1, logn++) ;
    assert(n <= maxn);
    vector<int> res;
    for (int it0 = 0; it0 < 2; it0++) {
      for (int it1 = 0; it1 < 2; it1++) {
        for (int i = 0; i < n; i++) {
          int c0 = (i < sz(a0) ? (!it0 ? a0[i] % base : a0[i] / base) : 0);
          int c1 = (i < sz(a1) ? (!it1 ? a1[i] % base : a1[i] / base) : 0);
          a[i] = comp(c0, c1);
        }
        fft(a);
        a[n] = a[0];
        for (int i = 0; i <= n - i; ++i) {
          a[i] = (a[i] * a[i] - (a[n - i] * a[n - i]).conj()) * comp(0, (ld) -1 / n / 4);
          a[n - i] = a[i].conj();
        }
        for (int i = 0; i < n; i++) {
          a[i] = a[i].conj();
        }
        fft(a);
        for (int i = 0; i < n; i++) {
          long long val = ((long long) round(a[i].x)) % mod;
          if (val) {
            if (sz(res) < i + 1) {
              res.resize(i + 1);
            }
            for (int j = 0; j < it0 + it1; j++) {
              val = val * base % mod;
            }
            add(res[i], val);
          }
        }
      }
    }
    if (sz(res) > k) {
      res.resize(k);
    }
    return res;
  }
};

void add(vector<int> &a, const vector<int> &b) {
  if (sz(b) > sz(a)) {
    a.resize(sz(b));
  }
  for (int i = 0; i < sz(b); i++) {
    add(a[i], b[i]);
  }
}

int n;

int read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  k++;
  return true;
}

vector<int> v[2], u[2];
vector<int> a[2][2], b[2][2];

void solve() {
  v[0].clear();
  v[0].push_back(1);
  v[1].clear();
  v[1].push_back(1);
  v[1].push_back(1);
  a[0][0].clear();
  a[0][1].clear();
  a[0][1].push_back(1);
  a[1][0].clear();
  a[1][0].push_back(0);
  a[1][0].push_back(1);
  a[1][1].clear();
  a[1][1].push_back(1);
  a[1][1].push_back(1);
  for (int i = 0; i < 2; i++) {
    if (sz(v[i]) > k) {
      v[i].resize(k);
    }
    for (int j = 0; j < 2; j++) {
      if (sz(a[i][j]) > k) {
        a[i][j].resize(k);
      }
    }
  }
  while (n) {
    if (n & 1) {
      for (int i = 0; i < 2; i++) {
        u[i].clear();
        for (int j = 0; j < 2; j++) {
          add(u[i], FFT::mul(a[i][j], v[j]));
        }
      }
      swap(v, u);
    }
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        b[i][j].clear();
        for (int l = 0; l < 2; l++) {
          add(b[i][j], FFT::mul(a[i][l], a[l][j]));
        }
      }
    }
    swap(a, b);
    n >>= 1;
  }
  for (int i = 1; i < k; i++) {
    int res = (i < sz(v[0]) ? v[0][i] : 0);
    printf("%d ", res);
  }
  printf("\n");
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