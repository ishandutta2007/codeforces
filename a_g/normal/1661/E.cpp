#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int a[3][N];
int cnt[N], vert_edge[N], horiz_edge[N], squares[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < 3; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < n; j++) {
      if (row[j] == '1') a[i][j] = 1;
    }
  }

  for (int i = 1; i <= n; i++) {
    cnt[i] = cnt[i-1];
    vert_edge[i] = vert_edge[i-1];
    horiz_edge[i] = horiz_edge[i-1];
    squares[i] = squares[i-1];
    for (int j = 0; j < 3; j++) {
      if (a[j][i-1]) cnt[i]++;
      if (a[j][i-1] && a[j][i]) horiz_edge[i]++;
    }
    for (int j = 0; j < 2; j++) {
      if (a[j][i-1] && a[j+1][i-1]) vert_edge[i]++;
      if (a[j][i-1] && a[j+1][i-1] && a[j][i] && a[j+1][i]) squares[i]++;
    }
  }
  vector<pair<int, int>> rects;
  int last = -1;
  for (int i = 0; i < n; i++) {
    if (a[0][i] && a[1][i] && a[2][i]) {
      if (last == -1 || last == i-1) {
        last = i;
      }
      else {
        rects.emplace_back(last, i);
        last = i;
      }
    }
    else if (a[0][i] && a[2][i]) {
      continue;
    }
    else {
      last = -1;
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int v = cnt[r]-cnt[l-1];
    int e = (vert_edge[r]-vert_edge[l-1]) + (horiz_edge[r-1]-horiz_edge[l-1]);
    int f = (squares[r-1]-squares[l-1]);
    auto it1 = lower_bound(rects.begin(), rects.end(), make_pair(l-1, -1));
    auto it2 = lower_bound(rects.begin(), rects.end(), make_pair(-1, r), 
        [&] (const pair<int, int>& p, const pair<int, int>& q) {
        if (p.second != q.second) {
          return p.second < q.second;
        }
        return p.first < q.first;
        });
    f += max<int>(0, it2-it1);
    cout << v+f-e << '\n';
  }
}