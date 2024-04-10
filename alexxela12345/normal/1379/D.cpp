#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}

signed main() {
  int n, h, m, k;
  cin >> n >> h >> m >> k;
  vector<pair<int, int>> evs;
  vector<int> tr(n);
  for (int i = 0; i < n; i++) {
    int h1, m1;
    cin >> h1 >> m1;
    m1 = m1 % (m / 2);
    tr[i] = m1;
    for (int j = m1 - m / 2; j < 2 * m; j += m / 2) {
      if (j < 0)
	continue;
      evs.push_back({j + 1, 1});
      evs.push_back({j + k, -1});
    }
  }
  sort(evs.begin(), evs.end());
  evs.push_back({-1, -1});
  int cur_bal = 0;
  pair<int, int> best_ans = {n + 1, -1};
  for (int i = 0; i + 1 < (int) evs.size(); i++) {
    cur_bal += evs[i].second;
    if (evs[i].first != evs[i + 1].first && evs[i].first >= m / 2 && evs[i].first < m) {
      best_ans = min(best_ans, {cur_bal, evs[i].first - m / 2});
    }
  }
  cout << best_ans.first << " " << best_ans.second << endl;
  int l = best_ans.second - k + 1;
  int r = best_ans.second - 1;
  if (l < 0) {
    l += m / 2;
    r += m / 2;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (tr[i] >= l && tr[i] <= r) {
      cnt++;
      cout << i + 1 << ' ';
    }
    tr[i] += m / 2;
    if (tr[i] >= l && tr[i] <= r) {
      cnt++;
      cout << i + 1 << ' ';
    }
  }
  cout << endl;
  assert(cnt == best_ans.first);
}