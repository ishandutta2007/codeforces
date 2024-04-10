#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> dishes(n);
    vector<pair<int, int>> orig(n);
    // sum, minfish, maxfish, index
    int variety = 0;
    for (int i = 0; i < n; i++) {
      int a, b, m;
      cin >> a >> b >> m;
      orig[i] = make_pair(a, b);
      dishes[i] = make_tuple(a+b-m, max(0, a-m), a-max(0, m-b), i);
    }
    sort(dishes.begin(), dishes.end());
    vector<pair<int, int>> ans(n);
    int sum = -1;
    int upper = 0;
    vector<int> group;
    auto evict = [&] () {
      if (group.size()) variety++;
      for (int i: group) {
        ans[i] = make_pair(upper, sum-upper);
      }
      group.clear();
    };

    for (tuple<int, int, int, int>& dish: dishes) {
      if (get<0>(dish) != sum || get<1>(dish) > upper) {
        evict();
        sum = get<0>(dish);
        upper = get<2>(dish);
        group.push_back(get<3>(dish));
      }
      else {
        upper = min(upper, get<2>(dish));
        group.push_back(get<3>(dish));
      }
    }
    evict();
    cout << variety << '\n';
    for (int i = 0; i < n; i++) {
      cout << orig[i].first-ans[i].first << " " << orig[i].second-ans[i].second << '\n';
    }
  }
}