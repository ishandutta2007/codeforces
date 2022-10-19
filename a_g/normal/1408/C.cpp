#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(8);
  int T;
  cin >> T;
  while (T--) {
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto calc1 = [&] (double time) {
      int pos = 0;
      for (int i = 0; i < n; i++) {
        // speed = i+1
        double del = (double)(a[i]-pos)/(i+1);
        if (del > time) {
          return pos + (i+1)*time;
        }
        else {
          time -= del;
          pos = a[i];
        }
      }
      return pos+(n+1)*time;
    };

    auto calc2 = [&] (double time) {
      int pos = l;
      for (int i = 0; i < n; i++) {
        // speed = i+1
        double del = (double)(pos-a[n-1-i])/(i+1);
        if (del > time) {
          return pos - (i+1)*time;
        }
        else {
          time -= del;
          pos = a[n-1-i];
        }
      }
      return pos-(n+1)*time;
    };
  
    double low = 0;
    double high = 1e9;
    while (abs(high-low) > 1e-7) {
      double mid = (low+high)/2;
      if (calc1(mid) > calc2(mid)) {
        high = mid;
      }
      else low = mid;
    }
    cout << (low+high)/2 << '\n';
  }
}