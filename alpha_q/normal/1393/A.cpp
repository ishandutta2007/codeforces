#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    if (n & 1) {
      n >>= 1;
      cout << min(1 + 2 * (1 + n >> 1), 2 + 2 * (n >> 1)) << '\n';
    } else {
      n >>= 1;
      cout << 1 + (1 + n >> 1) + (n >> 1) << '\n';        
    }
  }
  return 0;
}