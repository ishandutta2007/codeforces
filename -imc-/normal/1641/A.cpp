#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

void solve(bool read) {
  map<int, map<int, int>> cnt_by_b;
  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; ++i) {
    int y;
    cin >> y;

    int p = 0;
    while (y % x == 0) {
      y /= x;
      ++p;
    }

    ++cnt_by_b[y][p];
  }

  int ans = 0;
  for (auto& it : cnt_by_b) {
    vector<int> keys;
    for (pair<int, int> p : it.second) {
      keys.push_back(p.first);
    }

    for (int k : keys) {
      int a = it.second[k];
      int b = it.second[k + 1];

      if (b >= a) {
        it.second[k + 1] -= a;
      } else {
        ans += a - b;
        it.second[k + 1] = 0;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  //solve(false);

  return 0;
}