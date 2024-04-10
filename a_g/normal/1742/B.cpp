#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    sort(a.begin(), a.end());
    bool ok = 1;
    for (int i = 0; i+1 < n; i++) {
      if (a[i]==a[i+1]) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}