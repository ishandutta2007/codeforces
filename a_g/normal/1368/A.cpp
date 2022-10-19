#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, n;
    cin >> a >> b >> n;
    if (a > b) swap(a, b);
    int ans = 0;
    while (b <= n) {
      a = a+b;
      swap(a, b);
      ans++;
    }
    cout << ans << '\n';
  }
}