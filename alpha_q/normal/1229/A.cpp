#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 7010;

int n;
ll a[N], b[N];
bitset <N> vis;
map <ll, int> freq;
vector <int> one, more;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);
    ++freq[a[i]];
  }
  for (int i = 0; i < n; ++i) {
    scanf("%lld", b + i);
  }
  ll ans = 0; int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (freq[a[i]] > 1) {
      more.emplace_back(i);
      ans += b[i], ++cnt;
    } else {
      one.emplace_back(i);
    }
  }
  for (auto it : freq) {
    if (it.second <= 1) continue;
    ll x = it.first;
    for (auto id : one) if ((x & a[id]) == a[id]) {
      vis[id] = 1;
    }
  }
  for (int i = 0; i < n; ++i) if (vis[i]) ans += b[i], ++cnt;
  if (cnt < 2) puts("0");
  else printf("%lld\n", ans);
  return 0;
}