#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll arr [MAX_N];
ll pref [MAX_N];
ll suff [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, k;
  ll x;
  cin >> n >> k >> x;

  ll mul = 1;
  for (int i = 0; i < k; i++) {
    mul *= x;
  }

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] | arr[i];
  }

  for (int i = n; i >= 1; i--) {
    suff[i] = suff[i + 1] | arr[i];
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, (mul * arr[i]) | pref[i - 1] | suff[i + 1]);
  }
  cout << ans << endl;
}