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
      for (int j = n; j >= i+2; j--) {
        cout << j << ' ';
      }
      cout << "1 ";
      for (int j = i+1; j >= 2; j--) {
        cout << j << ' ';
      }
      cout << '\n';
    }
  }
}