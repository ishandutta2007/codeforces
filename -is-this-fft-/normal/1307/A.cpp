#include <iostream>

using namespace std;

const int MAX_N = 105;

int arr [MAX_N];

void solve () {
  int n, d;
  cin >> n >> d;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int ans = arr[0];
  for (int j = 1; j < n; j++) {
    while (arr[j] > 0 && d >= j) {
      d -= j;
      arr[j]--;
      ans++;
    }
  }
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}