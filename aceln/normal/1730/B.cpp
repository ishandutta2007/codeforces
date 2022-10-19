#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &[x, y] : a)
      cin >> x;
    for (auto &[x, y] : a)
      cin >> y;

    auto f = [&](double z) {
      double ret = 0;
      for (auto [x, y] : a)
        ret = max(ret, y + abs(z - x));
      return ret;
    };

    double L = 0, R = 1e8;
    for (int i = 1; i <= 200; i++) {
      double M1 = (L + L + R) / 3, M2 = (L + R + R) / 3;
      double fM1 = f(M1), fM2 = f(M2);
      if (fM1 < fM2)
        R = M2;
      else
        L = M1;
    }

    cout << fixed << setprecision(15) << L << '\n';
  }
}