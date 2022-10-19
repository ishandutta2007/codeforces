#include <bits/stdc++.h>
using namespace std;

template<typename T>
class gcdSparseTable {
  public:
    int n;
    int rows;
    vector<vector<T>> st;
    gcdSparseTable (vector<T> vals) {
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
          st[i][j] = __gcd(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
      }
    }
    T query(int l, int r) {
      int j = floor(log2(r-l+1));
      return __gcd(st[l][j], st[r-(1<<j)+1][j]);
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  gcdSparseTable<int> gst(a);
  vector<int> pts;

  for (int i = 0; i < n; i++) {
    int low = 0;
    int high = n-i+1;
    while (low + 1 < high) {
      int mid = (low+high)/2;
      int g = gst.query(i, i+mid-1);
      if (g == mid) {
        if (!pts.size() || pts.back() < i) pts.push_back(i+mid-1);
        break;
      }
      else if (g < mid) {
        high = mid;
      }
      else low = mid;
    }
  }

  vector<int> ans(n);
  for (int i: pts) ans[i]++;
  for (int i = 1; i < n; i++) ans[i] += ans[i-1];
  for (int val: ans) cout << val << ' ';
  cout << '\n';
}