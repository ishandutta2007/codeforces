#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int INF = 1e9;
const int MAXN = 1e6 + 10;

int tree[4 * MAXN];
int mod[4 * MAXN];

void push(int v, int l, int r) {
  tree[v] += mod[v];
  if (l + 1 != r) {
    mod[2 * v + 1] += mod[v];
    mod[2 * v + 2] += mod[v];
  }
  mod[v] = 0;
}

void update(int v, int l, int r, int ql, int qr, int val) {
  push(v, l, r);
  if (l >= qr || r <= ql) {
    return;
  }
  if (ql <= l && r <= qr) {
    mod[v] += val;
    push(v, l, r);
    return;
  }
  int m = l + (r - l) / 2;
  update(2 * v + 1, l, m, ql, qr, val);
  update(2 * v + 2, m, r, ql, qr, val);
  tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
}

int get(int v, int l, int r, int ql, int qr) {
  push(v, l, r);
  if (l >= qr || r <= ql) {
    return INF;
  }
  if (ql <= l && r <= qr) {
    return tree[v];
  }
  int m = l + (r - l) / 2;
  return min(get(2 * v + 1, l, m, ql, qr), get(2 * v + 2, m, r, ql, qr));
}

pair<int, int> get2(int v, int l, int r) {
  push(v, l, r);
  if (tree[v] >= 0) {
    return {INF, -1};
  }
  if (l + 1 == r) {
    return {tree[v], l};
  }
  int m = l + (r - l) / 2;
  auto ans1 = get2(2 * v + 2, m, r);
  if (ans1.first >= 0) {
    return get2(2 * v + 1, l, m);
  }
  return ans1;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
    update(0, 0, MAXN, 0, x + 1, -1);
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    b[i] = x;
    update(0, 0, MAXN, 0, x + 1, 1);
  }
  int q;
  cin >> q;
  while (q--) {
    int type, i, x;
    cin >> type >> i >> x;
    i--;
    if (type == 1) {
      update(0, 0, MAXN, 0, a[i] + 1, 1);
      a[i] = x;
      update(0, 0, MAXN, 0, a[i] + 1, -1);
    } else {
      update(0, 0, MAXN, 0, b[i] + 1, -1);
      b[i] = x;
      update(0, 0, MAXN, 0, b[i] + 1, 1);
    }
    auto xxx = get2(0, 0, MAXN);
    if (xxx.second == -1) {
      cout << -1 << endl;
    } else {
      cout << xxx.second << endl;
    }
  }
}