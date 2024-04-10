#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

ll arr [MAX_N];

bool can (ll cnt, int n) {
  ll buf = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] - cnt > 0) return false;
  }

  for (int i = 0; i < n; i++) {
    buf -= arr[i] - cnt;
    if (buf >= cnt) return true;
  }

  return buf >= cnt;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll ans = 0;
  for (ll k = 1LL << 60; k != 0; k /= 2) {
    if (!can(ans + k, n)) {
      ans += k;
    }
  }
  ans++;

  cout << ans << endl;
}