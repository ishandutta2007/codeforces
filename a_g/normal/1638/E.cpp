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
  int n, q;
  cin >> n >> q;
  
  vector<long long> lazy(n+1);
  map<int, int> colors;
  colors[1] = 1;
  colors[n+1] = 0;
  fenwick<long long> vals(n+1);

  while (q--) {
    string s;
    cin >> s;
    if (s == "Color") {
      int l, r, c;
      cin >> l >> r >> c;
      if (r < n) {
        colors[r+1] = prev(colors.lower_bound(r+2))->second;
      }
      for (auto it = prev(colors.lower_bound(l+1)); it->first <= r; 
          (it->first > l ? colors.erase(it++) : it++)) {
        int sl = max(l, it->first);
        int sr = min(r, next(it)->first - 1);
        vals.add(sl, lazy[it->second]);
        vals.add(sr+1, -lazy[it->second]);
      }
      colors[l] = c;
      vals.add(l, -lazy[c]);
      vals.add(r+1, lazy[c]);
    }
    else if (s == "Add") {
      int c, x;
      cin >> c >> x;
      lazy[c] += x;
    }
    else {
      int i;
      cin >> i;
      auto it = prev(colors.lower_bound(i+1));
      cout << vals.query(i) + lazy[it->second] << '\n';
    }
  }
}