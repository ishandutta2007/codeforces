#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

typedef long long ll;
typedef long double ldb;

const int MOD = 998244353;

int mul(int a, int b) { return 1LL * a * b % MOD; }

int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) {
      ans = mul(ans, a);
    }
    b >>= 1;
    a = mul(a, a);
  }
  return ans;
}

int rev(int a) { return pow(a, MOD - 2); }

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnts;
  int cur = 0;
  for (char c : s) {
    if (c == '0') {
      cnts.push_back(cur);
      cur = 0;
    } else {
      cur++;
    }
  }
  cnts.push_back(cur);
  int m = 0;
  for (int el : cnts) {
    if (el % 2) {
      el--;
      n--;
    }
    m += el / 2;
  }
  n -= m;
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = mul(ans, i);
  }
  for (int i = 1; i <= m; i++) {
    ans = mul(ans, rev(i));
  }
  for (int i = 1; i <= n - m; i++) {
    ans = mul(ans, rev(i));
  }
  cout << ans << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}