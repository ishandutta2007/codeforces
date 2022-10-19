#include <bits/stdc++.h>
using namespace std;

// structure of possible sign assignments
// the number of positives is congruent to (2-n) mod 3
// when n is odd, we must exclude the +-+-+-+ case

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  vector<long long> as(n+1);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    as[i+1] = as[i] + a[i].first;
  }
  if (n == 1) {
    cout << a[0].first << '\n';
    return 0;
  }

  long long ans = -1e18;
  for (int pos = 2-n%3; pos <= n; pos += 3) {
    long long val = as[n]-2*as[n-pos];
    if (n&1 && pos == (n+1)/2) {
      vector<bool> take(n);
      for (int i = 0; i < pos; i++) {
        take[a[n-1-i].second] = 1;
      }
      bool good = 0;
      for (int i = 0; i < n; i++) {
        if (take[i] != 1-(i&1)) {
          good = 1;
          break;
        }
      }
      if (good) {
        ans = max(ans, val);
      }
      else {
        ans = max(ans, val-2*(a[pos-1].first-a[pos-2].first));
      }
    }
    else {
      ans = max(ans, val);
    }
  }

  cout << ans << '\n';
}