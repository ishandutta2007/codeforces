#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    m++;
    ll ans = 0;
    for (int i = 31; i >= 0; i--) {
      int a = (n>>i)&1;
      int b = (m>>i)&1;
      if (a == 1 && b == 0) break;
      ans ^= (a^b)*(1<<i);
    }
    cout << ans << endl;
  }
}