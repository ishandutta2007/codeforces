#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int m, a, b;
  cin >> m >> a >> b;
  int g = __gcd(a, b);
  // sum from i = 0 to m/g of (m+1-g*i)
  int z = m/g;
  long long ans = 1LL*(m+1)*(z+1)-1LL*g*z*(z+1)/2;
  vector<int> residue_times(a, INF);
  int cur = 0;
  int t = 0;
  while (1) {
    t = max(t, cur);
    if (residue_times[cur%a] == INF) residue_times[cur%a] = t;
    if (cur >= b) cur -= b;
    else cur += a;
    if (cur == 0) break;
  }
  for (int z = 0; z <= a+b && z <= m; z += g) {
    // currently counted m+1-z times, should be counted m+1-t times
    int t = min(residue_times[z%a], m+1);
    ans -= 1LL*(max(z, t)-z);
  }
  cout << ans << '\n';
}