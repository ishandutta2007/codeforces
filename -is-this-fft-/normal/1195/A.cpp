#include <iostream>

using namespace std;

const int MAX_K = 1e3 + 5;

int cnt [MAX_K];

int main () {
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    cnt[x]++;
  }

  int ans = 0;
  int odd = 0;
  for (int i = 1; i <= k; i++) {
    ans += 2 * (cnt[i] / 2);
    if (cnt[i] % 2 == 1) {
      if (odd == 0) {
        ans++;
        odd = 1;
      } else {
        odd = 0;
      }
    }
  }

  cout << ans << endl;
}