#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MOD = 998244353;
const int LOG = 17;

int N;
int stair[MAXN];
int pw[MAXN], ipw[MAXN];
int fact[MAXN], ifact[MAXN];
vector <int> mat_pw[LOG][2][2];
vector <vector <int>> poly;

void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%d", stair + i);
}

inline int add(int x, int y) {
  x += y;
  if (x >= MOD)
    return x - MOD;
  if (x < 0)
    return x + MOD;
  return x;
}

inline int mul(int x, int y) {
  return (long long)x * y % MOD;
}

int pot(int x, int y) {
  int res = 1;
  for (; y; y /= 2) {
    if (y % 2)
      res = mul(res, x);
    x = mul(x, x);
  }
  return res;
}

int inverse(int x) {
  return pot(x, MOD - 2);
}

int choose(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

void ntt(vector <int> &a, int omega, int coef) {
  int n = a.size();
  if (n == 1)
    return;
  vector <int> even(n / 2), odd(n / 2);
  for (int i = 0; i < n / 2; i++) {
    even[i] = a[2 * i];
    odd[i] = a[2 * i + 1];
  }
  int curr = 1;
  int nxt = mul(omega, omega);
  ntt(even, nxt, coef);
  ntt(odd, nxt, coef);
  for (int i = 0; i < n / 2; i++) {
    int tmp = mul(odd[i], curr);
    a[i] = mul(add(even[i], tmp), coef);
    a[i + n / 2] = mul(add(even[i], -tmp), coef);
    curr = mul(curr, omega);
  }
}

vector <int> operator *(vector <int> a, vector <int> b) {
  int L = 1;
  int D = (int)a.size() + (int)b.size() - 1;
  while (L < D)
    L *= 2;
  a.resize(L);
  b.resize(L);
  int root = pot(3, (MOD - 1) / L);
  ntt(a, root, 1);
  ntt(b, root, 1);
  for (int i = 0; i < L; i++)
    a[i] = mul(a[i], b[i]);
  ntt(a, inverse(root), (MOD + 1) / 2);
  a.resize(D);
  return a;
}

vector <int> operator +(vector <int> a, vector <int> b) {
  int sz = max(a.size(), b.size());
  a.resize(sz);
  b.resize(sz);
  vector <int> c(sz);
  for (int i = 0; i < sz; i++)
    c[i] = add(a[i], b[i]);
  return c;
}

void operator +=(vector <int> &a, vector <int> b) {
  a = a + b;
}

void mat_mul(vector <int> a[2][2], vector <int> b[2][2], vector <int> c[2][2]) {
  for (int i = 0; i < 2; i++)
    for (int k = 0; k < 2; k++)
      for (int j = 0; j < 2; j++)
        c[i][j] += a[i][k] * b[k][j];
}

void mat_pot(vector <int> a[2][2], int ex) {
  a[0][0] = a[1][1] = {1};
  a[0][1] = a[1][0] = {0};
  for (int i = 0; i < LOG; i++)
    if (ex >> i & 1) {
      vector <int> tmp[2][2];
      mat_mul(a, mat_pw[i], tmp);
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          a[j][k] = tmp[j][k];
    }
}

vector <int> rec(int lo, int hi) {
  if (hi - lo == 1)
    return poly[lo];
  int mid = (lo + hi) / 2;
  return rec(lo, mid) * rec(mid, hi);
}

void init() {
  fact[0] = 1;
  for (int i = 1; i <= N; i++)
    fact[i] = mul(fact[i - 1], i);
  ifact[N] = inverse(fact[N]);
  for (int i = N - 1; i >= 0; i--)
    ifact[i] = mul(ifact[i + 1], i + 1);
  pw[0] = ipw[0] = 1;
  for (int i = 1; i <= N; i++) {
    pw[i] = mul(pw[i - 1], 2);
    ipw[i] = mul(ipw[i - 1], (MOD + 1) / 2);
  }
  mat_pw[0][0][0] = {0, ipw[1]};
  mat_pw[0][0][1] = {0, 1};
  mat_pw[0][1][0] = mat_pw[0][1][1] = {1};
  for (int i = 1; i < LOG; i++)
    mat_mul(mat_pw[i - 1], mat_pw[i - 1], mat_pw[i]);
}

int solve() {
  vector <int> seq;
  for (int pos = 0; pos < N; pos += stair[pos]) {
    seq.push_back(stair[pos] == 1);
    for (int i = 0; i < stair[pos]; i++)
      if (pos + i >= N || stair[pos + i] != stair[pos])
        return 0;
  }
  int K = seq.size();
  int deg = K - 1, lft;
  for (int i = 0; i < K; i++)
    if (seq[i]) {
      if (!i || !seq[i - 1])
        lft = i;
      if (i == K - 1 || !seq[i + 1]) {
        int lft_end = !lft;
        int rig_end = i == K - 1;
        int len = i - lft + 2 - lft_end - rig_end;
        vector <int> curr[2][2];
        mat_pot(curr, len);
        vector <int> ways[2];
        for (int j = 0; j < 2; j++)
          ways[j] = curr[j][!lft_end];
        if (rig_end)
          for (auto &it : ways[0])
            it = mul(it, ipw[1]);
        poly.push_back(ways[0] + ways[1]);
        deg -= len;
      }
    }
  vector <int> rest(deg + 1);
  for (int i = 0; i <= deg; i++)
    rest[i] = choose(deg, i);
  poly.push_back(rest);
  int sol = 0;
  vector <int> prod = rec(0, poly.size());
  for (int i = 0; i < K; i++) {
    int tmp = mul(mul(fact[K - i], pw[K - i]), prod[K - 1 - i]);
    sol = add(sol, i % 2 ? -tmp : tmp);
  }
  return sol;
}

int main() {
  load();
  init();
  printf("%d\n", solve());
  return 0;
}