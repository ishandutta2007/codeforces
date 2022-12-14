#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m; cin >> n >> m;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  vector<int> coef;
  coef.push_back(b[0]);
  for(int i = 1; i < n; i++) {
    coef.push_back(a[i]);
    coef.push_back(b[i]);
  }
  coef.push_back(a[0]);
  

  double low = 0, high = 2e9, ans = -1;
  for(int rep = 0; rep < 100; rep++) {
    double mid = (low + high) / 2.0;
    double fuel = mid;
    bool good = true;
    for(int x : coef) {
      fuel -= (fuel + m) / x;
      if(fuel < 0) {
        good = false;
        break;
      }
    }
    if(good) {
      ans = mid;
      high = mid;
    }else {
      low = mid;
    }
  }

  printf("%.20f\n", ans);
}