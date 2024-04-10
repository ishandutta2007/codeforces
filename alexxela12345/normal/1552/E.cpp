#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#ifndef LOCAL
#define endl '\n'
#endif

//#define int long long

#define sz(v) ((int)(v).size())
#define all(x) (x).begin(),(x).end()

vector<int> tree;
vector<int> mod;

void push(int v, int l, int r) {
  tree[v] += mod[v];
  if (l + 1 != r) {
    mod[2 * v + 1] += mod[v];
    mod[2 * v + 2] += mod[v];
  }
  mod[v] = 0;
}

int get(int v, int l, int r, int ql, int qr) {
  push(v, l, r);
  if (ql <= l && r <= qr) {
    return tree[v];
  }
  if (l >= qr || ql >= r) {
    return 0;
  }
  int m = (l + r) / 2;
  return max(get(2 * v + 1, l, m, ql, qr), get(2 * v + 2, m, r, ql, qr));
}

void add(int v, int l, int r, int ql, int qr, int x) {
  push(v, l, r);
  if (ql <= l && r <= qr) {
    mod[v] += x;
    push(v, l, r);
    return;
  }
  if (l >= qr || ql >= r) {
    return;
  }
  int m = (l + r) / 2;
  add(2 * v + 1, l, m, ql, qr, x);
  add(2 * v + 2, m, r, ql, qr, x);
  tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
}

void solve() {
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<int> arr(n * k);
  for (int i = 0; i < n * k; i++) {
    cin >> arr[i];
    arr[i]--;
  }
  vector<int> used(n), last(n, -1);
  tree.clear();
  tree.resize(4 * n * k);
  mod.clear();
  mod.resize(4 * n * k);
  int mx = (n + k - 2) / (k - 1);
  vector<pair<int, int>> ans(n, {-1, -1});
  for (int i = 0; i < n * k; i++) {
    if (used[arr[i]]) {
      continue;
    }
    if (last[arr[i]] == -1) {
      last[arr[i]] = i;
      continue;
    }
    int l = last[arr[i]];
    int r = i + 1;
    if (get(0, 0, n * k, l, r) >= mx) {
      last[arr[i]] = i;
      continue;
    }
    ans[arr[i]] = {l, i};
    used[arr[i]] = 1;
    add(0, 0, n * k, l, r, 1);
  }
  for (auto &el : ans)
    if (el.first == -1) {
      assert(false);
    }
  for (auto &el : ans) {
    cout << el.first + 1 << " " << el.second + 1 << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}