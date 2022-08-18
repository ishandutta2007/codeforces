#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Seg {
  int sum;
  int msum; // value, absolute position
};

Seg merge (Seg p, Seg q) {
  Seg ans;
  ans.sum = p.sum + q.sum;
  ans.msum = min(p.msum, p.sum + q.msum);
  return ans;
}

Seg from (int x) {
  Seg ans;
  ans.sum = x;
  ans.msum = x;
  return ans;
}

class Segtree {
  int n;
  vector<Seg> tree;

public:
  Segtree (int _n) {
    n = 1;
    while (n < _n) {
      n *= 2;
    }

    tree = vector<Seg> (2 * n);

    for (int i = n; i < 2 * n; i++) {
      tree[i].sum = 0;
      tree[i].msum = 0;
    }

    for (int i = n - 1; i > 0; i--) {
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
  }

  void set (int pos, Seg value) {
    tree[n + pos] = value;
    for (int u = (n + pos) / 2; u != 0; u /= 2) {
      tree[u] = merge(tree[2 * u], tree[2 * u + 1]);
    }
  }

  int get () {
    return tree[1].msum;
  }
};

const int MAX_N = 1e6 + 5;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
  rb_tree_tag, tree_order_statistics_node_update>;

// cur.order_of_key(2)
// the number of elements in the set less than 2
// *cur.find_by_order(1)
// the 1-st smallest number in the set(0-based)

typedef long long ll;

void solve () {
  int n, m;
  cin >> n >> m;

  // <time, type>
  // -x - at x becomes 0
  // 0 - query at time
  // x - at x becomes -1

  ll ans = 0;
  vector<pair<int, int>> events;
  ordered_set<pair<int, int>> seen; // <value, pos>
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    ans += (int) seen.size() - seen.order_of_key(make_pair(x, MAX_N));
    
    events.push_back(make_pair(x, -(i + 1)));
    events.push_back(make_pair(x, i + 1));
    seen.insert(make_pair(x, i));
  }

  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;

    events.push_back(make_pair(x, 0));
  }

  Segtree tree (n);
  for (int i = 0; i < n; i++) {
    tree.set(i, from(1));
  }
  
  sort(events.begin(), events.end());

  int add = 0;
  for (auto e : events) {
    if (e.second == 0) {
      ans += add + min(0, tree.get());
    } else if (e.second < 0) {
      int pos = -e.second - 1;
      tree.set(pos, from(0));
    } else {
      int pos = e.second - 1;
      tree.set(pos, from(-1));
      add++;
    }
  }

  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}