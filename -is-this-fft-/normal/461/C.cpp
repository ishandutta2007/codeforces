#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;

class Fenwick {
  int n;
  vector<int> tree;

public:
  Fenwick (int _n) : n(_n), tree(n) {}

  void add (int idx, int val) {
    idx++;
    for (int i = idx; i < n; i += i & -i) {
      tree[i] += val;
    }
  }
  
  int get (int idx) {
    idx++;
    int ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      ans += tree[i];
    }
    return ans;
  }

  int get (int l, int r) {
    if (l > r) swap(l, r);
    return get(r) - get(l - 1);
  }

  int at (int idx) {
    return get(idx) - get(idx - 1);
  }
};

int dir;
int our_l;

int to_our_pos (int x) {
  return our_l + dir * x;
}

int main () {
  ios::sync_with_stdio(false);

  int n, qc;
  cin >> n >> qc;
  
  Fenwick cnt (MAX_N);
  for (int i = 0; i < n; i++) {
    cnt.add(i, 1);
  }

  our_l = 0;

  int cur_w = n;
  dir = 1;
  for (int t = 0; t < qc; t++) {
    int type;
    cin >> type;
    
    if (type == 1) {
      int p;
      cin >> p;
      
      if (2 * p <= cur_w) {
        vector<pair<int, int>> to_add;
        for (int i = 0; i < p; i++) {
          int npos = p + (p - i) - 1;
          int val = cnt.at(to_our_pos(i));
          to_add.push_back(make_pair(npos, val));
        }
        
        for (auto pr : to_add) {
          cnt.add(to_our_pos(pr.first), pr.second);
        }

        our_l += dir * p;
      } else {
        vector<pair<int, int>> to_add;
        for (int i = p; i < cur_w; i++) {
          int npos = p + (p - i) - 1;
          int val = cnt.at(to_our_pos(i));
          to_add.push_back(make_pair(npos, val));
        }

        for (auto pr : to_add) {
          cnt.add(to_our_pos(pr.first), pr.second);
        }

        if (dir == 1) {
          our_l = our_l + p - 1;
        } else {
          our_l = our_l - p + 1;
        }
        dir *= -1;
      }

      cur_w = max(p, cur_w - p);
    } else {
      int l, r;
      cin >> l >> r;
      r--;

      
      cout << cnt.get(to_our_pos(l), to_our_pos(r)) << '\n';
    }
  }
}