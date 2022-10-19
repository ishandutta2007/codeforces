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
    int cur = -1;
    int ans1 = 0;
    int ans2 = 1;
    for (int i = 0; i < n; i+=2) {
      if (s[i] != s[i+1]) {
        ans1++;
      }
      else {
        if (s[i]-'0' != cur) {
          if (cur != -1) ans2++;
          cur = s[i]-'0';
        }
      }
    }
    cout << ans1 << '\n';
  }
}