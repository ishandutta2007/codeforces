#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    bool win = 0;
    vector<pair<int, int>> balls(n);
    for (int i = 0; i < n; i++) cin >> balls[i].first >> balls[i].second;
    for (pair<int, int>& x: balls) {
      bool good = 1;
      for (pair<int, int>& y: balls) {
        if (abs(x.first-y.first) + abs(x.second - y.second) > k) good = 0;
      }
      if (good) win = 1;
    }
    cout << (win ? 1 : -1) << '\n';
  }
}