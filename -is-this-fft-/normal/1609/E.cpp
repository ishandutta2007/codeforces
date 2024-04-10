#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9 + 2500;

class Segtree {
  int n;
  vector<int> tree;
  vector<int> lazy;
  vector<int> lfend;
  vector<int> rgend;

  void propagate (int u) {
    tree[u] += lazy[u];
    
    if (u < n) {
      lazy[2 * u] += lazy[u];
      lazy[2 * u + 1] += lazy[u];
    }
    
    lazy[u] = 0;
  }
  
public:
  Segtree () {
  }
  
  Segtree (const vector<int> &init) {
    n = 1;
    while (n < (int) init.size()) {
      n *= 2;
    }

    tree = vector<int> (2 * n);
    lfend = vector<int> (2 * n);
    rgend = vector<int> (2 * n);
    lazy = vector<int> (2 * n, 0);
    for (int i = n; i < 2 * n; i++) {
      if (i - n < (int) init.size()) {
        tree[i] = init[i - n];
      } else {
        tree[i] = 0;
      }

      lfend[i] = i - n;
      rgend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      tree[i] = min(tree[2 * i], tree[2 * i + 1]);
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
    }
  }

  int query (int ql, int qr, int u = 1) {
    propagate(u);

    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) {
      return INF;
    }

    if (ql == lfend[u] && qr == rgend[u]) {
      return tree[u];
    }

    return min(query(ql, qr, 2 * u),
               query(ql, qr, 2 * u + 1));
  }

  void add (int ql, int qr, int x, int u = 1) {
    propagate(u);

    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) {
      return;
    }

    if (ql == lfend[u] && qr == rgend[u]) {
      lazy[u] += x;
      propagate(u);
      return;
    }

    add(ql, qr, x, 2 * u);
    add(ql, qr, x, 2 * u + 1);
    tree[u] = min(tree[2 * u], tree[2 * u + 1]);
  }
};

const int MAX_N = 1e5 + 5;

char arr [MAX_N];

int n;
Segtree tree1, tree2;
int cc;

int fpmin (int pos) {
  int cmin = tree1.query(0, pos - 1);

  int ans = 0;
  for (int k = 1 << 17; k != 0; k /= 2) {
    if (ans + k <= n && tree1.query(0, ans + k) >= cmin) {
      ans += k;
    }
  }
  return ans + 1;
}

void incrtree1 (int pos) {
  int t2 = fpmin(pos);
  if (t2 <= n) {
    tree2.add(t2, n, 1);
  }

  tree1.add(pos, n, 1);
}

void decrtree1 (int pos) {
  tree1.add(pos, n, -1);

  int t2 = fpmin(pos);
  if (t2 <= n) {
    tree2.add(t2, n, -1);
  }
}

void change (int pos, char c) {
  if (arr[pos] == 'a') {
    decrtree1(pos);
  } else if (arr[pos] == 'b') {
    incrtree1(pos);
    tree2.add(pos, n, -1);
  } else if (arr[pos] == 'c') {
    tree2.add(pos, n, 1);
    cc--;
  }

  arr[pos] = c;

  if (arr[pos] == 'a') {
    incrtree1(pos);
  } else if (arr[pos] == 'b') {
    decrtree1(pos);
    tree2.add(pos, n, 1);
  } else if (arr[pos] == 'c') {
    tree2.add(pos, n, -1);
    cc++;
  }
}

int solve () {
  return cc + tree2.query(0, n);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int qc;
  cin >> n >> qc;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  vector<int> as (n + 1, 0);
  int ab = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 'a') ab++;
    else if (arr[i] == 'b') ab--;

    as[i] = ab;
  }

  tree1 = Segtree(as);

  vector<int> bs (n + 1, 0);
  int bc = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 'b') bc++;
    else if (arr[i] == 'c') bc--;

    bs[i] = bc;
  }

  for (int i = 0; i <= n; i++) {
    bs[i] += tree1.query(0, i);
  }

  tree2 = Segtree(bs);

  for (int i = 1; i <= n; i++) {
    if (arr[i] == 'c') cc++;
  }

  for (int i = 0; i < qc; i++) {
    int pos;
    char c;
    cin >> pos >> c;

    change(pos, c);
    cout << solve() << '\n';
  }
}