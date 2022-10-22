#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve () {
  int n;
  cin >> n;

  vector<ll> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  cout << arr[n - 1] + arr[n - 2] - arr[0] - arr[1] << '\n';
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