#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

void solve() {
  int w, h;
  cin >> w >> h;
  set<int> ans;

  auto checkBot = [&](int x) {
    if (x > h || x > w) {
      return false;
    }
    if (w % x == 0) {
      return (h - 2) % x == 0 || ((h - 1) % x == 0 && (w - 2) % x == 0);
    } else if (w % x == 1) {
      return (h - 1) % x == 0 || (h % x == 0 && (h - 2) % x == 0);
    }
    return false;
  };

  auto checkRight = [&](int x) {
    if (x > h || x > w) {
      return false;
    }
    if (h % x == 0) {
      return (w - 2) % x == 0 || ((w - 1) % x == 0 && (h - 2) % x == 0);
    } else if (h % x == 1) {
      return (w - 1) % x == 0 || (w % x == 0 && (w - 2) % x == 0);
    }
    return false;
  };

  auto check = [&](int x) {
    if (checkBot(x) || checkRight(x)) {
      ans.insert(x);
    }
  };

  auto brute = [&](int x) {
    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        check(i);
        check(x / i);
      }
    }
  };

  brute(h);
  brute(h - 1);
  brute(h - 2);

  cout << ans.size() << " ";
  for (int i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}