#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    string rods;
    cin >> n >> q >> rods;
    vector<int> partials(n+1, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int sign = 1-2*(i&1);
      sum += (rods[i] == '+') ? sign : -sign;
      partials[i+1] = sum;
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      if (!((r^l)&1)) {
        cout << 1 << '\n';
      }
      else {
        cout << (partials[r] == partials[l-1] ? 0 : 2) << '\n';
      }
    }
  }
}