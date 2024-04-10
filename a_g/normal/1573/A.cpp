#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
      if (s[i] > '0') {
        ans += s[i]-'0' + 1;
      }
    }
    ans += s[n-1] - '0';
    cout << ans << endl;
  }
}