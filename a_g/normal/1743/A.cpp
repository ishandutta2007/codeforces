#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
    }
    int k = 10-n;
    cout << 3*k*(k-1) << '\n';
  }
}