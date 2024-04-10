#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n+1);
    for (int i = 0; i < n; i++) cin >> a[i+1];
    auto check = [&] (int k) {
      vector<int> bad;
      int good = 0;
      if (d-a.back() > k) good++;
      for (int i = 0; i < n-1; i++) {
        if (a[i+2]-a[i] <= k) {
          return 0;
        }
      }
      for (int i = 0; i < n; i++) {
        if (a[i+1] - a[i] <= k) bad.push_back(i);
        if (a[i+1] - a[i] > 2*k+1) good++;
      }
      if (!bad.size()) return 1;
      if (bad.size() >= 3 || (bad.size() == 2 && bad[0]+1 != bad[1])) return 0;
      if (bad.size() == 1 && bad[0] > 0 && a[bad[0]+1]-a[bad[0]-1] > 2*k+1) return 1;
      if (bad.size() == 1 && bad[0] < n-1 && a[bad[0]+2]-a[bad[0]] > 2*k+1) return 1;
      if (bad.size() == 1 && bad[0] == n-1 && d - a[n-1] > k) return 1;
      if (!good) return 0;
      return 1;
    };

    int low = 0;
    int high = d;
    while (high-low > 1) {
      int mid = (low+high)/2;
      if (check(mid)) low = mid;
      else high = mid;
    }
    cout << low << '\n';
  }
}