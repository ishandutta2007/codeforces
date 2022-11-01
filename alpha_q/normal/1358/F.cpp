#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector <ll> a, b;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  a.resize(n), b.resize(n);
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
  if (n == 1) {
    puts(a == b ? "SMALL\n0" : "IMPOSSIBLE");
    return 0;
  }
  if (a == b) {
    puts("SMALL\n0");
    return 0;
  }
  vector <ll> c = b; reverse(c.begin(), c.end());
  if (a == c) {
    puts("SMALL\n1\nR");
    return 0;
  }
  if (n == 2) {
    c = a;
    vector <ll> d = b;
    if (c[0] > c[1]) swap(c[0], c[1]);
    if (d[0] > d[1]) swap(d[0], d[1]);
    ll sec = 0;
    while (true) {
      if (c == d) break;
      if (c[0] == d[0]) {
        if (d[1] > c[1] and (d[1] - c[1]) % d[0] == 0) {
          sec += (d[1] - c[1]) / d[0];
          break;
        } else {
          puts("IMPOSSIBLE");
          return 0;
        }
      }
      sec += d[1] / d[0], d[1] %= d[0], swap(d[0], d[1]);
      if (d[0] == 0) {
        puts("IMPOSSIBLE");
        return 0;
      }
    }
    if (sec > 200000) {
      puts("BIG"); cout << sec << '\n';
      return 0;
    }
  }
  int sec = 0;
  string ans = "";
  while (true) {
    if (a == b) break;
    c = b; reverse(c.begin(), c.end());
    if (a == c) {
      ans += 'R'; break;
    }
    if (b[0] > b.back()) ans += 'R', reverse(b.begin(), b.end());
    ans += 'P', ++sec;
    for (int i = n - 1; i; --i) b[i] -= b[i - 1];
    for (int i = 0; i < n; ++i) if (b[i] <= 0) {
      puts("IMPOSSIBLE");
      return 0;
    }
  }
  if (sec > 200000) {
    puts("BIG"); cout << sec << '\n';
  } else {
    reverse(ans.begin(), ans.end());
    puts("SMALL"); cout << ans.size() << '\n'; puts(ans.c_str());
  }
  return 0;
}