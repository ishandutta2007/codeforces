#include <bits/stdc++.h>

using namespace std;

string s;
int t, n, sz[69];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    int zero = 0, one = 0;
    for (int i = 0; i < n; ++i) {
      cin >> s; sz[i] = s.size();
      for (int j = 0; j < s.size(); ++j) {
        if (s[j] == '0') ++zero;
        else ++one;
      }
    }
    sort(sz, sz + n);
    int ans = 0, pr = zero / 2 + one / 2;
    for (int i = 0; i < n; ++i) {
      int req = sz[i] / 2;
      if (req > pr) break;
      pr -= req, ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}