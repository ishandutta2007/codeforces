#line 2 "/Users/alex/Code/Templates/ds/binary-indexed-tree.hpp"

#include <vector>

namespace Quark {
template <typename T> struct BinaryIndexedTree {
  int N;
  std::vector<T> data;

  BinaryIndexedTree() = default;
  BinaryIndexedTree(int _n) { init(_n); }

  void init(int _n) {
    N = _n;
    data.assign(N + 1, {});
  }

  T sum(int k) const {
    if (k <= 0)
      return T{};
    T ret{};
    for (; k > 0; k -= k & -k) {
      ret += data[k];
    }
    return ret;
  }

  inline T sum(int l, int r) const { return sum(r) - sum(l); }

  inline T operator[](int k) const { return sum(k + 1) - sum(k); }

  void add(int k, T x) {
    for (++k; k <= N; k += k & -k) {
      data[k] += x;
    }
  }
};
}; // namespace Quark
#line 2 "/Users/alex/Code/Templates/template/template.hpp"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

namespace Quark {
void solve();
};

int main() { Quark::solve(); }
#line 3 "main.cpp"

namespace Quark {
void solve1() {
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<int> rev(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i]--;
    rev[arr[i]] = i;
  }
  BinaryIndexedTree<int> bit(n);
  bit.add(rev[0], 1);
  bit.add(rev[1], 1);
  ll ans = 0;
  for (int i = 2; i < n; i++) {
    // i - 1 to
    int pos1 = rev[i - 1] + 1;
    if (pos1 == n)
      pos1 = 0;
    int pos2 = rev[i];
    int d;
    if (pos1 <= pos2) {
      d = bit.sum(pos1, pos2);
    } else {
      d = bit.sum(pos1, n) + bit.sum(pos2);
    }
    bit.add(rev[i], 1);
    ans += (ll) d * (n - i);
  }
  cout << ans << endl;
}

void solve() {
  int t;
  cin >> t;
  while (t--) {
    solve1();
  }
}
} // namespace Quark