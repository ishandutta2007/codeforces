#include <iostream>
#include <string>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;

mt19937 rng;
const int MOD = 1e9 + 2017;

vector<ll> mults;
vector<ll> xorer;

ll calc_hsh (const string &s, int l, int r, int d) {
  if ((r - l) % 2 == 0) {
    ll ans = 
      (((calc_hsh(s, l, l + (r - l) / 2, d + 1) *
         calc_hsh(s, l + (r - l) / 2, r, d + 1)) % mults[d]) ^ xorer[d]) % MOD;
    // cout << s << " " << l << " " << r << " " << d << " " << ans << endl;
    return ans;
  }

  ll ans = 0;
  for (int i = l; i < r; i++) {
    ans *= 31;
    ans += s[i] - 'a' + 3;
    ans %= MOD;
  }
  return ans;
}

bool solve (string a, string b) {
  mults.clear();
  xorer.clear();
  for (int i = 0; i < 30; i++) {
    mults.push_back(rng() % MOD);
    xorer.push_back(rng() % MOD);
  }

  return calc_hsh(a, 0, a.size(), 0) == calc_hsh(b, 0, b.size(), 0);
}

int main () {
  rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
  
  string a, b;
  cin >> a >> b;

  if (solve(a, b) && solve(a, b) && solve(a, b) && solve(a, b) &&
      solve(a, b) && solve(a, b) && solve(a, b) && solve(a, b) &&
      solve(a, b) && solve(a, b) && solve(a, b) && solve(a, b)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}