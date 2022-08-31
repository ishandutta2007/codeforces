#include <iostream>

typedef long long ll;

using namespace std;

ll gcd (ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

void try_val_mod_k (ll l, ll k, ll n, ll &min_ans, ll &max_ans) {
  for (ll cur_l = l; cur_l < k * n; cur_l += k) {
    ll jumpc = k * n / gcd(k * n, cur_l);
    min_ans = min(min_ans, jumpc);
    max_ans = max(max_ans, jumpc);
  }
}

int main () {
  ll n, k;
  cin >> n >> k;

  ll a, b;
  cin >> a >> b;

  ll min_ans = 1LL << 60;
  ll max_ans = -1;
  try_val_mod_k((b - a + 6 * k) % k, k, n, min_ans, max_ans);
  try_val_mod_k(((k - b) - a + 6 * k) % k, k, n, min_ans, max_ans);
  try_val_mod_k((b - (k - a) + 6 * k) % k, k, n, min_ans, max_ans);
  try_val_mod_k(((k - b) - (k - a) + 6 * k) % k, k, n, min_ans, max_ans);

  cout << min_ans << " " << max_ans << endl;
}