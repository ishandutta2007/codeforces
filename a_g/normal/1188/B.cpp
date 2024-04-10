#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, p, k;
  cin >> n >> p >> k;
  map<int, int> counts;
  ll ans = 0;
  while (n--) {
    ll val;
    cin >> val;
    ll res;
    res = val*val % p;
    res = res*res % p;
    res = (res+(p-k)*val) % p;
    ans += counts[res];
    counts[res]++;
  }
  cout << ans << '\n';
}