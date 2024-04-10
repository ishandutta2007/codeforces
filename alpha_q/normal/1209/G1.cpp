#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

vector <int> v;
bitset <N> vis;
vector <pair <int, int>> ran, dis;
int n, q, a[N], b[N], sz[N], tot, mn[N], mx[N];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    v.emplace_back(a[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  tot = v.size();
  for (int i = 1; i <= tot; ++i) {
    mn[i] = 69696969, mx[i] = -69696969;
  }
  for (int i = 1; i <= n; ++i) {
    a[i] = 1 + lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    ++sz[a[i]], mn[a[i]] = min(mn[a[i]], i), mx[a[i]] = max(mx[a[i]], i);
  }
  for (int i = 1; i <= tot; ++i) {
    ran.emplace_back(mn[i], mx[i]);
  }
  sort(ran.begin(), ran.end());
  int l = ran[0].first, r = ran[0].second;
  for (int i = 0; i < ran.size(); ++i) {
    if (ran[i].first > r) {
      dis.emplace_back(l, r);
      l = ran[i].first, r = ran[i].second;
    } else {
      r = max(r, ran[i].second);
    }
    if (i + 1 == ran.size()) dis.emplace_back(l, r);
  }
  int ans = 0;
  for (auto it : dis) {
    int sum = 0, mxx = 0;
    for (int i = it.first; i <= it.second; ++i) {
      if (vis[a[i]]) continue;
      vis[a[i]] = 1, sum += sz[a[i]], mxx = max(mxx, sz[a[i]]);
    }
    ans += sum - mxx;
  }
  cout << ans << '\n';
  return 0;
}