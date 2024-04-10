#include <iostream>
#include <vector>

using namespace std;

class Fenwick {
  int n;
  vector<int> tree;
  
public:
  Fenwick (int _n) : n(_n), tree(_n, 0) {
  }

  void upd (int pos, int val) {
    for (int i = pos; i < n; i += i & -i) {
      tree[i] = max(tree[i], val);
    }
  }

  int get (int pos) {
    int ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
      ans = max(ans, tree[i]);
    }
    return ans;
  }
};

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  auto dp = Fenwick(n + 5);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    dp.upd(x, 1 + dp.get(x - 1));
  }
  cout << dp.get(n + 1) << '\n';
}