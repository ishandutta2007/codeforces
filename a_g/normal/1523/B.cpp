#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
    }
    cout << 3*n << '\n';
    for (int i = 1; i < n; i += 2) {
      for (int j = 0; j < 3; j++) {
        cout << "1 " << i << " " << i+1 << '\n';
        cout << "2 " << i << " " << i+1 << '\n';
      }
    }
  }
}