#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;
const ll INF = 9e18 + 5;

int n, m, k; 
ll ta, tb, a[N], b[N];

int main() {
  cin >> n >> m >> ta >> tb >> k;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%lld", b + i);
  }
  if (k >= n) {
    puts("-1"); 
    return 0;
  }
  ll ans = -INF;
  for (int i = 0, j = 1; i <= k; ++i) {
    int rem = k - i;
    ll cur = a[i + 1] + ta;
    while (j <= m and b[j] < cur) ++j;
    if (j + rem > m) {
      puts("-1");
      return 0;
    }
    ans = max(ans, b[j + rem] + tb);
  }
  cout << ans << endl;
  return 0;
}