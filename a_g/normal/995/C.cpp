#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l2(pair<int, int> x) {
  return 1LL * x.first * x.first + 1LL * x.second * x.second;
}

pair<int, int> add(pair<int, int> x, pair<int, int> y) {
  return {x.first + y.first, x.second + y.second};
}

pair<int, int> sub(pair<int, int> x, pair<int, int> y) {
  return {x.first - y.first, x.second - y.second};
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> moves(n);
  vector<bool> active(n, 1);
  vector<pair<int, int>> parent(n);
  for (int i = 0; i < n; i++) {
    cin >> moves[i].first >> moves[i].second;
  }
  vector<int> curr;
  int j = 0;
  while (j < moves.size()) {
    pair<int, int> x = moves[j];
    for (int i: curr) {
      if (l2(add(x, moves[i])) < 1e12) {
        parent[i] = {moves.size(), 1};
        parent[j] = {moves.size(), 1};
        active[i] = 0;
        active[j] = 0;
        moves.push_back(add(x, moves[i]));
        active.push_back(1);
        parent.push_back({0, 0});
        curr.erase(find(curr.begin(), curr.end(), i));
        break;
      }
      else if (l2(sub(x, moves[i])) < 1e12) {
        parent[i] = {moves.size(), -1};
        parent[j] = {moves.size(), 1};
        active[i] = 0;
        active[j] = 0;
        moves.push_back(sub(x, moves[i]));
        active.push_back(1);
        parent.push_back({0, 0});
        curr.erase(find(curr.begin(), curr.end(), i));
        break;
      }
    }
    if (active[j]) curr.push_back(j);
    j++;
  }

  int m = curr.size();
  vector<int> ans(moves.size());
  for (int i = 0; i < (1<<m); i++) {
    int a = 0;
    int b = 0;
    for (int j = 0; j < m; j++) {
      int sign = ((i>>j) & 1 ? -1 : 1);
      a += sign*moves[curr[j]].first;
      b += sign*moves[curr[j]].second;
    }
    if (l2({a, b}) < 2.25e12) {
      for (int j = 0; j < m; j++) {
        int sign = ((i>>j) & 1 ? -1 : 1);
        ans[curr[j]] = sign;
      }
      break;
    }
  }
  for (int i = moves.size() - 1; i >= 0; i--) {
    if (!active[i]) {
      ans[i] = ans[parent[i].first] * parent[i].second;
    }
  }

  /*
  for (int i = 0; i < moves.size(); i++) {
    cout <<  active[i] << " " << ans[i] << " " << moves[i].first << " " << moves[i].second << " " << parent[i].first << " " << parent[i].second << endl;
  }
  cout << endl;
  */

  for (int i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << endl;
}