#include <bits/stdc++.h>
using namespace std;

vector<int> pts[3];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    int p;
    char c;
    cin >> p >> c;
    if (c == 'G') pts[0].push_back(p);
    if (c == 'R') pts[1].push_back(p);
    if (c == 'B') pts[2].push_back(p);
  }
  long long ans = 0;
  if (!pts[0].size()) {
    for (int j = 1; j < 3; j++) {
      if (pts[j].size()) ans += pts[j].back()-pts[j][0];
    }
    cout << ans << '\n';
    return 0;
  }

  if (!pts[1].size() && !pts[2].size()) {
    cout << pts[0].back()-pts[0][0] << '\n';
    return 0;
  }

  for (int j = 1; j < 3; j++) {
    if (!pts[j].size()) {
      pts[j].push_back(pts[0][0]);
    }
  }

  int m = pts[0].size();
  int sz1 = pts[1].size();
  int sz2 = pts[2].size();
  int l1 = 0;
  int r1 = 0;
  int l2 = 0;
  int r2 = 0;

  for (int j = 1; j < 3; j++) {
    if (pts[j][0] < pts[0][0]) ans += pts[0][0]-pts[j][0];
    if (pts[j].back() > pts[0].back()) ans += pts[j].back()-pts[0].back();
  }
  for (int z = 0; z < m-1; z++) {
    while (l1 < sz1 && pts[1][l1] < pts[0][z]) l1++;
    while (r1 < sz1 && pts[1][r1] < pts[0][z+1]) r1++;
    while (l2 < sz2 && pts[2][l2] < pts[0][z]) l2++;
    while (r2 < sz2 && pts[2][r2] < pts[0][z+1]) r2++;
    // pts[j][l], ..., pts[j][r-1]
    int d = pts[0][z+1]-pts[0][z];
    int mx1 = d;
    if (l1 != r1) {
      mx1 = max(pts[0][z+1]-pts[1][r1-1], pts[1][l1]-pts[0][z]);
      for (int w = l1; w < r1-1; w++) {
        mx1 = max(mx1, pts[1][w+1]-pts[1][w]);
      }
    }
    int mx2 = d;
    if (l2 != r2) {
      mx2 = max(pts[0][z+1]-pts[2][r2-1], pts[2][l2]-pts[0][z]);
      for (int w = l2; w < r2-1; w++) {
        mx2 = max(mx2, pts[2][w+1]-pts[2][w]);
      }
    }
    ans += min<long long>(2*d, 3LL*d-mx1-mx2);
  }
  cout << ans << '\n';
}