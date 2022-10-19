#include <bits/stdc++.h>
using namespace std;

// source: https://codeforces.com/contest/1588/submission/135350810

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    long long ans = 0;
    long long s = 0;
    int sign = 1;
    map<long long, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      s += sign*x;
      // s = a_0-a_1+...+(-1)^ia_i
      if (sign == -1) {
        while (!m.empty() && m.begin()->first < s) m.erase(m.begin());
      }
      else {
        while (!m.empty() && m.rbegin()->first > s) m.erase(prev(m.end()));
      }
      ans += m[s];
      m[s]++;
      sign = -sign;
    }
    cout << ans << '\n';
  }
}