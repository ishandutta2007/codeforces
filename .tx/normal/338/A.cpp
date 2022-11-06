#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

typedef long long int ll;

typedef vector<int> vei;
typedef vector<ll> vell;

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d\n", a)
#define prisp(a) printf("%d ", a)

#define foi(n) for (int i = 0; i < n; ++i)
#define foj(n) for (int j = 0; j < n; ++j)

#define pb push_back

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()

#define openfiles(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)

// File names!!!

const int mod = ((int) 1e9) + 9;

ll pow2(ll x) {
	if (x == 1) return 2;
	if (x % 2 == 0) {
		ll res = pow2(x / 2) % mod;
		return res * res % mod;
	}
	return 2 * pow2(x - 1) % mod;
}

int main() {
	// openfiles("test");
	ll n, m, k;
	cin >> n >> m >> k;
	ll x = (n - m + 1) * (k - 1);
	ll ans = 0;
	if (x >= m) {
		ans = m;
	} else {
		ll posl = m - x + k - 1;
		// cerr << posl << endl;
		int t = posl / k;
		ans = pow2(t + 1);
		ans = (ans - 2 + mod) % mod;
		ans = (ans * k) % mod;
		ans += m - t * k;
	}
	cout << ans % mod;

	puts("");
    return 0;
}//xwokfu