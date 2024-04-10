#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class Fenwick2D {
  int n;
  vector<vector<ll>> tree;
  
public:
  Fenwick2D (int _n) : n(_n), tree(_n, vector<ll> (_n, 0)) {
  }

  void add (int x, int y, ll val) {
    for (int i = x; i < n; i += i & -i) {
      for (int j = y; j < n; j += j & -j) {
        tree[i][j] ^= val;
      }
    }
  }

  ll get (int x, int y) {
    ll ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      for (int j = y; j > 0; j -= j & -j) {
        ans ^= tree[i][j];
      }
    }
    return ans;
  }
};

class FenwickWrapper {
  vector<vector<Fenwick2D>> trees;

  Fenwick2D* get_tree (int x, int y) {
    return &trees[x % 2][y % 2];
  }

  ll get (int x, int y) {
    return get_tree(x, y)->get(x, y);
  }

public:
  FenwickWrapper (int _n) : trees(2, vector<Fenwick2D> (2, Fenwick2D(_n))) {
  }
    
  void upd (int x0, int y0, int x1, int y1, ll val) {
    auto cur = get_tree(x0, y0);
    
    int xo = (x1 - x0 + 1) % 2;
    int yo = (y1 - y0 + 1) % 2;
    
    cur->add(x0, y0, val);
    
    if (xo && yo) {
      auto othx = get_tree(x0 + 1, y0);
      auto othy = get_tree(x0, y0 + 1);
      auto othxy = get_tree(x0 + 1, y0 + 1);

      othx->add(x1 + 1, y0, val);
      othy->add(x0, y1 + 1, val);
      othxy->add(x1 + 1, y1 + 1, val);
    } else if (xo) {
      auto othx = get_tree(x0 + 1, y0);

      cur->add(x0, y1 + 1, val);
      othx->add(x1 + 1, y0, val);
      othx->add(x1 + 1, y1 + 1, val);
    } else if (yo) {
      auto othy = get_tree(x0, y0 + 1);

      cur->add(x1 + 1, y0, val);
      othy->add(x0, y1 + 1, val);
      othy->add(x1 + 1, y1 + 1, val);      
    } else {
      cur->add(x0, y1 + 1, val);
      cur->add(x1 + 1, y0, val);
      cur->add(x1 + 1, y1 + 1, val);
    }
  }

  ll get (int x0, int y0, int x1, int y1) {
    return get(x0 - 1, y0 - 1) ^ get(x1, y0 - 1) ^ get(x0 - 1, y1) ^ get(x1, y1);
  }
};

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;

  auto ds = FenwickWrapper(n + 5);
  for (int i = 0; i < qc; i++) {
    int type;
    cin >> type;

    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    switch (type) {
    case 1:
      cout << ds.get(x0, y0, x1, y1) << '\n';
      break;
    case 2:
      ll val;
      cin >> val;
      ds.upd(x0, y0, x1, y1, val);
    }
  }
}