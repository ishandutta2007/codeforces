#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> h(m);
  for (int& x: h) cin >> x;
  int s = accumulate(h.begin(), h.end(), 0);
  int k = (s+n-1)/n;
  h[0] += k*n-s;
  cout << k << '\n';

  vector<int> ord(m);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&] (int x, int y) {return h[x] < h[y];});

  vector<int> a(m);
  vector<vector<int>> ops(k, vector<int>(m));
  for (int i = 0; i <= m-k; i++) {
    a[i] = h[ord[i]];
    for (int j = 0; j < k; j++) {
      h[ord[i+j]] -= a[i];
      ops[j][i] = ord[i+j]+1;
    }
    n -= a[i];
  }

  // there are less than k groups left. what now?
  // be greedy?
  int start = max(0, m-k+1);
  for (int i = start; i < m; i++) {
    if (!n) break;
    auto calc = [&] (int x) {
      int z = 0;
      for (int j = start; j < m; j++) {
        z += h[ord[j]]/x;
      }
      return z;
    };
    int mn = 1e9;
    for (int j = start; j < m; j++) {
      if (h[ord[j]] > 0) {
        mn = min(mn, h[ord[j]]);
      }
    }
    if (calc(mn) >= k) {
      a[i] = mn;
    }
    else {
      int low = 1;
      int high = n+1;
      while (high-low > 1) {
        int mid = (low+high)/2;
        if (calc(mid) >= k) low = mid;
        else high = mid;
      }
      a[i] = low;
    }
    int cur = 0;
    for (int j = start; j < m && cur < k; j++) {
      while (h[ord[j]] >= a[i]) {
        ops[cur++][i] = ord[j]+1;
        h[ord[j]] -= a[i];
        if (cur >= k) break;
      }
    }
    n -= a[i];
  }

  for (int x: a) {
    cout << x << ' ';
  }
  cout << '\n';
  for (vector<int>& op: ops) {
    for (int x: op) {
      cout << max(x, 1) << ' ';
    }
    cout << '\n';
  }
}