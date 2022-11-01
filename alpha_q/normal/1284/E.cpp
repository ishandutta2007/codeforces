#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <ll, ll> point;
 
#define x first
#define y second
 
const int N = 2505;
 
int n; point p[N], org;
 
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    vector <point> v;
    for (int j = 0; j < n; ++j) if (j ^ i) {
      v.emplace_back(p[j].x - p[i].x, p[j].y - p[i].y);
    }
    sort(v.begin(), v.end(), [] (point a, point b) {
      bool x = a > org, y = b > org;
      return x == y ? a.x * b.y > a.y * b.x : x < y;
    });
    int m = n - 1;
    for (int j = 0; j < m; ++j) v.emplace_back(v[j]);
    for (int j = 0, k = 0; j < m; ++j) {
      while (k < j + m and v[j].x * v[k].y >= v[j].y * v[k].x) ++k;
      ll cur = k - j; ans += (cur - 1) * (cur - 2) * (cur - 3);
    }
  }
  ans /= 6, ans = (ll) n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24 - ans;
  cout << ans << '\n';
  return 0;
}