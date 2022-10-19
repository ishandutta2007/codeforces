#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  multiset<int> bb;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    bb.insert(b[i]);
  }
  set<int> xx;
  for (int i = 0; i < n; i++) {
      xx.insert((b[i] - a[0] + m) % m);
  }
  for (int x : xx) {
    multiset<int> aa;
    for (int el : a) {
      aa.insert((el + x) % m);
    }
    if (aa == bb) {
      cout << x << endl;
      return;
    }
  }
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}