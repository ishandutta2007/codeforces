#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define a first
#define c second

const int MAX_N = 1e5 + 5;

pair<ll, ll> arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].a >> arr[i].c;
    ans += arr[i].c;
  }

  sort(arr, arr + n);

  ll mxac = 0;
  for (int i = 0; i < n; i++) {
    if (i != 0 && mxac < arr[i].a) {
      ans += arr[i].a - mxac;
    }
    mxac = max(mxac, arr[i].a + arr[i].c);
  }

  cout << ans << '\n';
}