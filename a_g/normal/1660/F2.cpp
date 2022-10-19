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
    string s;
    cin >> n >> s;
    vector<fenwick<int>> fenw;
    int off = n+1;
    for (int j = 0; j < 3; j++) {
      fenw.push_back(fenwick<int>(2*n+5));
    }
    fenw[0].add(off, 1);
    long long ans = 0;
    int cur = 0;
    for (char c: s) {
      cur += (c == '+' ? -1 : 1);
      int res = (cur%3+3)%3;
      int z = (cur-res)/3+off;
      ans += fenw[res].query(z);
      fenw[res].add(z, 1);
    }
    cout << ans << '\n';
  }
}