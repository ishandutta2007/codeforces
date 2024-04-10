#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> x;
    int ans = x&(-x);
    if (ans == x) ans++;
    if (x == 1) ans = 3;
    cout << ans << '\n';
  }
}