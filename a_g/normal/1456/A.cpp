#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, p, k, x, y;
    string s;
    cin >> n >> p >> k >> s >> x >> y;
    p--;
    vector<int> missing(k);
    for (int i = p; i < n; i++) {
      if (s[i] == '0') missing[i%k]++;
    }
    int ans = 1e9;
    for (int i = 0; i < n-p; i++) {
      ans = min(ans, y*i+x*missing[(p+i)%k]);
      if (s[p+i] == '0') missing[(p+i)%k]--;
    }
    cout << ans << '\n';
  }
}