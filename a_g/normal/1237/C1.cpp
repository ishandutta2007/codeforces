#include <bits/stdc++.h>
using namespace std;

struct pt {
  int x, y, z;
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pt> pts(n);
  for (pt& p: pts) {
    cin >> p.x >> p.y >> p.z;
  }
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&] (int a, int b) {
      if (pts[a].x != pts[b].x) return pts[a].x < pts[b].x;
      if (pts[a].y != pts[b].y) return pts[a].y < pts[b].y;
      return pts[a].z < pts[b].z;
      });

  vector<pair<int, int>> ans;
  vector<vector<int>> group_by_x;
  for (int i: ord) {
    if (group_by_x.size() && pts[group_by_x.back()[0]].x == pts[i].x) {
      group_by_x.back().emplace_back(i);
    }
    else {
      group_by_x.emplace_back(1, i);
    }
  }

  vector<int> leftovers; // these leftovers have decreasing x coordinates
  while (group_by_x.size()) {
    vector<int> group = group_by_x.back();
    vector<vector<int>> group_by_y;
    for (int i: group) {
      if (group_by_y.size() && pts[group_by_y.back()[0]].y == pts[i].y) {
        group_by_y.back().emplace_back(i);
      }
      else {
        group_by_y.emplace_back(1, i);
      }
    }

    group_by_x.pop_back();
    vector<int> leftovers_x; // these leftovers have equal x and decreasing y
    while (group_by_y.size()) {
      vector<int> subgroup = group_by_y.back();
      int k = subgroup.size();
      for (int i = 0; i+1 < k; i += 2) {
        ans.emplace_back(subgroup[i], subgroup[i+1]);
      }
      group_by_y.pop_back();
      if (k&1) {
        leftovers_x.push_back(subgroup[k-1]);
      }
    }
    int k = leftovers_x.size();
    for (int i = 0; i+1 < k; i += 2) {
      ans.emplace_back(leftovers_x[i], leftovers_x[i+1]);
    }
    if (k&1) {
      leftovers.emplace_back(leftovers_x[k-1]);
    }
  }

  int k = leftovers.size();
  for (int i = 0; i+1 < k; i += 2) {
    ans.emplace_back(leftovers[i], leftovers[i+1]);
  }

  for (pair<int, int>& p: ans) {
    cout << p.first+1 << " " << p.second+1 << '\n';
  }

}