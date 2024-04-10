#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ldb long double

#define endl '\n'

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

int n;
vector<int> arr;
vector<int> tree;

void build(int v, int l, int r) {
  if (l + 1 == r) {
    tree[v] = arr[l];
  } else {
    int m = l + (r - l) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
    tree[v] = gcd(tree[2 * v + 1], tree[2 * v + 2]);
  }
}

void update(int v, int l, int r, int ind, int x) {
  if (ind < l || ind >= r)
    return;
  if (l + 1 == r) {
    tree[v] = x;
  } else {
    int m = l + (r - l) / 2;
    update(2 * v + 1, l, m, ind, x);
    update(2 * v + 2, m, r, ind, x);
    tree[v] = gcd(tree[2 * v + 1], tree[2 * v + 2]);
  }
}

int find(int v, int l, int r, int ql, int qr, int x) {
  if (l >= qr || r <= ql) {
    return -1;
  }
  if (ql <= l && r <= qr) {
    if (tree[v] % x == 0) {
      return r;
    }
  }
  if (l + 1 == r) {
    return l;
  }
  int m = l + (r - l) / 2;
  int a = find(2 * v + 1, l, m, ql, qr, x);
  if (a == m || a == -1) {
    int b = find(2 * v + 2, m, r, ql, qr, x);
    if (b != -1)
      a = b;
  }
  return a;
}

void solve() {
  cin >> n;
  arr.resize(n);
  tree.resize(4 * n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  build(0, 0, n);
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      int r1 = (arr[l] % x != 0) ? l : find(0, 0, n, l, n, x);
      if (r1 >= r || r1 + 1 == n) {
        cout << "YES" << endl;
      } else {
        int r2 = find(0, 0, n, r1 + 1, n, x);
        if (r2 >= r) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      }
    } else {
      int i, x;
      cin >> i >> x;
      i--;
      arr[i] = x;
      update(0, 0, n, i, x);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--)
    solve();
}