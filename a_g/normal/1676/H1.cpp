#include <bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
  public:
    vector<T> arr;
    fenwick (int n) {
      arr.resize(n+3);
    }
    void add (int index, T val) {
      for (; index < arr.size(); index += (index & (-index))) {
        arr[index] += val;
      }
    }
    T query(int index) {
      T sum = 0;
      for (; index > 0; index -= (index & (-index))) {
        sum += arr[index];
      }
      return sum;
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
    for (int& x: a) cin >> x;
    fenwick<int> fenw(n+1);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += i- fenw.query(a[i]-1);
      fenw.add(a[i], 1);
    }
    cout << ans << '\n';
  }
}