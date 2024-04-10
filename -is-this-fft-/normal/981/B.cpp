#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int main () {
  ios::sync_with_stdio(false);

  map<int, ll> best;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int idx;
    ll cost;
    cin >> idx >> cost;

    best[idx] = cost;
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int idx;
    ll cost;
    cin >> idx >> cost;

    if (best.count(idx) == 0) {
      best[idx] = 0;
    }

    best[idx] = max(best[idx], cost);
  }

  ll ans = 0;
  for (auto it = best.begin(); it != best.end(); it++) {
    ans += it->second;
  }
  cout << ans << endl;
}