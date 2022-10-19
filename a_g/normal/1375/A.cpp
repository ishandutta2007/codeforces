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
      int b;
      cin >> b;
      cout << (i & 1 ? abs(b) : -abs(b)) << ' ';
    }
    cout << '\n';
  }
}