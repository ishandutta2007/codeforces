/**
 *    author:  tourist
 *    created: 27.05.2018 18:09:26       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> st(4 * n + 100);
  function<void(int,int,int,int,int,int)> modify = [&](int x, int l, int r, int ll, int rr, int v) {
    if (r < ll || rr < l) {
      return;
    }
    if (ll <= l && r <= rr) {
      st[x].push_back(v);
      return;
    }
    int y = (l + r) >> 1;
    if (ll <= y) {
      modify(x + x, l, y, ll, rr, v);
    }
    if (rr > y) {
      modify(x + x + 1, y + 1, r, ll, rr, v);
    }
  };
  for (int i = 0; i < q; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    l--; r--;
    modify(1, 0, n - 1, l, r, x);
  }
  bitset<N> ans;
  function<void(int,int,int,bitset<N>)> solve = [&](int x, int l, int r, bitset<N> b) {
    for (int v : st[x]) {
      b |= (b << v);
    }
    if (l == r) {
      ans |= b;
      return;
    }
    int y = (l + r) >> 1;
    solve(x + x, l, y, b);
    solve(x + x + 1, y + 1, r, b);
  };
  bitset<N> b;
  b.set(0);
  solve(1, 0, n - 1, b);
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 1) {
      res.push_back(i);
    }
  }
  int sz = (int) res.size();
  cout << sz << '\n';
  for (int i = 0; i < sz; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << res[i];
  }
  cout << '\n';
  return 0;
}