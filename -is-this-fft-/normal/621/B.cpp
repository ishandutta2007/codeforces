#include <iostream>

const int MAX_DIAG = 4005;

using namespace std;

long long cnt [2][MAX_DIAG];

int main () {
  int bishopc;
  cin >> bishopc;

  for (int i = 0; i < bishopc; i++) {
    int r, c;
    cin >> r >> c;
    cnt[0][((r - c) + MAX_DIAG) % MAX_DIAG]++;
    cnt[1][r + c]++;
  }

  long long ans = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < MAX_DIAG; j++) {
      ans += cnt[i][j] * (cnt[i][j] - 1) / 2;
    }
  }

  cout << ans << endl;
}