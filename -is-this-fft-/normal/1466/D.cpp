#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

const int MAX_N = 1e5 + 5;

int deg [MAX_N];
int spc [MAX_N];
ll arr [MAX_N];

void solve () {
  int n;
  cin >> n;

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    deg[i] = 0;
    spc[i] = 0;
    ans += arr[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    deg[u]++;
    deg[v]++;
  }

  set<pair<ll, int>> best; // <value, vertex>
  for (int i = 1; i <= n; i++) {
    best.insert(make_pair(arr[i], i));
  }
  
  for (int k = 1; k <= n - 1; k++) {
    cout << ans << " ";

    while (!best.empty() && spc[best.rbegin()->second] == deg[best.rbegin()->second] - 1) {
      auto to_rem = *best.rbegin();
      best.erase(to_rem);
    }

    if (!best.empty()) {
      auto pr = *best.rbegin();
      ans += pr.first;
      spc[pr.second]++;
    }
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}