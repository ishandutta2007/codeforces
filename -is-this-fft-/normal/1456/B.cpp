#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5;
const int CUT = 100;

int arr [MAX_N];
int cum [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    cum[i] = cum[i - 1] ^ arr[i];
  }

  if (n >= CUT) {
    cout << 1 << '\n';
    return 0;
  }

  int ans = MAX_N;
  for (int l = 1; l <= n; l++) {
    for (int m = l + 1; m <= n; m++) {
      for (int r = m + 1; r <= n + 1; r++) {
        int lm = cum[m - 1] ^ cum[l - 1];
        int rm = cum[r - 1] ^ cum[m - 1];

        if (lm > rm) {
          ans = min(ans, m - l - 1 + r - m - 1);
        }
      }
    }
  }
  if (ans == MAX_N) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}