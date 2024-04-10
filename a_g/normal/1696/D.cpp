#include <bits/stdc++.h>
using namespace std;

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
      int j = 31-__builtin_clz(r-l+1);
      return max(st[l][j], st[r-(1<<j)+1][j]);
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> jmp(n);
    for (int& x: a) cin >> x;

    vector<int> R(n);
    R[n-1] = n;
    vector<int> stk;
    for (int i = 0; i < n; i++) {
      while (stk.size() && a[stk.back()] < a[i]) {
        int v = stk.back();
        if (a[v] > a[v+1]) {
          R[v] = i;
        }
        stk.pop_back();
      }
      if (i != n-1) stk.push_back(i);
    }
    for (int v: stk) {
      if (a[v] > a[v+1]) R[v] = n;
    }

    stk.clear();
    for (int i = 0; i < n; i++) {
      while (stk.size() && a[stk.back()] > a[i]) {
        int v = stk.back();
        if (a[v] < a[v+1]) {
          R[v] = i;
        }
        stk.pop_back();
      }
      if (i != n-1) stk.push_back(i);
    }
    for (int v: stk) {
      if (a[v] < a[v+1]) R[v] = n;
    }

    vector<pair<int, int>> p(n), q(n);
    for (int i = 0; i < n; i++) {
      p[i] = {a[i], i};
      q[i] = {-a[i], i};
    }
    maxSparseTable<pair<int, int>> mstp(p), mstq(q);
    for (int i = 0; i < n-1; i++) {
      if (a[i] < a[i+1]) {
        jmp[i] = mstp.query(i, R[i]-1).second;
      }
      else {
        jmp[i] = mstq.query(i, R[i]-1).second;
      }
    }

    int cur = 0;
    int ans = 0;
    while (cur < n-1) {
      ans++;
      cur = jmp[cur];
    }
    cout << ans << '\n';
  }
}