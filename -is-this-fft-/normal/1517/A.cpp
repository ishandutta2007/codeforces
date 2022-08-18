#include <iostream>

using namespace std;

typedef long long ll;

void solve () {
  ll n;
  cin >> n;

  if (n % 2050 != 0) {
    cout << -1 << '\n';
    return;
  }
  
  n /= 2050;
  int ans = 0;
  while (n != 0) {
    ans += n % 10;
    n /= 10;
  }
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}