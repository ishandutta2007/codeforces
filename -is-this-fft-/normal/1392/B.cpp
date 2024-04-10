#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_N = 2e5 + 5;

ll arr [MAX_N];

void solve () {
  int n;
  cin >> n;
  ll K;
  cin >> K;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  if (K % 2 == 1) {
    for (int i = 0; i < n; i++) {
      arr[i] *= -1;
    }
  }

  ll mn = 1e18 + 5;
  for (int i = 0; i < n; i++) {
    mn = min(mn, arr[i]);
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] - mn << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}