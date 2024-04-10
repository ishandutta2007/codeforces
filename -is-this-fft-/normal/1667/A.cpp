#include <iostream>

using namespace std;

const int MAX_N = 5e3 + 5;

typedef long long ll;

const ll INF = 1e18 + 6000;

ll arr [MAX_N];

ll solve (int n, int zp) {
  ll ans = 0;
  ll cur = 0;
  for (int i = zp + 1; i < n; i++) {
    ll times = 1 + cur / arr[i];
    ans += times;
    cur = times * arr[i];
  }

  cur = 0;
  for (int i = zp - 1; i >= 0; i--) {
    ll times = 1 + cur / arr[i];
    ans += times;
    cur = times * arr[i];    
  }

  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll ans = INF;
  for (int i = 0; i < n; i++) {
    ans = min(ans, solve(n, i));
  }
  cout << ans << '\n';
}