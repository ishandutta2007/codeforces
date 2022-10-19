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

struct seg {
  int l, r, id;
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<seg>> segs(n);
    vector<int> ans(n);
    vector<int> all_coords;
    for (int i = 0; i < n; i++) {
      int l, r, c;
      cin >> l >> r >> c;
      c--;
      seg s{l, r, i};
      all_coords.push_back(l);
      all_coords.push_back(r);
      segs[c].push_back(s);
    }
    sort(all_coords.begin(), all_coords.end());
    all_coords.resize(unique(all_coords.begin(), all_coords.end())-all_coords.begin());
    auto compress = [&] (int x) {
      return lower_bound(all_coords.begin(), all_coords.end(), x)-all_coords.begin()+1;
    };

    fenwick<int> left_ends(2*n+5);
    fenwick<int> right_ends(2*n+5);
    for (int i = 0; i < n; i++) {
      for (auto& [l, r, id]: segs[i]) {
        left_ends.add(compress(l), 1);
        right_ends.add(compress(r), 1);
      }
    }

    for (int i = 0; i < n; i++) {
      for (auto& [l, r, id]: segs[i]) {
        left_ends.add(compress(l), -1);
        right_ends.add(compress(r), -1);
      }
      for (auto& [l, r, id]: segs[i]) {
        if (right_ends.query(compress(l)-1) != left_ends.query(compress(r))) continue;
        ans[id] = 1e9;
        if (right_ends.query(compress(l)-1)) {
          int high = compress(l)-1;
          int low = 0;
          while (high-low > 1) {
            int mid = (low+high)/2;
            if (right_ends.query(mid) == right_ends.query(compress(l)-1)) {
              high = mid;
            }
            else {
              low = mid;
            }
          }
          ans[id] = min(ans[id], l-all_coords[high-1]);
        }
        if (left_ends.query(2*n+5) > left_ends.query(compress(r))) {
          int high = 2*n+5;
          int low = compress(r);
          while (high-low > 1) {
            int mid = (low+high)/2;
            if (left_ends.query(mid) == left_ends.query(compress(r))) {
              low = mid;
            }
            else {
              high = mid;
            }
          }
          ans[id] = min(ans[id], all_coords[high-1]-r);
        }
      }
      for (auto& [l, r, id]: segs[i]) {
        left_ends.add(compress(l), 1);
        right_ends.add(compress(r), 1);
      }
    }

    for (int x: ans) cout << x << ' ';
    cout << '\n';
  }
}