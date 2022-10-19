#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, v;
  cin >> n >> v;
  vector<pair<long long, long long>> events;
  vector<int> t(n), a(n);
  for (int& x: t) cin >> x;
  for (int& x: a) cin >> x;
  for (int i = 0; i < n; i++) {
    long long x = 1LL * v * t[i] + a[i];
    long long y = 1LL * v * t[i] - a[i];
    if (x < 0 || y < 0) continue;
    events.emplace_back(x, y);
  }
  sort(events.begin(), events.end());
  vector<long long> best;
  best.emplace_back(0LL);
  for (pair<long long, long long>& event: events) {
    long long y = event.second;
    auto it = lower_bound(best.begin(), best.end(), y+1);
    if (it == best.end()) {
      best.push_back(y);
      continue;
    }
    assert(it != best.begin());
    *it = y;
  }
  cout << best.size()-1 << '\n';
}