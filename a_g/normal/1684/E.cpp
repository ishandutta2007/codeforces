#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<bool> seen(n+1);
    for (int& x: a) {
      cin >> x;
      if (x < n) {
        seen[x] = 1;
      }
    }
    sort(a.begin(), a.end());
    int mex = 0;
    int ops = 0;
    int holes = 0;
    while (mex < n) {
      if (seen[mex]) mex++;
      else if (ops < k) {
        mex++;
        ops++;
        holes++;
      }
      else {
        break;
      }
    }
    int pr = -1;
    int sz = 0;
    vector<int> groups;
    for (int x: a) {
      if (x < mex) continue;
      if (x == pr) {
        sz++;
        continue;
      }
      if (pr != -1) {
        groups.push_back(sz);
      }
      pr = x;
      sz = 1;
    }
    if (sz) groups.push_back(sz);
    sort(groups.begin(), groups.end());
    int diff = mex + groups.size();
    int m = 0;
    for (int z: groups) {
      if (m+z <= k) {
        m += z;
        diff--;
      }
      else {
        break;
      }
    }
    cout << diff-mex << '\n';
  }
}