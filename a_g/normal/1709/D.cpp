#include <bits/stdc++.h>
using namespace std;

template<typename T>
class maxSparseTable {
  public:
    int n;
    vector<vector<T>> st;
    maxSparseTable (vector<T> vals) {
      n = vals.size();
      int rows = __lg(n)+1;
      st.resize(rows);
      st[0] = vals;
      for (int j = 1; j < rows; j++) {
        st[j].resize(n);
        for (int i = 0; i + (1<<j) <= n; i++) {
          st[j][i] = max(st[j-1][i], st[j-1][i+(1<<(j-1))]);
        }
      }
    }
    T query(int l, int r) {
      int j = __lg(r-l+1);
      return max(st[j][l], st[j][r-(1<<j)+1]);
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int& x: a) cin >> x;
  maxSparseTable<int> mst(a);

  int q;
  cin >> q;
  while (q--) {
    int x0, y0, x1, y1, k;
    cin >> x0 >> y0 >> x1 >> y1 >> k;
    if ((x0-x1)%k != 0 || (y0-y1)%k != 0) {
      cout << "NO\n";
      continue;
    }

    int h = k*(n/k)+(x0%k);
    while (h > n) h -= k;
    while (h+k <= n) h += k;
    assert(h <= n && h+k > n);
    if (y0 > y1) swap(y0, y1);
    cout << (mst.query(y0-1, y1-1) < h ? "YES" : "NO") << '\n';
  }
}