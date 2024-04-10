#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

struct builder {
  vector<pair<int, li>> p;
  int m;

  builder(int m): m(m) {}

  void add(int x) {
    li cnt = 1;
    while (x % m == 0) {
      x /= m;
      cnt *= m;
    }
    if (p.empty() || p.back().first != x) {
      p.emplace_back(x, cnt);
    } else {
      p.back().second += cnt;
    }
  }
};

void solve(bool read) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  int k;
  cin >> k;
  vector<int> b(k);
  for (int& x : b) cin >> x;

  auto build = [&](vector<int> v) {
    builder b(m);
    for (int x : v) {
      b.add(x);
    }
    return b.p;
  };

  auto ap = build(a);
  auto bp = build(b);
  cout << ((ap == bp) ? "Yes" : "No") << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  return 0;
}