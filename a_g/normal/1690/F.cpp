#include <bits/stdc++.h>
using namespace std;

long long lcm(long long x, long long y) {
  return (x*y)/(__gcd(x, y));
}

int period(string& s) {
  int n = s.size();
  for (int i = 1; i <= n/2; i++) {
    if (n%i == 0) {
      bool good = 1;
      for (int j = i; j < n; j++) {
        if (s[j-i] != s[j]) {
          good = 0;
          break;
        }
      }
      if (good) return i;
    }
  }
  return n;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> p(n);
    for (int& x: p) {
      cin >> x;
      x--;
    }
    vector<bool> vis(n);
    long long ans = 1;
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      string part;
      int v = i;
      while (!vis[v]) {
        part.push_back(s[v]);
        vis[v] = 1;
        v = p[v];
      }
      ans = lcm(ans, period(part));
    }
    cout << ans << '\n';
  }
}