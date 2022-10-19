#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define PI 3.14159265
const double eps = 1e-5;

class frac {
  public:
    ll num;
    ll denom;
    frac(ll a, ll b) {
      if (a == 0 && b == 0) {
        num = 0;
        denom = 0;
        return;
      }
      ll g = __gcd(a, b);
      a /= g;
      b /= g;
      if (b < 0) {
        a = -a;
        b = -b;
      }
      if (b == 0 && a < 0) {
        a = -a;
      }
      num = a;
      denom = b;
    }
    pll rep() {
      return {num, denom};
    };
    frac operator + (frac const & other) {
      return frac(num*other.denom + denom*other.num, denom*other.denom);
    }
    frac operator - (frac const & other) {
      return frac(num*other.denom - denom*other.num, denom*other.denom);
    }
    frac operator / (frac const & other) {
      return frac(num*other.denom, denom*other.num);
    }
};

typedef pair<frac, frac> pff;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pff> points;
  int zeroes = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 0) zeroes++;
    else {
      pff x = {frac(a*c, a*a+b*b), frac(b*c, a*a+b*b)};
      points.push_back(x);
    }
  }
  assert(zeroes <= 2);
  int m = points.size();
  ll ans = 0;

  for (int i = 0; i < m; i++) {
    map<pll, int> slopecounts;
    for (int j = i+1; j < m; j++) {
      pll slope = ((points[j].second-points[i].second)/(points[j].first-points[i].first)).rep();
      ans += slopecounts[slope];
      slopecounts[slope]++;
    }
  }

  if (zeroes == 2) ans += m;
  cout << ans << endl;
}