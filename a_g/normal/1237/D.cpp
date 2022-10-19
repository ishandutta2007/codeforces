#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

template<typename T>
class minSparseTable {
  public:
    int n;
    int rows;
    vector<vector<T>> st;
    minSparseTable (vector<T> vals) {
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
          st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
      }
    }
    T query(int l, int r) {
      int j = 31-__builtin_clz(r-l+1);
      return min(st[l][j], st[r-(1<<j)+1][j]);
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(2*n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i+n] = a[i];
  }
  int lo = *min_element(a.begin(), a.end());
  int hi = *max_element(a.begin(), a.end());
  if (2*lo >= hi) {
    while (n--) {
      cout << "-1 ";
    }
    cout << '\n';
    return 0;
  }

  minSparseTable<int> mst(a);
  vector<int> b(2*n);
  for (int i = 0; i < n; i++) {
    if (2*lo >= a[i]) {
      b[i] = INF;
    }
    else {
      int low = i;
      int high = 2*n-1;
      while (high-low > 1) {
        int mid = (low+high)/2;
        if (2*mst.query(i, mid) >= a[i]) low = mid;
        else high = mid;
      }
      b[i] = high;
    }
    b[i+n] = b[i]+n;
  }
  for (int i = 2*n-2; i >= 0; i--) {
    b[i] = min(b[i], b[i+1]);
  }
  for (int i = 0; i < n; i++) {
    cout << b[i]-i << " \n"[i+1==n];
  }
}