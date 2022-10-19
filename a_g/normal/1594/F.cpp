#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool valid(ll s, ll n, ll k) {
  if (s < k) return 0;
  if (s == k) return 1;
  if (k > n/((s-n)/k+1)) return 0;
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll s, n, k;
    cin >> s >> n >> k;
    cout << (valid(s, n, k) ? "YES\n" : "NO\n");
  }
}