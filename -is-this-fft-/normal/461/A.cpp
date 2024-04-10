#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_N = 3e5 + 5;

ll arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (ll) (i + 2) * arr[i];
  }
  ans -= arr[n - 1];

  cout << ans << endl;
}