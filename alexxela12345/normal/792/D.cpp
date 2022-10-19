#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ldb long double
#define pt pair<int, int>
#define x first
#define y second

vector<int> line(pt a, pt b) {
  vector<int> ans(3);
  ans[0] = a.y - b.y;
  ans[1] = b.x - a.x;
  ans[2] = -(a.x * ans[0] + a.y * ans[1]);
  return ans;
}

int from(int x, int sz, int v = 1) {
  if (x == (sz + 1) / 2) {
    return v;
  } else if (x < (sz + 1) / 2) {
    return from(x, (sz - 1) / 2, 2 * v);
  } else {
    return from(x - (sz + 1) / 2, (sz - 1) / 2, 2 * v + 1);
  }
}

int to(int v, int n, bool add = 1) {
  int ans = 0;
  if (add) {
    ans += (n - 1) / 2 + 1;
  }
  if (v == 1) {
    return ans;
  }
  if (v % 2 == 0) {
    return ans + to(v / 2, 2 * n + 1, 0);
  }
  return ans + to(v / 2, 2 * n + 1, 1);
}

void solve() {
  int n, q;
  cin >> n >> q;
  while (q--) {
    int v;
    cin >> v;
    v = from(v, n);
    string s;
    cin >> s;
    for (char c : s) {
      if (c == 'U') {
        if (v != 1) {
          v /= 2;
        }
      } else {
        if (2 * v <= n) {
          v *= 2;
          if (c == 'R')
            v++;
        }
      }
    }
    int cnt = 0;
    int vv = v;
    while (vv != 1) {
      vv /= 2;
      cnt++;
    }
    int x = n;
    for (int i = 0; i < cnt; i++) {
      x = (x - 1) / 2;
    }
    v = to(v, x);
    cout << v << endl;
  }
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}