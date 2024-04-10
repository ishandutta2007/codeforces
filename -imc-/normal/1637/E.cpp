#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int next_num(vector<int>& a, int x) {
  auto it = lower_bound(all(a), x, std::greater<int>());
  assert(it != a.end());
  if (it + 1 == a.end()) {
    return -1;
  } else {
    return *(it + 1);
  }
}

void solve(bool read = true) {
  int n, n_banned;
  cin >> n >> n_banned;

  li ans = 0;

  vector<int> a(n);

  unordered_map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
  }

  set<pair<int, int>> B;
  for (int i = 0; i < n_banned; ++i) {
    int x, y;
    cin >> x >> y;
    B.insert(make_pair(x, y));
  }
  for (int i = 0; i < n; ++i) {
    B.insert(make_pair(a[i], a[i]));
  }

  unordered_map<int, vector<int>> nums;

  for (int i = 0; i < n; ++i) {
    nums[cnt[a[i]]].push_back(a[i]);
  }

  for (auto& it : nums) {
    sort(all(it.second));
    it.second.erase(unique(all(it.second)), it.second.end());
    reverse(all(it.second));
  }

  auto relax = [&](int x1, int x2) {
    if (x1 == x2) {
      return;
    }

    if (x1 < 0 || x2 < 0) {
      return;
    }

    if (x1 > x2) {
      swap(x1, x2);
    }

    if (B.count(make_pair(x1, x2))) {
      return;
    }

    ans = max(ans, (cnt[x1] + cnt[x2]) * (li)(x1 + x2));
  };

  for (auto p : B) {
    auto& a1 = nums[cnt[p.first]];
    auto& a2 = nums[cnt[p.second]];

    int x1 = next_num(a1, p.first);
    int x2 = next_num(a2, p.second);

    relax(x1, p.second);
    relax(x2, p.first);
  }

  for (auto it1 = nums.begin(); it1 != nums.end(); ++it1) {
    for (auto it2 = it1; it2 != nums.end(); ++it2) {
      auto& a1 = it1->second;
      auto& a2 = it2->second;

      relax(a1[0], a2[0]);
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

  return 0;
}