#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    if (m == 1 && n == 1) {
      cout << "0\n";
      continue;
    }
    cout << m+n+min(m, n)-2 << '\n';
  }
}