#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    int x = count(s.begin(), s.end(), 'A');
    int y = count(s.begin(), s.end(), 'B');
    if (a+c+d != x || b+c+d != y) {
      cout << "NO\n";
      continue;
    }

    int free = 0;
    vector<int> u, v;

    int cur = -1;
    int sz = 0;
    int start = -1;

    int n = a+b+2*c+2*d;
    auto calc = [&] () {
      int m = (start&1)^(cur);
      if (sz == 1) return;
      if (1-sz&1) {
        if (m == 1) u.push_back(sz/2);
        else v.push_back(sz/2);
        free += (sz/2)-1;
      }
      else free += (sz-1)/2;
    };
    for (int i = 0; i < n; i++) {
      int t = (s[i]=='A')^(i&1);
      if (t == cur) {
        sz++;
      }
      else {
        if (cur != -1) {
          calc();
        }
        start = i;
        sz = 1;
        cur = t;
      }
    }
    calc();
    sort(u.begin(), u.end(), greater<int>());
    sort(v.begin(), v.end(), greater<int>());
    while (u.size() && u.back() <= c) {
      int k = u.back();
      c -= k;
      free -= k-1;
      u.pop_back();
    }

    while (v.size() && v.back() <= d) {
      int k = v.back();
      d -= k;
      free -= k-1;
      v.pop_back();
    }

    cout << (free >= c+d ? "YES" : "NO") << '\n';
  }
}