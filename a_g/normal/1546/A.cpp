#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), incr, decr;
    for (int& x: a) cin >> x;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] -= x;
      while (a[i] > 0) decr.push_back(i), a[i]--;
      while (a[i] < 0) incr.push_back(i), a[i]++;
    }
    if (incr.size() != decr.size()) {
      cout << "-1\n";
      continue;
    }
    cout << incr.size() << '\n';
    for (int i = 0; i < (int)incr.size(); i++) {
      cout << decr[i]+1 << ' ' << incr[i]+1 << '\n';
    }
  }
}