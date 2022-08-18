#include <iostream>

using namespace std;

typedef long long ll;

ll pc (ll x) {
  return (x * (x - 1)) / 2;
}

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, D;
  cin >> n >> D;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll ans = 0;
  int lptr = 0;
  for (int i = 0; i < n; i++) {
    while (arr[i] - arr[lptr] > D) {
      lptr++;
    }

    ans += pc(i - lptr);
  }

  cout << ans << endl;
}