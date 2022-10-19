#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;

ll M;
int N, L;
vector <int> prob;
vector <int> fact, ifact;
vector <int> inv, sgn;
vector <int> trans;
int root, iroot;

void load() {
  scanf("%d%lld", &N, &M);
  prob.resize(N + 1);
  for (auto &it : prob)
    scanf("%d", &it);
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
  return (ll)x * y % MOD;
}

inline void mult(int &x, int y) {
  x = mul(x, y);
}

int pot(int x, int y) {
  int res = 1;
  for (; y; y /= 2) {
    if (y % 2)
      mult(res, x);
    mult(x, x);
  }
  return res;
}

int inverse(int x) {
  return pot(x, MOD - 2);
}

void rec(vector <int> &a, int omega, int coef) {
  int n = a.size();
  if (n == 1)
    return;
  vector <int> even(n / 2), odd(n / 2);
  for (int i = 0; i < n / 2; i++) {
    even[i] = a[2 * i];
    odd[i] = a[2 * i + 1];
  }
  int nxt = mul(omega, omega);
  rec(even, nxt, coef);
  rec(odd, nxt, coef);
  int curr = 1;
  for (int i = 0; i < n / 2; i++) {
    int tmp = mul(odd[i], curr);
    a[i] = mul(add(even[i], tmp), coef);
    a[i + n / 2] = mul(add(even[i], -tmp), coef);
    mult(curr, omega);
  }
}

void ntt(vector <int> &a, bool invert) {
  a.resize(L);
  if (invert)
    rec(a, iroot, inv[2]);
  else
    rec(a, root, 1);
}

void conv(bool flip) {
  for (int i = 0; i <= N; i++) {
    mult(prob[i], fact[i]);
    if (flip)
      mult(prob[i], sgn[i]);
  }
  reverse(prob.begin(), prob.end());
  ntt(prob, false);
  for (int i = 0; i < L; i++)
    mult(prob[i], trans[i]);
  ntt(prob, true);
  prob.resize(N + 1);
  reverse(prob.begin(), prob.end());
  for (int i = 0; i <= N; i++) {
    mult(prob[i], ifact[i]);
    if (flip)
      mult(prob[i], sgn[i]);
  }
}

void init() {
  L = 1;
  while (L <= N)
    L *= 2;
  L *= 2;
  root = pot(3, (MOD - 1) / L);
  iroot = inverse(root);
  inv.resize(N + 1);
  sgn.resize(N + 1);
  fact.resize(N + 1);
  ifact.resize(N + 1);
  sgn[0] = fact[0] = ifact[0] = 1;
  for (int i = 1; i <= N; i++) {
    inv[i] = inverse(i);
    sgn[i] = add(0, -sgn[i - 1]);
    fact[i] = mul(fact[i - 1], i);
    ifact[i] = mul(ifact[i - 1], inv[i]);
  }
  inv.push_back(inverse(N + 1));
  trans = ifact;
  ntt(trans, false);
}

void solve() {
  conv(false);
  M %= MOD - 1;
  for (int i = 0; i <= N; i++) 
    mult(prob[i], pot(inv[i + 1], M));
  conv(true);
  for (auto it : prob)
    printf("%d ", it);
  puts("");
}

int main() {
  load();
  init();
  solve();
  return 0;
}