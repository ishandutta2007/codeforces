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
      for (int j = 0; j < n; j++) {
        int val = 0;
        if (i == j) val = 1;
        if (j == (i+1)%n) val = 4;
        cout << val << ' ';
      }
      cout << '\n';
    }
  }
}