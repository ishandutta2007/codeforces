#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> lack(31);
    for (int i = 0; i < n; i++) {
      long long a;
      cin >> a;
      for (int j = 0; j < 31; j++) {
        if (!(a&(1LL<<j))) {
          lack[j]++;
        }
      }
    }
    long long ans = 0;
    for (int j = 30; j >= 0; j--) {
      if (k >= lack[j]) {
        ans += 1LL<<j;
        k -= lack[j];
      }
      else if (lack[j] == 0) {
        ans += 1LL<<j;
      }
    }
    cout << ans << '\n';
  }
}