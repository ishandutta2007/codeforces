#include <iostream>

using namespace std;

const int MOD = 998244353;
typedef long long ll;

const int MAX_N = 2e5 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int last = -1;
  ll ans1 = 0, ans2 = 1;
  for (int i = 0; i < n; i++) {
    if (arr[i] > n - k) {
      ans1 += arr[i];
      if (last != -1) {
	ans2 *= (ll) (i - last);
	ans2 %= MOD;
      }
      last = i;
    }
  }

  cout << ans1 << " " << ans2 << endl;
}