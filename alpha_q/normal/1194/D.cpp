#include <bits/stdc++.h>

using namespace std;

int t, n, k;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (k % 3) {
      cout << (n % 3 ? "Alice" : "Bob") << '\n';
    } else {
      n %= (k + 1);
      if (n == k) cout << "Alice\n";
      else cout << (n % 3 ? "Alice" : "Bob") << '\n';
    }
  }
  return 0;
}