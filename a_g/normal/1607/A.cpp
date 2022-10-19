#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> z;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string k;
    cin >> k;
    for (int i = 0; i < 26; i++) {
      z[k[i]] = i;
    }
    string s;
    cin >> s;
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n-1; i++) {
      ans += abs(z[s[i]]-z[s[i+1]]);
    }
    cout << ans << '\n';
  }
}