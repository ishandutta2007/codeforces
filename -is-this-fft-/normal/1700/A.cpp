#include <iostream>

using namespace std;

typedef long long ll;

void solve () {
  int n, m;
  cin >> n >> m;

  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += i;
  }
  for (int i = 2 * m; i <= n * m; i += m) {
    ans += i;
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}