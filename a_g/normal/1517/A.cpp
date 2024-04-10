#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    if (n%2050 != 0) {
      cout << "-1\n";
      continue;
    }
    n /= 2050;
    int ans = 0;
    while (n) {
      ans += n % 10;
      n /= 10;
    }
    cout << ans << '\n';
  }
}