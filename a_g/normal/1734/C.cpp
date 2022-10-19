#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j+=i) {
        if (s[j-1] == '1') break;
        if (s[j-1] == '0') {
          ans += i;
          s[j-1] = '2';
        }
      }
    }
    cout << ans << '\n';
  }
}