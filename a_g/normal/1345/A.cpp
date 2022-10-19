#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    if (m == 2 && n == 2) {
      cout << "YES\n";
      continue;
    }
    cout << (min(m, n) == 1 ? "YES" : "NO") << '\n';
  }
}