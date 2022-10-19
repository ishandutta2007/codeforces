#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), f(n+1);
    for (int& x: a) cin >> x;
    for (int& x: b) cin >> x;
    bool win = 1;
    while (a.size()) {
      while (b.size() && a.back() == b.back()) {
        f[b.back()]++;
        b.pop_back();
      }
      if (f[a.back()] <= 0) {
        win = 0;
        break;
      }
      f[a.back()]--;
      a.pop_back();
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}