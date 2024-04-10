#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c0 = count(s.begin(), s.end(), '0');
    int c1 = count(s.begin(), s.end(), '1');
    if (c1 > c0) {
      reverse(s.begin(), s.end());
      for (char& c: s) c = '0'+'1'-c;
      swap(c0, c1);
    }
    vector<int> p(c0+1);
    int x = 0;
    for (int i = 0; i < n; i++) {
      x += (s[i] == '0' ? 1 : -1);
      if (x >= 0) p[x] = i+1;
    }
    int ans = 0;
    int cur = 0;
    while (cur < n && s[cur] == '0') cur++;
    while (cur < c0) {
      ans++;
      if (cur >= c0-c1) break;
      cur = (cur+p[cur])/2;
    }
    cout << ans << '\n';
  }
}