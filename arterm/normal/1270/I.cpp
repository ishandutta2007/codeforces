#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

int k;

struct Field {
  int n, m;
  vector<ll> a;

  Field(int n, int m)
    : n(n),
      m(m),
      a(n * m)
  { }

  ll* operator[](int x) {
    return a.data() + (x * m);
  }

  const ll* operator[](int x) const {
    return a.data() + (x * m);
  }

  Field flip() {
    Field res(m, n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        res[j][i] = a[i * m + j];
    return res;
  }
};

struct Figure {
  int n, m;
  set<pair<int, int>> s;

  Figure(int n, int m)
    : n(n),
      m(m)
  { }

  void add(int x, int y) {
    assert(0 <= x && x < n);
    assert(0 <= y && y < m);

    auto p = make_pair(x, y);
    if (s.count(p))
      s.erase(p);
    else
      s.insert(p);
  }

  Figure flip() const {
    Figure res(m, n);
    for (auto e : s)
      res.s.emplace(e.second, e.first);
    return res;
  }

  Figure bend() const {
    assert(n > 0);
    Figure res(n / 2, m);
    for (auto e : s)
      res.add(e.first % (n / 2), e.second);
    return res;
  }
};

void apply(Field &a, const Field &b, const Figure &f) {
  int n = a.n;
  int m = a.m;
  
  assert(b.n == n);
  assert(b.m == m);
  assert(f.n == n);
  assert(f.m == m);

  //int mi = n - 1;
  //int mj = (1 << m) - 1;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (b[i][j])
        for (auto e : f.s)
          a[(i + e.first) % n][(j + e.second) % m] ^= b[i][j];
}

Field solve(Field a, Figure f) {
  int n = a.n;
  int m = a.m;

  assert(f.n == n);
  assert(f.m == m);

  assert(f.s.size() % 2 == 1);

  //cerr << n << " " << m << "\n";

  bool flip = false;

  if (n < m) {
    a = a.flip();
    f = f.flip();
    swap(n, m);
    flip = true;
  }

  if (n == 1) {
    if (flip)
      return a.flip();
    return a;
  }

  Field ans(n, m);

  Field x(n / 2, m);
  for (int i = 0; i < (n / 2); ++i)
    for (int j = 0; j < m; ++j)
      x[i][j] = a[i][j] ^ a[i + (n / 2)][j];

  Figure xf = f.bend();

  Field xsol = solve(x, xf);
  for (int i = 0; i < (n / 2); ++i)
    for (int j = 0; j < m; ++j)
      ans[i][j] = xsol[i][j];

  apply(a, ans, f);

  for (int i = 0; i < n / 2; ++i)
    for (int j = 0; j < m; ++j) {
      //cerr << "ij " << i << " " << j << " with n = " << n << ", m = " << m << "\n";
      assert(a[i][j] == a[i + (n / 2)][j]);
    }


  Field y(n / 2, m);
  for (int i = 0; i < (n / 2); ++i)
    for (int j = 0; j < m; ++j)
      y[i][j] = a[i][j];

  Field ysol = solve(y, xf);
  for (int i = 0; i < n / 2; ++i)
    for (int j = 0; j < m; ++j) {
      ans[i][j] ^= ysol[i][j];
      ans[i + (n / 2)][j] ^= ysol[i][j];
    }

  if (flip)
    return ans.flip();
  return ans;
}


int main() {
#ifdef LOCAL
  assert(freopen("i.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  cin >> k;
  k = 1 << k;
  Field A(k, k);
  for (int i = 0; i < k; ++i)
    for (int j = 0; j < k; ++j)
      cin >> A[i][j];

  Figure f(k, k);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    f.s.emplace(x, y);
  }


  Field ans = solve(A, f);
  int res = 0;
  for (int i = 0; i < k; ++i)
    for (int j = 0; j < k; ++j)
      if (ans[i][j] != 0)
        ++res;
  cout << res << "\n";
}