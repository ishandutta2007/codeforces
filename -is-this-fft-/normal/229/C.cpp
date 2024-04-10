#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_N = 1e6 + 5;

int deg [MAX_N];

ll sq (ll x) {
  return x * x;
}

ll cb (ll x) {
  return x * sq(x);
}

ll sqsq (ll x) {
  return sq(sq(x));
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    u--; v--;

    deg[u]++;
    deg[v]++;
  }

  ll K = 0;
  for (int i = 0; i < n; i++) {
    K += sq(deg[i]);
  }

  ll ans = cb(n) - 3 * sq(n) + 2 * n
    - 6 * m * n + 12 * m
    + 3 * K - 6 * m;

  cout << ans / 6 << endl;
}