#include <bits/stdc++.h>
using namespace std;

template<typename T, const T& (*op)(const T&, const T&)>
class sparseTable {
  public:
    vector<vector<T>> st;
    sparseTable (vector<T> vals) {
      int n = vals.size();
      int rows = __lg(n)+1;
      st.resize(rows);
      st[0] = vals;
      for (int j = 1; j < rows; j++) {
        st[j].resize(n);
        for (int i = 0; i + (1<<j) <= n; i++) {
          st[j][i] = op(st[j-1][i], st[j-1][i+(1<<(j-1))]);
        }
      }
    }
    T query(int l, int r) {
      int j = __lg(r-l+1);
      return op(st[j][l], st[j][r-(1<<j)+1]);
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  for (int& x: a) {
    int y;
    cin >> y;
    x -= y;
  }
  vector<long long> sums(n+1);
  for (int i = 0; i < n; i++) {
    sums[i+1] = sums[i] + a[i];
  }

  sparseTable<long long, max<long long>> maxst(sums);
  sparseTable<long long, min<long long>> minst(sums);

  while (q--) {
    int l, r;
    cin >> l >> r;
    if (sums[l-1] != sums[r] || maxst.query(l-1, r) > sums[l-1]) {
      cout << "-1\n";
      continue;
    }
    cout << sums[l-1]-minst.query(l-1, r) << '\n';
  }
}