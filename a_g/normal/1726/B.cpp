#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    if (m < n) {
      cout << "No\n";
      continue;
    }
    if (n&1) {
      cout << "Yes\n";
      for (int i = 0; i < n-1; i++) {
        cout << "1 ";
      }
      cout << m-n+1 << '\n';
      continue;
    }
    if (m&1) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
    for (int i = 0; i < n-2; i++) {
      cout << "1 ";
    }
    int x = (m-n+2)/2;
    cout << x << ' ' << x << '\n';
  }
}