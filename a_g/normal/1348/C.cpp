#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    sort(s.begin(), s.end());
    if (s[0] != s[k-1] || n == k) {
      cout << s[k-1] << '\n';
      continue;
    }
    cout << s[k-1];
    s = s.substr(k);
    if (count(s.begin(), s.end(), s[0]) == n-k) {
      cout << string((n-1)/k, s[0]) << '\n';
      continue;
    }
    cout << s  << '\n';
  }
}