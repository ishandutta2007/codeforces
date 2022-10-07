#include <bits/stdc++.h>

void solve() {
  long long x, n;
  std::cin >> x >> n;
  long long d = 0;
  if (n % 4 == 0) {
    d = 0;
  } else if (n % 4 == 1) {
    d = n;
  } else if (n % 4 == 2) {
    d = -1;
  } else {
    d = -1 - n;
  }
  if (x % 2 == 0) {
    d = -d;
  }
  std::cout << x + d << "\n";
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
}