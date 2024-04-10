#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const int N = 300010;

int n, m;
ll x[N], y[N];
vector <pair <ll, ll>> v;
ll diff[N], sx[N], sy[N], ans[N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", x + i, y + i);
    v.emplace_back(x[i] - y[i], i);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i) {
    diff[i + 1] = v[i].first;
    sx[i + 1] = x[v[i].second];
    sy[i + 1] = y[v[i].second];
    sx[i + 1] += sx[i];
    sy[i + 1] += sy[i];
    // cout << v[i].second << endl;
  }
  for (int i = 1; i <= n; ++i) {
    ll aa = y[i], bb = x[i];
    int pos = upper_bound(diff + 1, diff + n + 1, bb - aa) - diff - 1;
    // cout << pos << endl;
    ans[i] = pos * 1LL * aa + sx[pos] + (n - pos) * 1LL * bb + sy[n] - sy[pos];
    ans[i] -= (aa + bb);
  }
  while (m--) {
    int i, j;
    scanf("%d %d", &i, &j);
    ans[i] -= min(x[i] + y[j], x[j] + y[i]);
    ans[j] -= min(x[i] + y[j], x[j] + y[i]);
  }
  for (int i = 1; i <= n; ++i) {
    printf("%lld ", ans[i]);
  }
  puts("");
  return 0;
}