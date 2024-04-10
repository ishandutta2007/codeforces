#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

struct Solution {
  int x = -1, y = -1;
  vector<pair<int, int>> s;

  bool can() {
    return !s.empty();
  }
};

Solution solve(vector<int> a, int k, int delta) {
  auto sorted = a;
  sort(all(sorted));

  int max_can = 0;
  Solution s;

  int r = 0;
  for (int l = 0; l < sorted.size(); ++l) {
    while (r + 1 < sorted.size() && sorted[r + 1] - sorted[l] < delta) {
      ++r;
    }

    if (r - l + 1 > max_can) {
      max_can = r - l + 1;
      s.x = sorted[l];
      s.y = sorted[r];
    }
  }

  int sum = 0;

  int l = 0;
  for (int i = 0; i < a.size(); ++i) {
    int x = a[i];

    int sign = (x >= s.x && x <= s.y) ? 1 : -1;
    sum += sign;
    if (sum > 0) {
      s.s.emplace_back(l, i);
      sum = 0;
      l = i + 1;
    }
  }

  /*for (auto it : s.s) {
    cout << "preseg " << it.first + 1 << " " << it.second + 1 << endl;
  }
  cout << "final sum " << sum << endl;*/

  while (sum <= 0 && !s.s.empty()) {
    auto p = s.s.back();
    s.s.pop_back();
    l = p.first;
    ++sum;
  }

  //cout << "adjusted " << sum << " " << l + 1 << " segs " << s.s.size() << endl;

  if (sum > 0) {
    s.s.emplace_back(l, a.size() - 1);
  } else {
    return Solution{};
  }

  if (s.s.size() < k) {
    return Solution{};
  }

  while (s.s.size() > k) {
    s.s.pop_back();
  }
  s.s.back().second = a.size() - 1;
  assert(s.s.size() == k);

  for (auto& it : s.s) {
    int sum = 0;
    for (int i = it.first; i <= it.second; ++i) {
      int x = a[i];
      sum += (x >= s.x && x <= s.y) ? 1 : -1;
    }
    assert(sum > 0);
  }

  /*for (auto it : s.s) {
    cout << "preseg " << it.first + 1 << " " << it.second + 1 << endl;
  }*/

  return s;
}

void solve(bool read = true) {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int low = -1, high = n;

  assert(solve(a, k, high).can());

  while (low + 1 != high) {
    int m = (low + high) / 2;
    auto s = solve(a, k, m);
    if (s.can()) {
      high = m;
    } else {
      low = m;
    }
  }
  auto s = solve(a, k, high);
  assert(s.can());

  cout << s.x << " " << s.y << "\n";
  assert(s.s.size() == k);
  for (auto it : s.s) {
    cout << it.first + 1 << " " << it.second + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }

  return 0;
}