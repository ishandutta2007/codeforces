#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

int n; ll a[N], p[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    p[i] = p[i - 1] + a[i];
  }
  map <ll, int> last;
  last[0] = 0;
  int rightMost = 0;
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (last.find(p[i]) != last.end()) {
      rightMost = max(rightMost, last[p[i]] + 1);
    }
    last[p[i]] = i, ans += i - rightMost;
  }
  cout << ans << '\n';
  return 0;
}