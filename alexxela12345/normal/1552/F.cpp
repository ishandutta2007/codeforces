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

const int MOD = 998244353;

int add(int a, int b) {
  return (a + b) % MOD;
}

int sub(int a, int b) {
  return (a - b + MOD) % MOD;
}

int mul(int a, int b) {
  return 1LL * a * b % MOD;
}

void solve() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), s(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> s[i];
  }
  vector<int> a(n);
  vector<int> pref(n + 1);
  for (int i = 0; i < n; i++) {
    int j = lower_bound(all(x), y[i]) - x.begin();
    a[i] = add(sub(x[i], y[i]), sub(pref[i], pref[j]));
    pref[i + 1] = add(pref[i], a[i]);
  }
  int ans = (x[n - 1] + 1) % MOD;
  for (int i = 0; i < n; i++) {
    if (s[i])
      ans = add(ans, a[i]);
  }
  ans %= MOD;
  cout << ans << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}