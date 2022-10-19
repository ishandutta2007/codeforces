#include <bits/stdc++.h>
using namespace std;

const int K = 20;
int L[1<<K], R[1<<K];

// (f_r * f_{r-1} * ... * f_l)(s) vs t
// (f_1 * ... * f_{l-1})(s) vs (f_1 * f_2 * ... * f_r)(t)

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  string s, t;
  cin >> n >> m >> k >> s >> t;
  fill(L, L+(1<<k), n);

  vector<vector<int>> p(n+1, vector<int>(k));
  iota(p[0].begin(), p[0].end(), 0);
  for (int i = 0; i < n; i++) {
    p[i+1] = p[i];
    int x, y;
    cin >> x >> y;
    swap(p[i+1][x-1], p[i+1][y-1]);
  }

  for (int i = n; i >= 0; i--) {
    int mask = 0;
    for (int j = 0; j < k; j++) {
      if (s[j] == '1') mask |= 1<<p[i][j];
    }
    L[mask] = i;
  }
  for (int i = 0; i <= n; i++) {
    int mask = 0;
    for (int j = 0; j < k; j++) {
      if (t[j] == '1') mask |= 1<<p[i][j];
    }
    R[mask] = i;
  }

  for (int i = 0; i < k; i++) {
    for (int mask = 0; mask < (1<<k); mask++) {
      if (!((mask>>i)&1)) {
        L[mask] = min(L[mask], L[mask|(1<<i)]);
        R[mask] = max(R[mask], R[mask|(1<<i)]);
      }
    }
  }

  int best = 0;
  for (int mask = 0; mask < (1<<k); mask++) {
    if (R[mask]-L[mask] >= m &&  __builtin_popcount(mask) > __builtin_popcount(best)) {
      best = mask;
    }
  }

  cout << k-count(s.begin(), s.end(), '1')-count(t.begin(), t.end(), '1')+2*__builtin_popcount(best) << '\n';
  cout << L[best]+1 << ' ' << R[best] << '\n';
}