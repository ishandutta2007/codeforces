#include <iostream>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

void solve () {
  int n;
  ll X;
  cin >> n >> X;
  
  map<ll, int> cnt;
  set<ll> seen;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;

    cnt[a]++;
    seen.insert(a);
  }

  int ans = 0;
  for (ll a : seen) {
    ll nxt = X * a;
    int del = min(cnt[a], cnt[nxt]);
    cnt[a] -= del;
    cnt[nxt] -= del;
    ans += cnt[a];
  }
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