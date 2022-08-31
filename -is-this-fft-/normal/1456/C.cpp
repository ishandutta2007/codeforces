#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 5e5 + 5;

ll arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, K;
  cin >> n >> K;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  ll ans = 0, csum = 0;
  for (int i = 0; i < n; i++) {
    ans += (ll) i * arr[i];
    csum += arr[i];
  }

  if (K == 0) {
    cout << ans << '\n';
    return 0;
  }

  ll cur = ans;
  for (int i = 0; i < n; i++) {
    csum -= arr[i];
    // remove i-th from main
    if (i % (K + 1) != 0) {
      cur -= (ll) (1 + (i / (K + 1))) * arr[i];
      cur -= csum;
      cur += (ll) (i / (K + 1)) * arr[i];
    }

    ans = max(ans, cur);
  }

  cout << ans << endl;
}