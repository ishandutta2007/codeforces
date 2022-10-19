#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
  public:
    vector<T> arr;
    fenwick (int n) {
      arr.resize(n+3, 1e9);
    }
    void add (int index, T val) {
      for (; index < arr.size(); index += (index & (-index))) {
        arr[index] = min(arr[index], val);
      }
    }
    T query(int index) {
      T sum = 1e9;
      for (; index > 0; index -= (index & (-index))) {
        sum = min(sum, arr[index]);
      }
      return sum;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    fenwick<int> fenw(n);
    for (int i = 1; i <= n; i++) {
      fenw.add(i, a[i]);
    }
    set<int, greater<int>> vals;
    for (int i = 1; i <= n; i++) {
      vals.insert(fenw.query(i));
    }

    while (m--) {
      int k, d;
      cin >> k >> d;
      int curspeed = fenw.query(k);
      a[k] -= d;
      if (a[k] < curspeed) {
        if (k == 1 || fenw.query(k-1) != curspeed) {
          vals.erase(curspeed);
        }
      }
      for (auto it = vals.lower_bound(curspeed-1);
          it != vals.end() && *it > a[k];
          vals.erase(it++));
      fenw.add(k, a[k]);
      if (fenw.query(k) == a[k]) vals.insert(a[k]);
      cout << vals.size() << ' ';
    }
    cout << '\n';
  }
}