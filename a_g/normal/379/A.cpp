#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int a, b;
  cin >> a >> b;
  int c = 0;
  int ans = 0;
  while (a) {
    ans += a;
    c += a;
    a = c/b;
    c -= b*(c/b);
  }
  cout << ans << '\n';
}