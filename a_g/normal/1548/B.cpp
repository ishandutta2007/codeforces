#include <bits/stdc++.h>
using namespace std;

template<typename T, T (*op)(T, T)>
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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> d(n-1);
    for (long long& x: a) cin >> x;
    for (int i = 0; i < n-1; i++) d[i] = a[i+1]-a[i]; 
    sparseTable<long long, __gcd> st(d);
    int r = -1;
    int ans = 0;
    for (int l = 0; l < n-1; l++) {
      while (r+1 < n-1 && abs(st.query(l, r+1)) > 1) r++;
      ans = max(ans, r-l+1);
      if (r < l) r++;
    }
    cout << ans+1 << '\n';
  }
}