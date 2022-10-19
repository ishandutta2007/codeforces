#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  cout << fixed << setprecision(10);
  while (T--) {
    int n;
    cin >> n;
    vector<int> miners;
    vector<int> diamonds;
    for (int i = 0; i < 2*n; i++) {
      int x, y;
      cin >> x >> y;
      if (x == 0) miners.push_back(abs(y));
      else diamonds.push_back(abs(x));
    }
    sort(miners.begin(), miners.end());
    sort(diamonds.begin(), diamonds.end());
    double ans = 0;
    for (int i = 0; i < n; i++) {
      double x = miners[i];
      double y = diamonds[i];
      ans += sqrt(x*x+y*y);
    }
    cout << ans << endl;
  }
}