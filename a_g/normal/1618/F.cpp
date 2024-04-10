#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool good(ll x, ll y) {
  if (x == y) return 1;
  vector<int> xbits;
  vector<int> ybits;
  for (int i = 0; i < 64; i++) {
    xbits.push_back((x>>i)&1);
    ybits.push_back((y>>i)&1);
  }
  while (xbits.back() == 0) xbits.pop_back();
  while (ybits.back() == 0) ybits.pop_back();
  if (xbits[0] == 0) {
    ll newx = x;
    while (newx % 2 == 0) newx >>= 1;
    if (good(newx, y)) return 1;
    if (good(2*x+1, y)) return 1;
    return 0;
  }

  int m = xbits.size();
  int n = ybits.size();
  assert(xbits[0] == 1 && xbits[m-1] == 1 && ybits[n-1] == 1);
  for (int i = 0; i+m-1 < n; i++) {
    bool good = 1;
    if (i > 0 && ybits[i-1] == 0) break;
    for (int j = 0; j < m; j++) {
      if (ybits[i+j] != xbits[j]) good = 0;
    }
    for (int j = i+m; j < n; j++) {
      if (ybits[j] == 0) good = 0;
    }
    if (good) return 1;
  }

  reverse(xbits.begin(), xbits.end());
  for (int i = 0; i+m-1 < n; i++) {
    bool good = 1;
    if (i > 0 && ybits[i-1] == 0) break;
    for (int j = 0; j < m; j++) {
      if (ybits[i+j] != xbits[j]) good = 0;
    }
    for (int j = i+m; j < n; j++) {
      if (ybits[j] == 0) good = 0;
    }
    if (good) return 1;
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll x, y;
  cin >> x >> y;
  cout << (good(x, y) ? "YES" : "NO") << '\n';

}