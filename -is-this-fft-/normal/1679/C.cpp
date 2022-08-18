#include <iostream>
#include <vector>

using namespace std;

class Fenwick {
  vector<int> tree;

public:
  Fenwick (int n) : tree(n) {
  }

  void add (int pos, int val) {
    for (int i = pos; i < (int) tree.size(); i += i & -i) {
      tree[i] += val;
    }
  }

  int get (int pos) {
    int sum = 0;
    for (int i = pos; i > 0; i -= i & -i) {
      sum += tree[i];
    }
    return sum;
  }

  int range (int l, int r) {
    return get(r) - get(l - 1);
  }
};

const int MAX_N = 1e5 + 5;

int row [MAX_N];
int col [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;

  Fenwick rowf (n + 5), colf (n + 5);
  
  for (int k = 0; k < qc; k++) {
    int type;
    cin >> type;

    if (type == 1) {
      int x, y;
      cin >> x >> y;

      row[x]++;
      if (row[x] == 1) {
        rowf.add(x, 1);
      }

      col[y]++;
      if (col[y] == 1) {
        colf.add(y, 1);
      }
    } else if (type == 2) {
      int x, y;
      cin >> x >> y;

      row[x]--;
      if (row[x] == 0) {
        rowf.add(x, -1);
      }

      col[y]--;
      if (col[y] == 0) {
        colf.add(y, -1);
      }
    } else {
      int xl, yl, xr, yr;
      cin >> xl >> yl >> xr >> yr;

      if (rowf.range(xl, xr) == xr - xl + 1 ||
          colf.range(yl, yr) == yr - yl + 1) {
        cout << "Yes" << '\n';
      } else {
        cout << "No" << '\n';
      }
    }
  }
}