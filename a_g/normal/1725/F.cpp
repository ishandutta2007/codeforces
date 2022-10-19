#include <bits/stdc++.h>
using namespace std;

const int B = 30;
int ans[B];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (pair<int, int>& p: a) {
    cin >> p.first >> p.second;
  }
  for (int bit = 0; bit < B; bit++) {
    vector<pair<int, int>> events;
    int mask = (1<<bit)-1;
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (a[i].second-a[i].first+1 >= (1<<bit)) {
        continue;
      }
      int u = a[i].first&mask;
      int v = a[i].second&mask;
      //cout << u << ' ' << v << endl;
      if (v >= u) {
        cur++;
        events.emplace_back(2*u, -1);
        events.emplace_back(2*v+1, 1);
      }
      else {
        events.emplace_back(2*v+1, 1);
        events.emplace_back(2*u, -1);
      }
    }
    sort(events.begin(), events.end());
    int best = cur;
    for (auto& [k, d]: events) {
      //cout << k << ' ' << d << endl;
      cur += d;
      best = min(best, cur);
    }
    ans[bit] = n-best;
  }

  int q;
  cin >> q;
  while (q--) {
    int w;
    cin >> w;
    cout << ans[__builtin_ctz(w)] << '\n';
  }
}