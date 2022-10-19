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
    int a = count(s.begin(), s.end(), '>');
    int b = count(s.begin(), s.end(), '<');
    if (a == 0 || b == 0) {
      cout << n << '\n';
      continue;
    }
    int ans = 0;
    s.push_back(s[0]);
    for (int i = 0; i < n; i++) {
      if (s[i] == '-' || s[i+1] == '-') ans++;
    }
    cout << ans << '\n';
  }
}