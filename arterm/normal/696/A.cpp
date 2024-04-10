#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

map<ll, ll> cost;

ll len(ll x) {
  ll ans = 0;
  while (x) {
    x >>= 1;
    ++ans;
  }
  return ans;
}

vector<ll> path(ll u, ll v) {
  if (len(u) > len(v))
    swap(u, v);

  vector<ll> ans;

  while (len(v) > len(u)) {
    ans.push_back(v);
    v >>= 1;
  }

  ll x = v, y = u;
  while (x != y) {
    ans.push_back(x);
    ans.push_back(y);
    x >>= 1;
    y >>= 1;
  }

  return ans;
}

void kill() {
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      ll u, v, w;
      cin >> u >> v >> w;
      for (ll x : path(u, v))
        cost[x] += w;
    }

    if (type == 2) {
      ll u, v;
      cin >> u >> v;
      ll ans = 0;
      for (ll x : path(u, v))
        ans += cost[x];
      cout << ans << "\n";
    }
  }
      
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  kill();
}