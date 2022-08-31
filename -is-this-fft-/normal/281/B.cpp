#include <iostream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ld, pair<ll, ll>> frac;
 
frac best;
void get_best (ll x, ll y, ll K) {
  ll xK = x * K;
 
  ll mna = xK / y;
  ll mxa = mna + 1;
  frac fmna = make_pair((ld) x / (ld) y - (ld) mna / (ld) K, make_pair(mna, K));
  best = min(best, fmna);
  frac fmxa = make_pair((ld) mxa / (ld) K - (ld) x / (ld) y, make_pair(mxa, K));
  best = min(best, fmxa);
}
 
int main () {
  ios::sync_with_stdio(false);
 
  int x, y, n;
  cin >> x >> y >> n;
 
  best = make_pair(1e18, make_pair(0, 0));
  for (int i = 1; i <= n; i++) {
    get_best(x, y, i);
  }
 
  cout << best.second.first << "/" << best.second.second << endl;
}