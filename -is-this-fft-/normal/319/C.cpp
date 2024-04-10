#include <iostream>
#include <set>
#include <cassert>
#include <climits>

using namespace std;

typedef long long ll;

// KACTL line container

struct Line {
  mutable ll k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  static const ll inf = LLONG_MAX;
  ll div(ll a, ll b) { // floored division
    return a / b - ((a ^ b) < 0 && a % b); }
  bool isect(iterator x, iterator y) {
    if (y == end()) return x->p = inf, 0;
    if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
    else x->p = div(y->m - x->m, x->k - y->k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    k *= -1; m *= -1;
    
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return -(l.k * x + l.m);
  }
};

const int MAX_N = 1e5 + 5;

ll A [MAX_N], B [MAX_N], dp [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }

  LineContainer lc;

  dp[0] = 0;
  lc.add(B[0], dp[0]);
  for (int i = 1; i < n; i++) {
    dp[i] = lc.query(A[i]);
    lc.add(B[i], dp[i]);
  }

  cout << dp[n - 1] << '\n';
}