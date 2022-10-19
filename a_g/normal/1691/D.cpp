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
    vector<int> L(n), R(n);
    for (int& x: a) cin >> x;
    vector<long long> s(n+1), sp(n+1);
    for (int i = 0; i < n; i++) {
      s[i+1] = s[i] + a[i];
      sp[i+1] = -s[i+1];
    }

    vector<int> stk;
    for (int i = 0; i < n; i++) {
      while (stk.size() && a[stk.back()] < a[i]) {
        R[stk.back()] = i;
        stk.pop_back();
      }
      stk.push_back(i);
    }
    for (int i: stk) {
      R[i] = n;
    }
    stk.clear();

    for (int i = n-1; i >= 0; i--) {
      while (stk.size() && a[stk.back()] < a[i]) {
        L[stk.back()] = i;
        stk.pop_back();
      }
      stk.push_back(i);
    }
    for (int i: stk) {
      L[i] = -1;
    }

    maxSparseTable<long long> mst(s); 
    maxSparseTable<long long> mst2(sp); 

    bool good = 1;
    for (int i = 0; i < n; i++) {
      long long z = mst.query(i+1, R[i]);
      if (z > s[i+1]) {
        //cout << i << " " << R[i] << " " << z << " " << endl;
        good = 0;
        break;
      }
      z = -mst2.query(L[i]+1, i);
      if (z < s[i]) {
        //cout << i << " " << L[i] << " " << z << " " << endl;
        good = 0;
        break;
      }
    }


    cout << (good ? "YES" : "NO") << '\n';
  }
}