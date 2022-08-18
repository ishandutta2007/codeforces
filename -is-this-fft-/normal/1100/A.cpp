#include <iostream>

using namespace std;

const int MAX_N = 105;

int cnt [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  int tot = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    cnt[i % k] += x;
    tot += x;
  }

  int ans = 0;
  for (int i = 0; i < k; i++) {
    ans = max(ans, abs(tot - cnt[i]));
  }

  cout << ans << endl;
}