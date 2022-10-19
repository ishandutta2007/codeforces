#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string b;
    cin >> n >> b;
    string ans;
    char prev = 'a';
    for (int i = 0; i < n; i++) {
      if ((char)(b[i]+1) != prev) ans.push_back('1');
      else ans.push_back('0');
      prev = b[i] + ans.back()-'0';
    }
    cout << ans << '\n';
  }
}