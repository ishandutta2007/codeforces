#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  long long s, x;
  cin >> s >> x;
  if (s%2 != x%2 || s < x) {
    cout << "0\n";
    return 0;
  }
  long long y = (s-x)/2; // a&b
  if (x&y) {
    cout << "0\n";
    return 0;
  }
  long long ans = 1LL<<__builtin_popcountll(x);
  if (y == 0) ans -= 2;
  cout << ans << '\n';
}