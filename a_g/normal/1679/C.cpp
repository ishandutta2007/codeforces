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
  vector<int> row(n+1);
  vector<int> col(n+1);
  fenwick<int> rowf(n);
  fenwick<int> colf(n);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      rowf.add(x, row[x] ? -1 : 0);
      colf.add(y, col[y] ? -1 : 0);
      row[x]++;
      col[y]++;
      rowf.add(x, row[x] ? 1 : 0);
      colf.add(y, col[y] ? 1 : 0);
    }
    else if (t == 2) {
      int x, y;
      cin >> x >> y;
      rowf.add(x, row[x] ? -1 : 0);
      colf.add(y, col[y] ? -1 : 0);
      row[x]--;
      col[y]--;
      rowf.add(x, row[x] ? 1 : 0);
      colf.add(y, col[y] ? 1 : 0);
    }
    else {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      cout << (rowf.query(x2)-rowf.query(x1-1) == x2-x1+1 || colf.query(y2)-colf.query(y1-1) == y2-y1+1 ? "Yes" : "No") << '\n';
    }
  }
}