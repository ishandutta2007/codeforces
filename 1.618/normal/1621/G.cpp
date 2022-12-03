/*
start thinking:
BULB:
result of thinking: Pure.

<> #dp

? ( luogu P2839 []middle )
.

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
const ll mod = 1000000007;
int n, a[maxn], sufmax[maxn];
// f(i): a[i]IS
// g(i): a[i]IS
// h(i): a[i]IS
ll ans[maxn], fbit[maxn], gbit[maxn], hbit[maxn];

void add(ll* bit, int pos, ll x) {
  for (int i = pos; i <= n; i += i & -i)
    (bit[i] += x) %= mod;
}
void clear(ll* bit, int pos) {
  for (int i = pos; i <= n; i += i & -i)
    bit[i] = 0;
}
ll qsum(ll* bit, int pos) {
  ll res = 0;
  for (int i = pos; i; i -= i & -i)
    (res += bit[i]) %= mod;
  return res;
}

vector<int> pos[maxn];

void compress() {
  vector<int> as;
  for (int i = 1; i <= n; i++) {
    as.push_back(a[i]);
  }
  sort(as.begin(), as.end());
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(as.begin(), as.end(), a[i]) - as.begin() + 1;
  }
}

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  compress();
  for (int i = 1; i <= n; i++) {
    pos[i].clear();
    ans[i] = fbit[i] = gbit[i] = 0;
  }
  for (int i = n; i >= 1; i--)
    pos[a[i]].push_back(i);
  vector<int> foo;
  sufmax[n] = a[n];
  for (int i = n - 1; i >= 1; i--) {
    sufmax[i] = sufmax[i + 1];
    if (chmax(sufmax[i], a[i]))
      foo.push_back(i);
  }
  for (int i = 1; i < a[n]; i++) {
    for (auto j : pos[i]) {
      ll f = qsum(fbit, j) + 1;
      add(fbit, j, f);
      add(gbit, j, qsum(gbit, j) + f);
    }
  }
  for (auto i : foo) {
    for (int j = sufmax[i + 1]; j < a[i]; j++) {
      for (auto k : pos[j]) {
        add(hbit, k, qsum(gbit, k) + qsum(hbit, k));
      }
    }
    ans[i] = (qsum(gbit, i) + qsum(hbit, i)) % mod;
    for (int j = sufmax[i + 1]; j < a[i]; j++) {
      for (auto k : pos[j]) {
        clear(hbit, k);
        ll f = qsum(fbit, k) + 1;
        add(fbit, k, f);
        add(gbit, k, qsum(gbit, k) + f);
      }
    }
  }
  if (foo.empty()) {
    for (auto i : pos[a[n]]) {
      ll f = qsum(fbit, i) + 1;
      add(fbit, i, f);
      add(gbit, i, qsum(gbit, i) + f);
    }
  } else {
    for (auto i : pos[a[foo.back()]]) {
      ll f = qsum(fbit, i) + 1;
      add(fbit, i, f);
      add(gbit, i, qsum(gbit, i) + f);
    }
  }
  for (int i = 1; i < n; i++) {
    if (sufmax[i] == sufmax[i + 1]) {
      ans[i] = (qsum(gbit, i) - qsum(gbit, i - 1)) % mod;
      if (a[i] == sufmax[i])
        (ans[i] -= qsum(fbit, i) - qsum(fbit, i - 1)) %= mod;
    }
  }
  int tot = 0;
  for (int i = 1; i <= n; i++)
    (tot += ans[i]) %= mod;
  printf("%lld\n", (tot + mod) % mod);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}