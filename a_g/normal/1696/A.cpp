#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, z;
    cin >> n >> z;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    int ans = 0;
    for (int x: a) ans = max(ans, x|z);
    cout << ans << '\n';
  }
}