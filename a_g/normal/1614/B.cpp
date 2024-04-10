#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
      int d;
      cin >> d;
      a[i] = {-d, i+1};
    }
    sort(a.begin(), a.end());
    vector<int> ans(n+1);
    ll val = 1;
    ll T = 0;
    for (pii p: a) {
      ans[p.second] = val;
      T += abs(val)*(-p.first);
      if (val > 0) val = -val;
      else val = 1-val;
    }
    cout << 2*T << '\n';
    for (int i: ans) cout << i << ' ';
    cout << '\n';
  }
}