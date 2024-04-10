#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
  li n, k;
  cin >> n >> k;

  vector<li> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  vector<li> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = (i ? p[i - 1] : 0) + a[i];
  }

  if (k <= n) {
    li ms = 0;
    for (int i = 0; i + k - 1 < n; ++i) {
      li s = p[i + k - 1] - (i ? p[i - 1] : 0);
      ms = max(ms, s);
    }

    cout << ms + k * (k - 1) / 2 << "\n";
  } else {
    li s = p.back();
    //cout << "?\n";

    s += (k - n + k - 1) * n / 2;
    cout << s << "\n";
  }
}

int main() {
  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //while (true) solve(false);

  return 0;
}