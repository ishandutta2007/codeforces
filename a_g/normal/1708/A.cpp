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
    bool good = 1;
    for (int i = 1; i < n; i++) {
      if (a[i]%a[0] != 0) good = 0;
    }
    cout << (good ? "YES" : "NO") << '\n';
  }
}