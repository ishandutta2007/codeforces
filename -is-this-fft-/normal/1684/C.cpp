#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  bool fail = false;
  set<pair<int, int>> need;
  vector<vector<int>> arr;
  for (int i = 0; i < n; i++) {
    vector<int> cur (m);
    for (int j = 0; j < m; j++) {
      cin >> cur[j];
    }

    auto sorted = cur;
    sort(sorted.begin(), sorted.end());

    vector<int> diff;
    for (int j = 0; j < m; j++) {
      if (cur[j] != sorted[j]) {
        diff.push_back(j);
      }
    }

    if ((int) diff.size() > 2) {
      fail = true;
    } else if ((int) diff.size() == 2) {
      need.insert(make_pair(diff[0], diff[1]));
    }
    arr.push_back(cur);
  }

  if (fail || (int) need.size() > 1) {
    cout << -1 << '\n';
    return;
  }

  if ((int) need.size() == 0) {
    cout << "1 1" << '\n';
    return;
  }

  auto swp = *need.begin();

  for (const auto &cur : arr) {
    if (cur[swp.first] < cur[swp.second]) {
      cout << -1 << '\n';
      return;
    }
  }
  
  cout << 1 + swp.first << " " << 1 + swp.second << '\n';
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