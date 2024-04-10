#include <iostream>

using namespace std;

const int MAX_N = 3e4 + 5;

typedef long long ll;

ll arr [MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll pos = 0;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i + 1] - arr[i] >= 0) {
      pos += arr[i + 1] - arr[i];
    }
  }

  ll neg = 0;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i + 1] - arr[i] <= 0) {
      neg -= arr[i + 1] - arr[i];
    }
  }

  if (pos <= arr[n - 1] && neg <= arr[0]) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}