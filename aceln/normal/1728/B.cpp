#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      for (int i = n - 2; i >= 2; i--)
        cout << i << ' ';
      cout << 1 << ' ' << n - 1 << ' ' << n << '\n';
    } else {
      for (int i = n - 2; i >= 4; i--)
        cout << i << ' ';
      cout << 2 << ' ' << 3 << ' ' << 1 << ' ' << n - 1 << ' ' << n << '\n';
    }
  }
}