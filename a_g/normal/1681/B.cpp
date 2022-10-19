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
    int m;
    cin >> m;
    int x = 0;
    while (m--) {
      int b;
      cin >> b;
      x = (x+b)%n;
    }
    cout << a[x] << '\n';
  }
}