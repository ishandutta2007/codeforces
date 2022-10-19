#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> s >> k;
    set<char> z;
    for (int i = 0; i < k; i++) {
      char c;
      cin >> c;
      z.insert(c);
    }
    int pr = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (z.count(s[i])) {
        ans = max(ans, i-pr);
        pr = i;
      }
    }
    cout << ans << '\n';
  }
}