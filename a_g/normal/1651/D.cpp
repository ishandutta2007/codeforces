#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> adj = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> ptsvec(n);
  map<pair<int, int>, int> pts;
  for (int i = 0; i < n; i++) {
    cin >> ptsvec[i].first >> ptsvec[i].second;
    pts[ptsvec[i]] = i;
  }
  vector<pair<int, int>> ans(n, make_pair(-1, -1));
  vector<int> que;
  for (int i = 0; i < n; i++) {
    int x = ptsvec[i].first;
    int y = ptsvec[i].second;
    for (const pair<int, int>& d: adj) {
      if (!pts.count(make_pair(x+d.first, y+d.second))) {
        ans[i] = make_pair(x+d.first, y+d.second);
      }
    }
    if (ans[i].first != -1) {
      que.push_back(i);
    }
  }

  for (int i = 0; i < que.size(); i++) {
    int x = ptsvec[que[i]].first;
    int y = ptsvec[que[i]].second;
    for (const pair<int, int>& d: adj) {
      pair<int, int> nbr = make_pair(x+d.first, y+d.second);
      if (pts.count(nbr) && ans[pts[nbr]].first == -1) {
        ans[pts[nbr]] = ans[que[i]];
        que.push_back(pts[nbr]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i].first << " " << ans[i].second << '\n';
  }
}