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
    for (int i = 0; i < n; i++) cin >> a[i];
    bool win = 1;
    for (int i = 2; i < n; i += 2) {
      if (a[i]%2 != a[0] % 2) win = 0;
    }
    for (int i = 1; i < n; i += 2) {
      if (a[i]%2 != a[1] % 2) win = 0;
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}