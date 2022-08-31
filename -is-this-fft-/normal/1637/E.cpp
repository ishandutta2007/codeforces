#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 3e5 + 5;

vector<int> wcnt [MAX_N];

typedef long long ll;

void solve () {
  int n, m;
  cin >> n >> m;

  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    cnt[x]++;
  }

  set<pair<int, int>> forb;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    forb.insert({u, v});
    forb.insert({v, u});
  }

  for (int i = 1; i <= n; i++) {
    wcnt[i].clear();
  }

  for (auto it = cnt.begin(); it != cnt.end(); it++) {
    wcnt[it->second].push_back(it->first);
  }

  for (int i = 1; i <= n; i++) {
    reverse(wcnt[i].begin(), wcnt[i].end());
  }

  ll ans = 0;
  for (int cx = 1; cx <= n; cx++) {
    for (int x : wcnt[cx]) {
      for (int cy = 1; cy <= cx; cy++) {
        for (int y : wcnt[cy]) {
          if (x != y && !forb.count({x, y})) {
            ans = max(ans, (ll) (x + y) * (ll) (cx + cy));
            break;
          }
        }
      }
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}