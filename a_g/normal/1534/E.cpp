#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int c[N];

int query(vector<int> b) {
  cout << "?";
  for (int x: b) {
    cout << " " << x;
  }
  cout << endl;
  int r;
  cin >> r;
  return r;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (n%2 == 1 && k%2 == 0) {
    cout << -1 << endl;
    return 0;
  }
  fill(c+1, c+n+1, 1);
  int z = n;
  int u = 1;
  while (z%k != 0 || z/k < c[1]) {
    c[u++] += 2;
    z += 2;
    if (u > n) u -= n;
  }

  int iters = z/k;
  int ans = 0;
  while (iters--) {
    vector<int> prio(n);
    iota(prio.begin(), prio.end(), 1);
    sort(prio.begin(), prio.end(), [&] (int x, int y) {return c[x] > c[y];});
    prio.resize(k);
    for (int x: prio) c[x]--;
    ans ^= query(prio);
  }
  cout << "! " << ans << endl;
}