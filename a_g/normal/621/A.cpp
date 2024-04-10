#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int minodd = 1e9;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    ans += val;
    if (val & 1) minodd = min(minodd, val);
  }
  if (ans & 1) ans -= minodd;
  cout << ans << endl;
}