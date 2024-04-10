#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
  int a, b;
  cin >> a >> b;
  int n = abs(a - b);
  int x = n / 5;
  n -= x * 5;
  int y = n / 2;
  n -= y * 2;
  cout << n + x + y << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}