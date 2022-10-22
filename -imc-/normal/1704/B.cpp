#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read) {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int& x : a) cin >> x;

  int ns = 0;
  for (int l = 0; l < n;) {
    int r = l;
    int minv = a[l], maxv = a[l];
    while (r + 1 < n && abs(min(minv, a[r + 1]) - max(maxv, a[r + 1])) <= 2 * x) {
      minv = min(minv, a[r + 1]);
      maxv = max(maxv, a[r + 1]);
      ++r;
    }
    ++ns;
    l = r + 1;
  }
  cout << ns - 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#if 1
  int nt = 1;
  cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }
#endif

  //solve(false);

  return 0;
}