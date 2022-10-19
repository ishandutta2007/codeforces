#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int K = 400300;
const int N = 2;
const int mod = 1e9 + 7;

int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

int mul(ll x, ll y) {
  return x * y % mod;
}

struct M {
  int a[2][2];

  M() {
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < 2; ++j)
        a[i][j] = 0;
  }

  int* operator[](int x) {
    return a[x];
  }

  const int* operator[](int x) const {
    return a[x];
  }

  M operator*(M const &o) const {
    M ans;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        for (int k = 0; k < N; ++k)
          ans[i][k] = add(ans[i][k], mul(a[i][j], o[j][k]));
    return ans;
  }

  M operator+(M const &o) const {
    M ans;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        ans[i][j] = add(a[i][j], o[i][j]);
    return ans;
  }
} I, T;

M bin(M A, int to) {
  M B = I;
  while (to) {
    if (to & 1)
      B = A * B;
    A = A * A;
    to >>= 1;
  }
  return B;
}

M a[K], b[K];
int n, x[K], m;

M val(int v) {
  return a[v] * b[v];
}

void upd(int v) {
  a[v] = val(2 * v) + val(2 * v + 1);
}

void push(int v, int l, int r) {
  a[v] = val(v);
  if (l + 1 != r) {
    b[2 * v] = b[2 * v] * b[v];
    b[2 * v + 1] = b[2 * v + 1] * b[v];
  }
  b[v] = I;
}

void build(int v, int l, int r) {
  b[v] = I;
  if (l + 1 == r) {
    a[v] = bin(T, x[l]);
    return;
  }

  int m = (l + r) / 2;
  build(2 * v, l, m);
  build(2 * v + 1, m, r);
  upd(v);
}

void upd(int v, int l, int r, int le, int re, M by) {
  push(v, l, r);

  if (l == le && r == re) {
    b[v] = by;
    return;
  }

  int m = (l + r) / 2;
  if (le < m)
    upd(2 * v, l, m, le, min(m, re), by);
  if (m < re)
    upd(2 * v + 1, m, r, max(le, m), re, by);

  upd(v);
}

M get(int v, int l, int r, int le, int re) {
  push(v, l, r);


  if (l == le && r == re)
    return val(v);

  M ans;
  int m = (l + r) / 2;
  if (le < m)
    ans = ans + get(2 * v, l, m, le, min(m, re));
  if (m < re)
    ans = ans + get(2 * v + 1, m, r, max(m, le), re);

  return ans;
}
    
  
void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> x[i];
}


void kill() {
  for (int i = 0; i < m; ++i) {
    int t, l, r;
    cin >> t >> l >> r;
    --l;

    if (t == 1) {
      int x;
      cin >> x;
      upd(1, 0, n, l, r, bin(T, x));
    }

    if (t == 2) {
      cout << get(1, 0, n, l, r)[0][1] << "\n";
    }
  }
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < N; ++i)
    I[i][i] = 1;

  T[0][0] = T[0][1] = T[1][0] = 1;

  read();
  build(1, 0, n);
  kill();
}