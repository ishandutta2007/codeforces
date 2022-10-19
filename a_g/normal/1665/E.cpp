#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
const size_t K = 31;
int a[N];
vector<int> vals[4*N];

void init(int v, int tl, int tr) {
  if (tl == tr) {
    vals[v] = {a[tl]};
    return;
  }
  vals[v].clear();
  int tm = (tl+tr)/2;
  init(2*v, tl, tm);
  init(2*v+1, tm+1, tr);
  merge(vals[2*v].begin(), vals[2*v].end(), vals[2*v+1].begin(), vals[2*v+1].end(), back_inserter(vals[v]));
  vals[v].resize(min(K, vals[v].size()));
}

vector<int> query(int v, int tl, int tr, int l, int r) {
  if (l > tr || r < tl) return {};
  if (l <= tl && tr <= r) return vals[v];
  int tm = (tl+tr)/2;
  vector<int> left_part = query(2*v, tl, tm, l, r);
  vector<int> right_part = query(2*v+1, tm+1, tr, l, r);
  vector<int> ans;
  merge(left_part.begin(), left_part.end(), right_part.begin(), right_part.end(), back_inserter(ans));
  ans.resize(min(K, ans.size()));
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    init(1, 1, n);

    int q;
    cin >> q;
    while (q--) {
      int l, r;
      cin >> l >> r;
      vector<int> b = query(1, 1, n, l, r);
      int ans = 2e9;
      for (int i = 0; i < (int)b.size(); i++) {
        for (int j = i+1; j < (int)b.size(); j++) {
          ans = min(ans, b[i]|b[j]);
        }
      }
      cout << ans << '\n';
    }
  }
}