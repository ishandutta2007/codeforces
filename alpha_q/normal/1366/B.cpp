#include <bits/stdc++.h>

using namespace std;

int t, n, x, m;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> x >> m;
    int lt = x, rt = x;
    while (m--) {
      int l, r;
      scanf("%d %d", &l, &r);
      if (max(l, lt) > min(r, rt)) continue;
      lt = min(lt, l), rt = max(rt, r);
    }
    cout << rt - lt + 1 << '\n';
  }
  return 0;
}