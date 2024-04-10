#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> p(n), x(m);
  for (int& a: p) cin >> a;
  for (int& a: x) cin >> a;
  sort(x.begin(), x.end());
  map<int, long long> events;
  // time, delta
  for (int i = 0; i < n; i++) {
    int pos = 100*i;
    auto it = lower_bound(x.begin(), x.end(), pos);
    int dist = 1e9;
    if (it != x.end()) {
      dist = min(dist, *it-pos);
    }
    if (it != x.begin()) {
      dist = min(dist, pos-*(it-1));
    }
    events[2*(pos-dist)+1] += p[i];
    events[2*(pos+dist)] -= p[i];
  }
  long long tot = 0, ans = 0;
  for (const pair<int, long long>& p: events) {
    tot += p.second;
    ans = max(ans, tot);
  }
  cout << ans << '\n';
}