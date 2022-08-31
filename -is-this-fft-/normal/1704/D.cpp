#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll pot (const vector<ll> &v) {
  ll ans = 0;
  for (int i = 0; i < (int) v.size(); i++) {
    ans += (ll) i * v[i];
  }
  return ans;
}

void solve () {
  int n, m;
  cin >> n >> m;

  vector<ll> pots;
  for (int i = 0; i < n; i++) {
    vector<ll> vec (m);
    for (int j = 0; j < m; j++) {
      cin >> vec[j];
    }

    pots.push_back(pot(vec));
  }

  pair<ll, int> mn = make_pair(pots[0], 0);
  pair<ll, int> mx = make_pair(pots[0], 0);
  for (int i = 0; i < n; i++) {
    mn = min(mn, make_pair(pots[i], i));
    mx = max(mx, make_pair(pots[i], i));
  }

  cout << 1 + mx.second << " " << mx.first - mn.first << '\n'; 
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