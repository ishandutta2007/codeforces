#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0;
    int r = 0;
    ll lsum = 0;
    ll rsum = 0;
    int best = 0;
    int lbest, rbest;
    while (r < n) {
      while (lsum-rsum <= s) {
        if (r == n) {
          if (r-l > best) {
            best = r-l;
            lbest = l+1;
            rbest = r;
          }
          break;
        }
        rsum += a[r];
        r++;
      }
      if (r-1-l > best) {
        best = r-l-1;
        lbest = l+1;
        rbest = r-1;
      }
      lsum += a[l];
      l++;
    }
    if (best) cout << lbest << ' ' << rbest << '\n';
    else cout << "-1\n";
  }
}