#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> s(n), f(n);
    for (int& x: s) cin >> x;
    for (int& x: f) cin >> x;
    int time = 0;
    for (int i = 0; i < n; i++) {
      time = max(time, s[i]);
      int d = f[i]-time;
      cout << d << ' ';
      time += d;
    }
    cout << '\n';
  }
}