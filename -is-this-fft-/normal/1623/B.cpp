#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define l first
#define r second

const int INF = 1e9 + 5;

void solve () {
  int n;
  cin >> n;

  vector<pair<int, int>> segs (n);
  for (int i = 0; i < n; i++) {
    cin >> segs[i].l >> segs[i].r;
  }

  map<int, pair<int, int>> ans;
  for (auto p : segs) {
    if (p.l == 1 && p.r == n) continue;
    
    int minr = INF;
    int maxl = -1;

    for (auto q : segs) {
      if (q.l == p.l && q.r > p.r) {
        minr = min(minr, q.r);
      }

      if (q.r == p.r && q.l < p.l) {
        maxl = max(maxl, q.l);
      }
    }

    if (minr != INF) {
      ans[p.r + 1] = make_pair(p.l, minr);
    } else {
      ans[p.l - 1] = make_pair(maxl, p.r);
    }
  }

  for (auto pr : ans) {
    cout << pr.r.l << " " << pr.r.r << " " << pr.l << '\n';
  }
  for (auto p : segs) {
    if (p.l == p.r) {
      cout << p.l << " " << p.r << " " << p.l << '\n';
    }
  }
  cout << '\n';
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