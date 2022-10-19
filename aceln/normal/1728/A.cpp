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
    int mx = -1, idx = 0;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x > mx) {
        mx = x;
        idx = i;
      }
    }
    cout << idx << '\n';
  }
}