#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

const int N = 5005;
const int MOD = 1e9 + 7;
 
struct polynomial {
  int deg;
  ll coeff[N];
  
  polynomial () {
    deg = 0;
    memset(coeff, 0, sizeof coeff);
  }
};

ll bigMod (ll a, int e) {
  ll r = 1; 
  while (e) {
    if (e & 1) r = (r * a) % MOD;
    a = (a * a) % MOD, e >>= 1;
  }
  return r;
}

polynomial product (polynomial f, polynomial g) {
  polynomial h;
  h.deg = f.deg + g.deg;

  for (int i = 0; i <= f.deg; ++i) {
    for (int j = 0; j <= g.deg; ++j) {
      h.coeff[i + j] += f.coeff[i] * g.coeff[j];
      h.coeff[i + j] %= MOD;
    }
  }
  
  return h;
}

int n, k;
ll a[N], prod, ext;
polynomial f, g;

int main() {
	scanf("%d %d", &n, &k);

	f.deg = 0, f.coeff[0] = 1;
	g.deg = 1, g.coeff[1] = -1;
	prod = ext = 1;
	
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a + i);
		prod *= a[i], prod %= MOD;
		g.coeff[0] = a[i];
		f = product(f, g);
	}
	
	ll offset = 0, inv = bigMod(n, MOD - 2);
	for (int i = 0; i <= min(n, k); ++i) {
		offset += f.coeff[i] * ext;
		offset %= MOD;
		ext *= inv, ext %= MOD;
		ext *= (k - i), ext %= MOD;
	}
	
	ll ans = prod - offset;
	ans %= MOD, ans += MOD, ans %= MOD;
	printf("%lld\n", ans);
	
	return 0;
}