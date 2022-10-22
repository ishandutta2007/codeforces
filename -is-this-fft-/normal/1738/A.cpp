#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll solve (vector<ll> a, vector<ll> b) {
  if (a.empty()) {
    return 0;
  }

  ll ans = 0;
  ans += a.back();
  a.pop_back();

  int last = 0;
  int aptr = 0, bptr = 0;
  while (aptr < (int) a.size() || bptr < (int) b.size()) {
    if (last == 0) {
      if (bptr < (int) b.size()) {
        ans += 2 * b[bptr];
        bptr++;
        last = 1;
      } else {
        ans += a[aptr];
        aptr++;
        last = 0;
      }
    } else {
      if (aptr < (int) a.size()) {
        ans += 2 * a[aptr];
        aptr++;
        last = 0;
      } else {
        ans += b[bptr];
        bptr++;
        last = 1;
      } 
    }
  }

  return ans;
}

void solve () {
  int n;
  cin >> n;

  vector<ll> fi, fo;
  
  vector<ll> type (n);
  for (int i = 0; i < n; i++) {
    cin >> type[i];
  }
  
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;

    if (type[i] == 0) fi.push_back(x);
    else fo.push_back(x);
  }

  sort(fi.rbegin(), fi.rend());
  sort(fo.rbegin(), fo.rend());

  ll ans = max(solve(fi, fo), solve(fo, fi));
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}