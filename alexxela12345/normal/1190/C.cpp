#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, k;
string s;

struct mdata {
  int l0, r0, l1, r1;

  mdata() {}

  mdata(char c, int pos) {
    l0 = INF;
    r0 = -INF;
    l1 = INF;
    r1 = -INF;
    if (c == '0') {
      l0 = pos;
      r0 = pos;
    } else {
      l1 = pos;
      r1 = pos;
    }
  }


  mdata(mdata a, mdata b) {
    l0 = min(a.l0, b.l0);
    r0 = max(a.r0, b.r0);
    l1 = min(a.l1, b.l1);
    r1 = max(a.r1, b.r1);
  }
};

vector<mdata> tree;

void build(int v, int l, int r) {
  if (l + 1 == r) {
    tree[v] = mdata(s[l], l);
  } else {
    int m = l + (r - l) / 2;
    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);
    tree[v] = mdata(tree[2 * v + 1], tree[2 * v + 2]);
  }
}

mdata get(int v, int l, int r, int ql, int qr, int x) {
  if (ql >= r || qr <= l) {
    return tree[v];
  }
  if (ql <= l && r <= qr) {
    if (x == 0) {
      mdata a;
      a.l0 = l;
      a.r0 = r - 1;
      a.l1 = INF;
      a.r1 = -INF;
      return a;
    } else {
      mdata a;
      a.l1 = l;
      a.r1 = r - 1;
      a.l0 = INF;
      a.r0 = -INF;
      return a;
    }
  }
  int m = l + (r - l) / 2;
  return mdata(get(2 * v + 1, l, m, ql, qr, x),
               get(2 * v + 2, m, r, ql, qr, x));
}

bool check_first() {
  mdata a = tree[0];
  if (a.r0 - a.l0 + 1 <= k) {
    return true;
  }
  if (a.r1 - a.l1 + 1 <= k) {
    return true;
  }
  return false;
}

bool check_second() {
  bool bad = 0;
  for (int i = 0; i + k <= n; i++) {
    mdata a;
    bool can = 0;
    a = get(0, 0, n, i, i + k, 0);
    if (a.r0 - a.l0 + 1 <= k) {
      can = 1;
    }
    if (a.r1 - a.l1 + 1 <= k) {
      can = 1;
    }
    if (!can)
      bad = 1;
    a = get(0, 0, n, i, i + k, 1);
    if (a.r0 - a.l0 + 1 <= k) {
      can = 1;
    }
    if (a.r1 - a.l1 + 1 <= k) {
      can = 1;
    }
    if (!can)
      bad = 1;
  }
  return !bad;
}


int main() {
  cin >> n >> k;
  cin >> s;
  tree.resize(4 * n);
  build(0, 0, n);
  if (check_first()) {
    cout << "tokitsukaze";
  } else if (check_second()) {
    cout << "quailty";
  } else {
    cout << "once again";
  }
  cout << endl;
}