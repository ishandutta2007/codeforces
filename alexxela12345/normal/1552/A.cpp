#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#ifndef LOCAL
#define endl '\n'
#endif

//#define int long long

#define sz(v) ((int)(v).size())
#define all(x) (x).begin(),(x).end()

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string s2 = s;
  sort(s2.begin(), s2.end());
  int ans = n;
  for (int i = 0; i < n; i++) {
    if (s[i] == s2[i])
      ans--;
  }
  cout << ans << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}