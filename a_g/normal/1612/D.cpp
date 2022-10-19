#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool solve2(ll a, ll b, ll x) {
  if (max(a, b) < x) return 0;
  if (a < b) swap(a, b);
  if (a % b == x % b) return 1;
  if (a % b == 0) return 0;
  return solve2(b, a-(a/b)*b, x);
}

bool solve() {
  ll a, b, x;
  cin >> a >> b >> x;
  return solve2(a, b, x);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cout << (solve() ? "YES\n" : "NO\n");
  }
}