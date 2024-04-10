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

void solve() {
  int n;
  cin >> n;
  vector<pt> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].x >> arr[i].y;
  }
  ldb ans = 1e18;
  for (int i = 0; i < n; i++) {
    auto a = line(arr[i], arr[(i + 2) % n]);
    auto p = arr[(i + 1) % n];
    ldb d = (a[0] * p.x + a[1] * p.y + a[2]) / sqrt(a[0] * a[0] + a[1] * a[1]);
    d = abs(d);
    ans = min(ans, d);
  }
  cout.precision(20);
  cout << ans / 2 << endl;
}

signed main() {
  int t;
  t = 1;
  while (t--)
    solve();
}