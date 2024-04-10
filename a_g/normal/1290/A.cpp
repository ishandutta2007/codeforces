#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
class maxSparseTable {
  public:
    int n;
    int rows;
    vector<vector<T>> st;
    maxSparseTable (vector<T> vals) {
      n = vals.size();
      rows = floor(log2(n))+1;
      for (int i = 0; i < n; i++) {
        st.push_back(vector<T>(rows));
      }
      for (int i = 0; i < n; i++) {
        st[i][0] = vals[i];
      }
      for (int j = 1; j < rows; j++) {
        for (int i = 0; i + (1<<j) <= n; i++) {
          st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
      }
    }
    T query(int l, int r) {
      int j = floor(log2(r-l+1));
      return max(st[l][j], st[r-(1<<j)+1][j]);
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
      b[i] = max(a[i], a[i+n-m]);
    }
    k = min(k, m-1);
    int w = m-k;
    int ans = 0;
    for (int i = 0; i + w <= m; i++) {
      //cout << i << " " << *min_element(b.begin()+i, b.begin()+w+i) << endl;
      ans = max(ans, *min_element(b.begin()+i, b.begin()+w+i));
    }
    cout << ans << '\n';
  }
}