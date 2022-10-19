#include <bits/stdc++.h>
using namespace std;

const int N = 1e9;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    auto check = [&] (int target) {
      if (target > N) return false;
      vector<int> b = a;
      int steps = 0;
      for (int& x: b) {
        if (2*x < target) {
          steps++;
          x = N;
        }
      }
      bool ok = 0;
      for (int i = 0; i < n-1; i++) {
        if (b[i] >= target && b[i+1] >= target) {
          ok = 1;
        }
      }
      if (!ok) {
        steps++;
        if (*max_element(b.begin(), b.end()) < target) steps++;
      }
      return (steps <= k);
    };

    int low = 0;
    int high = N+1;
    while (high-low > 1) {
      int mid = (low+high)/2;
      if (check(mid)) low = mid;
      else high = mid;
    }
    cout << low << '\n';
  }
}