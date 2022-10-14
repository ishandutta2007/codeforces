#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector <int> x, y;
    for (int i = 0, a, b; i < n * 2; ++i) {
      cin >> a >> b;
      if (a == 0) y.push_back(abs(b));
      else x.push_back(abs(a));
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    double ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += sqrt(1ll * x[i] * x[i] + 1ll * y[i] * y[i]);
    }
    cout << fixed << setprecision(10) << ans << endl;
  }
}