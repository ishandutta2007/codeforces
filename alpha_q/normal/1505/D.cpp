#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  set <int> vis;
  while (n) {
    if (vis.count(n % m)) {
      cout << "NO\n";
      return 0;
    }
    vis.emplace(n % m);
    n /= m;
  }
  cout << "YES\n";
  return 0;
}