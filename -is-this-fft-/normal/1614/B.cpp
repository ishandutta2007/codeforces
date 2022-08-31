#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve () {
  int n;
  cin >> n;

  vector<pair<int, int>> ord;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;

    ord.push_back({a, i});
  }

  sort(ord.rbegin(), ord.rend());

  ll sum = 0;
  vector<int> ans (n + 1, 0);
  for (int i = 0; i < n; i++) {
    ll cur = 1 + i / 2;
    if (i % 2 == 1) cur *= -1;
    ans[ord[i].second] = cur;
    sum += 2 * abs(cur) * (ll) ord[i].first;
  }

  cout << sum << '\n';
  for (int i = 0; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
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