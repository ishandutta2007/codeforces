#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll a, b, c;
    cin >> a >> b >> c;
    int ans = ((a&1)^(c&1));
    cout << ans << endl;
  }
}