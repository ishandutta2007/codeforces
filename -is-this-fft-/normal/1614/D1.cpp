#include <iostream>

using namespace std;

typedef long long ll;

const int MAX_A = 5e6 + 5;

int cnt [MAX_A];
ll dp [MAX_A];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    for (int k = 1; k * k <= x; k++) {
      if (x % k == 0) {
        cnt[k]++;
        if (k * k != x) {
          cnt[x / k]++;
        }
      }
    }
  }

  for (int i = MAX_A - 1; i >= 1; i--) {
    dp[i] = (ll) i * (ll) cnt[i];
    for (int k = 2 * i; k < MAX_A; k += i) {
      dp[i] = max(dp[i], dp[k] + (ll) i * (ll) (cnt[i] - cnt[k]));
    }
  }

  cout << dp[1] << '\n';
}