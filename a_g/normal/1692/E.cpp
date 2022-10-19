#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, s;
    cin >> n >> s;
    vector<int> p(n+1);
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      p[i+1] = p[i] + a;
    }
    if (p[n] < s) {
      cout << "-1\n";
      continue;
    }
    int ans = 0;

    for (int i = 0; i < n; i++) {
      auto it = upper_bound(p.begin(), p.end(), p[i]+s);
      ans = max<int>(ans, it-p.begin()-i-1);
    }
    cout << n-ans << '\n';
  }
}