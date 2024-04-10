#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, z;
    cin >> n >> z;
    int mx = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mx = max(mx, x | z);
    }
    cout << mx << '\n';
  }
}