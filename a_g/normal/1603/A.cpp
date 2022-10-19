#include <bits/stdc++.h>
using namespace std;

long long lcm(long long x, long long y) {
  return x*y/__gcd(x, y);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long b = 1;
    bool win = 1;
    for (int i = 0; i < n; i++) {
      b = lcm(b, i+2);
      if (b > 1e9) break;
      if (a[i] % b == 0) win = 0;
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}