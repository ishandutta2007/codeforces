#include <iostream>

using namespace std;

const int MAX_N = 310;
const int ZERO = 155;
const int INF = 1e9 + 5;

int arr [MAX_N][MAX_N];

int _dp [2 * MAX_N][MAX_N][MAX_N];
int &dp (int i, int j, int k) {
  if (i % 2 == 1) {
    j++;
    k++;
  }
  return _dp[i][j / 2 + ZERO][k / 2 + ZERO];
}

int range (int d, int n) {
  if (d < n) {
    return d;
  }

  return 2 * n - 2 - d;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < 2 * n - 1; i++) {
    int fin = range(i, n);
    int sta = -fin;
    for (int j = sta; j <= fin; j += 2) {
      for (int k = j; k <= fin; k += 2) {
        dp(i, j, k) = -INF;
      }
    }
  }

  dp(0, 0, 0) = 0;
  for (int i = 0; i < 2 * n - 1; i++) { // x + y
    int fin = range(i, n);
    int sta = -fin;
    for (int j = sta; j <= fin; j += 2) { // x - y
      for (int k = j; k <= fin; k += 2) {
        dp(i, j, k) += arr[(i + j) / 2][(i - j) / 2];
        if (j != k) {
          dp(i, j, k) += arr[(i + k) / 2][(i - k) / 2];
        }

        if (i != 2 * n - 2) {
          for (int a = -1; a <= 1; a += 2) {
            for (int b = -1; b <= 1; b += 2) {
              dp(i + 1, j + a, k + b) = max(dp(i + 1, j + a, k + b),
                                            dp(i, j, k));
            }
          }
        }
      }
    }
  }

  cout << dp(2 * n - 2, 0, 0) << endl;
}