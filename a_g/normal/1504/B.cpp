#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector<int> sa(n+1), sb(n+1);
    for (int i = 0; i < n; i++) {
      sa[i+1] = sa[i] + (a[i] == '1' ? 1 : -1);
      sb[i+1] = sb[i] + (b[i] == '1' ? 1 : -1);
    }
    int r = n;
    while (sa[r] != 0) r--;
    bool good = 1;
    for (int i = 0; i <= n; i++) {
      if (abs(sa[i]) != abs(sb[i])) {
        good = 0;
        break;
      }
      if (sa[i] != sb[i] && i > r) {
        good = 0;
        break;
      }
    }
    cout << (good ? "YES" : "NO") << '\n';
  }
}