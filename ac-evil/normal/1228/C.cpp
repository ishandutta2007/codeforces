#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long
#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= b; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)

namespace io {
    inline ll read() {
        ll w = 0, f = 1; char c;
        while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
        while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
        return w * f;
    }
}

using io::read;

const int MOD = 1000000007;

vector<int> prime;

bool check(int x) {
	rep(i, 2, sqrt(x))
		if (!(x % i)) return 0;
	return 1;
}

void prework() {
	rep(i, 2, 40000)
		if (check(i)) prime.push_back(i);
}

vector<int> pri;

ll n, x;

ll pow(ll a, ll b) {
	ll res = 1;
	for (register int k = a; b; k = (ll)k*k%MOD, b >>= 1)
		if (b & 1) res = res*k%MOD;
	return res;
}

int main() {
	prework();
	x = read(), n = read();
	for (register int pt = 0; pt < prime.size(); pt++) {
		if (!(x % prime[pt])) pri.push_back(prime[pt]);
		while (!(x % prime[pt])) x /= prime[pt];
	}
	if (x != 1) pri.push_back(x);

	int ans = 1;

	rep(i, 0, pri.size()-1) {
		ll x = 1;
		ll cnt = 0, sgm = 0;
		while (x <= n/pri[i]) x *= pri[i];
		while (x > 1) {
			cnt = n / x - sgm;
			sgm += cnt;
			ans = (ll)ans*pow(x%MOD, cnt)%MOD;
			x /= pri[i];
		}
	}

	printf("%d\n", ans);
	
    return 0;
}