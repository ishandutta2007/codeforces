#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << ((k >= (r-1)/2- l/2+1) || (l == r && l > 1) ? "YES" : "NO") << '\n';
  }
}