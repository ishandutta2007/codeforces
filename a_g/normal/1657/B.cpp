#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, B, x, y;
    cin >> n >> B >> x >> y;
    long long ans = 0;
    int a = 0;
    for (int i = 1; i <= n; i++) {
      if (a+x <= B) {
        a += x;
      }
      else a -= y;
      ans += a;
    }
    cout << ans << '\n';
  }
}