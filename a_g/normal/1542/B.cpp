#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool good(ll n, ll a, ll b) {
  set<int> seen;
  ll x = 1;
  while (x <= n) {
    if (x % b == n % b) return 1;
    if (seen.count(x % b)) return 0;
    seen.insert(x % b);
    x *= a;
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll n, a, b;
    cin >> n >> a >> b;
    cout << (good(n, a, b) ? "Yes" : "No") << endl;
  }
}