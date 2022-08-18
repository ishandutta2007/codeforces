#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;

const int MAX_N = 1e5 + 5;

int arr [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, U;
  cin >> n >> U;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int curk = 2;
  ld ans = -1;
  for (int i = 0; i < n - 2; i++) {
    while (curk <= i + 1) curk++;

    while (curk + 1 < n && arr[curk + 1] - arr[i] <= U) {
      curk++;
    }

    if (arr[curk] - arr[i] <= U) {
      ld cur = (ld) (arr[curk] - arr[i + 1]) / (ld) (arr[curk] - arr[i]);
      ans = max(ans, cur);
    }
  }

  if (ans < -0.5) {
    cout << -1 << endl;
  } else {
    cout << fixed << setprecision(12) << ans << endl;
  }
}