#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int a = 2; a < n-2; a++) {
      if (__gcd(a, n-1) == 1) {
        cout << a << ' ' << n-1-a << ' ' << 1 << '\n';
        break;
      }
    }
  }
}