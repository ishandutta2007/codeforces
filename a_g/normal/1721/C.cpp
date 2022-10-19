#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x: a) cin >> x;
    for (int& x: b) cin >> x;
    int z = 0;
    for (int i = 0; i < n; i++) {
      while (b[z] < a[i]) z++;
      cout << b[z]-a[i] << ' ';
    }
    cout << '\n';
    vector<int> c(n);
    for (int i = n-1; i >= 0; i--) {
      c[i] = (i == n-1 ? n-1 : c[i+1]);
      if (i < n-1 && a[i+1] > b[i]) c[i] = i;
    }
    for (int i = 0; i < n; i++) {
      cout << b[c[i]]-a[i] << ' ';
    }
    cout << '\n';
  }
}