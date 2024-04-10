#include <bits/stdc++.h>
using namespace std;

vector<int> factor(int x) {
  vector<int> ans;
  for (int i = 1; i*i <= x; i++) {
    if (x%i == 0) {
      ans.push_back(i);
      if (x/i != i) ans.push_back(x/i);
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> fa = factor(a);
    vector<int> fb = factor(b);
    vector<long long> fab;
    for (int x: fa) {
      for (int y: fb) {
        fab.push_back(1LL*x*y);
      }
    }
    sort(fab.begin(), fab.end());
    fab.resize(unique(fab.begin(), fab.end())-fab.begin());
    int ansx = -1;
    int ansy = -1;
    for (long long x: fab) {
      long long y = 1LL*a*b/x;
      long long p = x*(a/x+1);
      long long q = y*(b/y+1);
      if (p <= c && q <= d) {
        ansx = p;
        ansy = q;
      }
    }
    cout << ansx << ' ' << ansy << '\n';
  }
}