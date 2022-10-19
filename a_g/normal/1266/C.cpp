#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int r, c;
  cin >> r >> c;
  if (r+c == 2) {
    cout << "0\n";
    return 0;
  }
  if (c == 1) {
    for (int i = 1; i <= r; i++) {
      cout << i+1 << '\n';
    }
    return 0;
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cout << i*(r+j) << " \n"[j==c];
    }
  }
}