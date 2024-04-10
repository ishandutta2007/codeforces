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
  vector<int> cnt(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cnt[a]++;
    cnt[b]++;
  }
  if (m == n - 1) {
    bool ok;
    ok = 1;
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (cnt[i] > 2) {
        ok = 0;
      } else if (cnt[i] == 1) {
        c++;
      }
    }
    if (c != 2) {
      ok = 0;
    }
    if (ok) {
      cout << "bus topology" << endl;
      return;
    }
    ok = 1;
    c = 0;
    for (int i = 0; i < n; i++) {
      if (cnt[i] > 1)
        c++;
    }
    if (c > 1)
      ok = 0;
    if (ok) {
      cout << "star topology" << endl;
      return;
    }
    cout << "unknown topology" << endl;
    return;
  }
  if (n == m) {
    for (int i = 0; i < n; i++) {
      if (cnt[i] != 2) {
        cout << "unknown topology" << endl;
        return;
      }
    }
    cout << "ring topology" << endl;
  } else {
        cout << "unknown topology" << endl;
  }
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}