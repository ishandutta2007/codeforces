#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 100100;

int n;
ll k;
ll s[M];

void read() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    s[i + 1] = x + s[i];
  }
}

ll cnt(ll t) {
  ll ans = 0;
  map<ll, int> cur;
  for (int i = 0; i <= n; ++i) {
    ans += cur[s[i] - t];
    cur[s[i]]++;
  }
  return ans;
}

ll mabs(ll k) {
  return k < 0 ? -k : k;
}

void kill() {
  ll ans = 0;
  ans += cnt(1);
  if (k == -1) {
    ans += cnt(-1);
  } else if (mabs(k) >= 2) {
    ll pw = k;
    while (mabs(pw) <= 2e14) {
      ans += cnt(pw);
      pw *= k;
    }
  }
  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}