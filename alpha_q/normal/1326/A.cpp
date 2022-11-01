#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 1) cout << "-1\n";
    else {
      for (int i = 1; i < n; ++i) putchar('7');
      cout << "8\n";
    }
  }
  return 0;
}