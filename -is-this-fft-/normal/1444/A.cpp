#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int SQR = 4e4 + 5;

vector<pair<ll, int>> factors (int x) {
  vector<pair<ll, int>> ans;
  for (int i = 2; i < SQR; i++) {
    if (x % i == 0) {
      int cnt = 0;
      while (x % i == 0) {
        cnt++;
        x /= i;
      }
      ans.push_back(make_pair(i, cnt));
    }
  }

  if (x != 1) {
    ans.push_back(make_pair(x, 1));
  }
  return ans;
}

int cnt_prime (ll x, int p) {
  int ans = 0;
  while (x % p == 0) {
    ans++;
    x /= p;
  }
  return ans;
}

ll exp (ll p, int k) {
  ll ans = 1;
  for (int i = 0; i < k; i++) {
    ans *= p;
  }
  return ans;
}

void solve () {
  ll p;
  int q;
  cin >> p >> q;

  auto fs = factors(q);
  ll ans = 0;
  for (auto pr : fs) {
    int cnt = cnt_prime(p, pr.first);
    int rem = max(0, cnt - pr.second + 1);
    ans = max(ans, p / exp(pr.first, rem));
  }
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}