#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
const int M = 3e6;
int a[N];
int lchild[M];
int rchild[M];
int vals[M];
int mins[M];
int ptr = 1;
int ans[2*N];

void push(int v) {
  vals[lchild[v]] += vals[v];
  vals[rchild[v]] += vals[v];
  mins[lchild[v]] += vals[v];
  mins[rchild[v]] += vals[v];
  vals[v] = 0;
}

void combine(int v) {
  mins[v] = min(mins[lchild[v]], mins[rchild[v]]);
}

void add(int v, int tl, int tr, int l, int r, int x) {
  if (l > r) return;
  if (l == tl && r == tr) {
    vals[v] += x;
    mins[v] += x;
    return;
  }
  int tm = (tl+tr)/2;
  if (!lchild[v]) {
    assert(ptr < M);
    lchild[v] = ptr++;
  }
  if (!rchild[v]) {
    assert(ptr < M);
    rchild[v] = ptr++;
  }
  push(v);
  add(lchild[v], tl, tm, l, min(tm, r), x);
  add(rchild[v], tm+1, tr, max(l, tm+1), r, x);
  combine(v);
}

void add(int l, int r, int x) {
  add(0, 0, N, l, r, x);
}

int ceil(long long x, int y) {
  return (x+y-1)/y;
}

void debug(int v, int tl, int tr) {
  cout << v << " " << tl << " " << tr << " " << vals[v] << " " << mins[v] << '\n';
  int tm = (tl+tr)/2;
  if (lchild[v]) {
    debug(lchild[v], tl, tm);
  }
  if (rchild[v]) {
    debug(rchild[v], tm+1, tr);
  }
}

void debug() {
  debug(0, 0, N);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      add(0, a[i], 1);
    }

    vector<vector<int>> groups(m);
    vector<long long> sums(m);
    for (int i = 0; i < m; i++) {
      int k;
      cin >> k;
      groups[i].resize(k);
      for (int j = 0; j < k; j++) {
        cin >> groups[i][j];
        sums[i] += groups[i][j];
      }
      add(0, ceil(sums[i], k), -1);
    }

    int cur = 0;
    for (int i = 0; i < m; i++) {
      int k = groups[i].size();
      add(0, ceil(sums[i], k), 1);
      for (int val: groups[i]) {
        add(0, ceil(sums[i]-val, k-1), -1);
        ans[cur++] = mins[0] >= 0;
        add(0, ceil(sums[i]-val, k-1), 1);
      }
      add(0, ceil(sums[i], k), -1);
    }

    for (int i = 0; i < n; i++) {
      add(0, a[i], -1);
    }

    for (int i = 0; i < m; i++) {
      add(0, ceil(sums[i], groups[i].size()), 1);
    }

    for (int i = 0; i < cur; i++) {
      cout << ans[i];
    }
    cout << '\n';
  }
}