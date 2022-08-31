#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

map<ll, ll> wt;

void add (ll u, ll v, ll w) {
  while (u != v) {
    if (u < v) swap(u, v);
    if (wt.count(u) == 0) {
      wt[u] = 0;
    }
    wt[u] += w;
    u /= 2;
  }
}

ll get (ll u, ll v) {
  ll ans = 0;
  while (u != v) {
    if (u < v) swap(u, v);
    if (wt.count(u) == 0) {
      wt[u] = 0;
    }
    ans += wt[u];
    u /= 2;
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int t;
    cin >> t;

    if (t == 1) {
      ll u, v, w;
      cin >> u >> v >> w;

      add(u, v, w);
    } else {
      ll u, v;
      cin >> u >> v;

      cout << get(u, v) << '\n';
    }
  }
}