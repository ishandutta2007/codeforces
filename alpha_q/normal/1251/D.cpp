#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define x first
#define y second

const int N = 200010;
const ll INF = 1e10 + 5;

int t, n; ll s;
pair <ll, ll> p[N];

bool ok (ll x) {
  ll tot = 0;
  vector <ll> vec;
  for (int i = 1; i <= n; ++i) {
    tot += p[i].x;
    if (p[i].y >= x) vec.emplace_back(max(x, p[i].x) - p[i].x);
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n / 2 + 1; ++i) tot += vec[i];
  return tot <= s;
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %lld", &n, &s);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld %lld", &p[i].x, &p[i].y);
    }
    ll lo, hi;
    sort(p + 1, p + n + 1, [] (pair <ll, ll> a, pair <ll, ll> b) {
      return a.y == b.y ? a.x < b.x : a.y < b.y;
    });
    hi = p[1 + n >> 1].y;
    sort(p + 1, p + n + 1);
    lo = p[1 + n >> 1].x;
    while (lo < hi) {
      ll mid = lo + hi + 1 >> 1;
      if (ok(mid)) lo = mid;
      else hi = mid - 1;
    }
    printf("%lld\n", lo);
  }
  return 0;
}