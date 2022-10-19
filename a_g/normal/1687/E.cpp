#include <bits/stdc++.h>
using namespace std;

const int M = 1e6+2;
const int N = 1e5+2;
int a[N];
int lpf[M], dpf[M];

int gcd(int a, int b) {
  if (a == -1) return b;
  if (b == -1) return a;
  return __gcd(a, b);
}

vector<int> find_gcd_set(vector<int>& indices) {
  int target = -1;
  int g = -1;
  for (int i: indices) {
    target = gcd(target, a[i]);
  }

  vector<int> ans;

  while (g != target) {
    int best_index = -1;
    int b = 1e9;
    for (int i: indices) {
      int k = dpf[gcd(g, a[i])/target];
      if (k < b) {
        best_index = i;
        b = k;
      }
    }
    ans.push_back(best_index);
    g = gcd(g, a[best_index]);
  }
  return ans;
}


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  iota(lpf, lpf+M, 0);
  for (int i = 2; i < M; i++) {
    if (lpf[i] == i) {
      for (int j = i; j < M; j += i) {
        lpf[j] = i;
        dpf[j]++;
      }
    }
  }

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<int> indices(n);
  iota(indices.begin(), indices.end(), 1);
  vector<int> use = find_gcd_set(indices);

  indices.clear();
  for (int i = 1; i <= n; i++) {
    if (find(use.begin(), use.end(), i) == use.end()) {
      indices.push_back(i);
    }
  }
  for (int k: find_gcd_set(indices)) {
    use.push_back(k);
  }

  int m = use.size();
  assert(m <= 14);
  sort(use.begin(), use.end());
  vector<vector<int>> ops;
  for (int mask = 1; mask < (1<<m); mask++) {
    int z = __builtin_popcount(mask);
    vector<int> op;
    op.push_back(1-(z&1) || z == 1 ? 0 : 1);
    op.push_back(z);
    for (int j = 0; j < m; j++) {
      if (mask&(1<<j)) {
        op.push_back(use[j]);
      }
    }
    for (int k = 0; k < abs(z-2); k++) {
      ops.push_back(op);
    }
  }
  cout << ops.size() << '\n';
  for (vector<int>& op: ops) {
    for (int x: op) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}