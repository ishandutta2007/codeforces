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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n&1) {
      cout << "NO\n";
      continue;
    }
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (int i = 0; i < n/2; i++) {
      b[2*i] = a[i];
      b[2*i+1] = a[i+n/2];
    }
    bool win = 1;
    for (int i = 0; i < n/2; i++) {
      if (b[2*i] >= b[2*i+1] || b[2*i] >= b[(2*i+n-1)%n]) win = 0;
    }
    if (!win) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int x: b) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}