#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int target = *max_element(a.begin(), a.end());

    function<long long(int)> calc = [&] (int target) {
      vector<int> b = a;
      for (int i = 0; i < n; i++) {
        b[i] = target-b[i];
      }
      long long low = -1;
      long long high = 1e15;
      while (high-low > 1) {
        long long mid = (low+high)/2;
        long long twos = mid/2;
        long long ones = (mid+1)/2;
        bool good = 1;
        for (int val: b) {
          int x = min<long long>(twos, val/2);
          twos -= x;
          val -= 2*x;
          int y = min<long long>(ones, val);
          ones -= y;
          val -= y;
          if (val) {
            good = 0;
            break;
          }
        }
        if (good) high = mid;
        else low = mid;
      }
      return high;
    };

    cout << min(calc(target), calc(target+1)) << '\n';
  }
}