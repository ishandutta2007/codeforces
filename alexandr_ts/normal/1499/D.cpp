#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 2e7 + 10;

vector<int> get_divs(int x) {
  vector<int> res;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i) continue;
    res.push_back(i);
    if (i != x / i) {
      res.push_back(x / i);
    }
  }
  return res;
}

int cnt_primes[N];
void prec() {
  for (int i = 2; i < N; ++i) {
    if (!cnt_primes[i]) {
      for (int j = i; j < N; j += i) {
        cnt_primes[j]++;
      }
    }
  }
}

int calc_good_pairs(int x) {
  return (1 << cnt_primes[x]);
  /*
  int ans = 0;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i) continue;
    if (__gcd(i, x / i) == 1) {
      if (i != x / i) {
        ans += 2;
      } else {
        ans += 1;
      }
    }    
  }
  return ans;
  */
}

void solve(ll c, ll d, ll x) {
  auto x_divs = get_divs(x);
  ll ans = 0;
  for (auto g: x_divs) {
    if ((x / g + d) % c) continue;
    ll val = (x / g + d) / c;
    ans += calc_good_pairs(val);
  }
  cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
  prec();
	int t = 1;
  cin >> t;
	while (t--) {
    ll c, d, x;
    cin >> c >> d >> x;
		solve(c, d, x);
	}
}