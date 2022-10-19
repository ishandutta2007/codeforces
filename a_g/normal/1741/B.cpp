#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n == 3) {
      cout << "-1\n";
      continue;
    }
    if (n == 2) {
      cout << "2 1\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      int k = (i+2)%n;
      cout << k+1 << ' ';
    }
    cout << '\n';
  }
}