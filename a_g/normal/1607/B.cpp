#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long x, n;
    cin >> x >> n;
    for (long long j = 4*(n/4)+1; j <= n; j++) {
      if (x & 1) x += j;
      else x -= j;
    }
    cout << x << '\n';
  }
}