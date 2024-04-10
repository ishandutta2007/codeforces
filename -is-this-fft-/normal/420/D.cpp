#include <iostream>

using namespace std;

void failure () {
  cout << -1 << endl;
  exit(0);
}

struct Cup {
  int key, init, mark;
};

bool operator< (Cup p, Cup q) {
  return p.key < q.key;
}

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
  rb_tree_tag, tree_order_statistics_node_update>;

// cur.order_of_key(2)
// the number of elements in the set less than 2
// *cur.find_by_order(1)
// the 1-st smallest number in the set(0-based)

const int MAX_N = 1e6 + 5;

ordered_set<Cup> row;

int seen [MAX_N];

// with mark x, at position y on time t (t is just for the keys)
// y should be 0-based
void op (int x, int y, int t) {
  Cup cur = *row.find_by_order(y);
  row.erase(cur);

  if (cur.mark != 0 && cur.mark != x) {
    failure();
  }

  if (cur.mark == 0 && seen[x]) {
    failure();
  }

  cur.mark = x;
  seen[x] = 1;
  cur.key = -t;
  row.insert(cur);
}

int ans [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    Cup cup;
    cup.key = i;
    cup.init = i;
    cup.mark = 0;
    row.insert(cup);
  }

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    y--;

    op(x, y, i);
  }

  set<int> unused;
  for (int i = 1; i <= n; i++) {
    if (!seen[i]) {
      unused.insert(i);
    }
  }

  for (Cup cup : row) {
    if (cup.mark == 0) {
      cup.mark = *unused.begin();
      unused.erase(cup.mark);
    }

    ans[cup.init] = cup.mark;
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}