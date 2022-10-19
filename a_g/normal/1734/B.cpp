#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        cout << (j == 1 || j == i ? 1 : 0) << ' ';
      }
      cout << '\n';
    }
  }
}