#include <bits/stdc++.h>

using namespace std;

typedef double ld;
typedef long long ll;

struct cplx {
  ld a, b;

  cplx (ld a = 0, ld b = 0) : a(a), b(b) {}
  
  const cplx operator + (const cplx &c) const {
    return cplx(a + c.a, b + c.b);
  }

  const cplx operator - (const cplx &c) const {
    return cplx(a - c.a, b - c.b);
  }

  const cplx operator * (const cplx &c) const {
    return cplx(a * c.a - b * c.b, a * c.b + b * c.a);
  }

  const cplx conj() const {
    return cplx(a, -b);
  }
};

const ld PI = acosl(-1);
const int N = (1 << 20) + 5;

int rev[N]; cplx w[N];

void prepare (int n) { 
  int sz = __builtin_ctz(n);
  for (int i = 1; i < n; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (sz - 1));
  w[0] = 0, w[1] = 1, sz = 1; 
  while (1 << sz < n) {
    ld ang = 2 * PI / (1 << (sz + 1));
    cplx w_n = cplx(cosl(ang), sinl(ang));
    for (int i = 1 << (sz - 1); i < (1 << sz); ++i) {
      w[i << 1] = w[i], w[i << 1 | 1] = w[i] * w_n; 
    } ++sz;
  }
}

void fft (cplx *a, int n) { 
  for (int i = 1; i < n - 1; ++i) { 
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  for (int h = 1; h < n; h <<= 1) {
    for (int s = 0; s < n; s += h << 1) {
      for (int i = 0; i < h; ++i) {
        cplx &u = a[s + i], &v = a[s + i + h], t = v * w[h + i];
        v = u - t, u = u + t;
      }
    }
  }
}

static cplx f[N], g[N], u[N], v[N];

void multiply (int *a, int *b, int n, int m) {
  int sz = n + m - 1; 
  while (sz & (sz - 1)) sz = (sz | (sz - 1)) + 1;
  prepare(sz);
  for (int i = 0; i < sz; ++i) f[i] = cplx(i < n ? a[i] : 0, i < m ? b[i] : 0);
  fft(f, sz);
  for (int i = 0; i <= (sz >> 1); ++i) {
    int j = (sz - i) & (sz - 1); 
    cplx x = (f[i] * f[i] - (f[j] * f[j]).conj()) * cplx(0, -0.25); 
    f[j] = x, f[i] = x.conj(); 
  }
  fft(f, sz); 
  for(int i = 0; i < sz; ++i) a[i] = f[i].a / sz + 0.5; 
}

bitset <N> ok;
int n, x, y, q, a[N], b[N], ans[N];

int main() {
  cin >> n >> x >> y;
  for (int i = 0, val; i <= n; ++i) {
    scanf("%d", &val);
    a[val] = b[x - val] = 1;
  }
  multiply(a, b, x + 1, x + 1);
  for (int i = x + 1; i <= x + x; ++i) {
    if (a[i]) ok[y + i - x] = 1;
  }
  for (int i = 1; i < N; ++i) {
    if (ok[i]) for (int j = i; j < N; j += i) {
      ans[j] = max(ans[j], i);
    }
  }
  cin >> q;
  while (q--) {
    int x; scanf("%d", &x); x >>= 1;
    printf("%d ", ans[x] ? 2 * ans[x] : -1);
  }
  cout << '\n';
  return 0;
}