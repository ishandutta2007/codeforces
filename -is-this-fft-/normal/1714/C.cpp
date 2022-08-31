#include <iostream>
#include <vector>

using namespace std;

const int INF = 2e9 + 5;

int ans [46];

int main () {
  for (int i = 1; i <= 45; i++) {
    ans[i] = INF;
  }
  
  for (int mask = 1; mask < 1 << 10; mask++) {
    int val = 0, sum = 0;
    for (int k = 0; k < 10; k++) {
      if (mask & 1 << k) {
        val *= 10;
        val += k;
        sum += k;
      }
    }

    ans[sum] = min(ans[sum], val);
  }

  ios::sync_with_stdio(false);
  cin.tie(0);

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int x;
    cin >> x;

    cout << ans[x] << '\n';
  }
}