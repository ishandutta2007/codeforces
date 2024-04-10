#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

void solve() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  while (n && m && n + m > 2) {
    if (n > m) {
      ans++;
      n-=2;
      m--;
    } else {
      ans++;
      n--;
      m-=2;
    }
  }
  cout << ans << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}