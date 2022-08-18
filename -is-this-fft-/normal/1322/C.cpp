#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd (ll p, ll q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

void solve () {
  int n, m;
  cin >> n >> m;

  vector<pair<vector<int>, ll>> thing (n, make_pair(vector<int> (0), 0));
  for (int i = 0; i < n; i++) {
    cin >> thing[i].second;
  }

  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;

    l--; r--;
    thing[r].first.push_back(l);
  }

  for (int i = 0; i < n; i++) {
    sort(thing[i].first.begin(), thing[i].first.end());
  }

  sort(thing.begin(), thing.end());

  ll cur_sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    cur_sum += thing[i].second;
    if (i == n - 1 || thing[i].first != thing[i + 1].first) {
      if (!thing[i].first.empty()) {
        ans = gcd(ans, cur_sum);
      }
      cur_sum = 0;
    }
  }

  cout << ans << endl;
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}