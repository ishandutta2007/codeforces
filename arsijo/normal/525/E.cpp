#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define MAX 100000
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define ld long double
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n, k;
ll s;

ll fac[20] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800,
		479001600, 6227020800, 87178291200, 1307674368000, 20922789888000,
		355687428096000, 6402373705728000, 121645100408832000 };

ll ar[25];
ll ans = 0;
map<int, int> dp[30];

ll factorial(int n) {
	ll ans = 1;
	for (int i = 2; i <= n; i++)
		ans *= i;
	return ans;
}

void make(ll pos, ll val, ll used) {
	if (val > s || val < 0 || used > k)
		return;
	if (pos == n) {
		dp[used][val]++;
		return;
	}
	if (ar[pos] <= 18)
		make(pos + 1, val + fac[ar[pos]], used + 1);
	make(pos + 1, val, used);
	make(pos + 1, val + ar[pos], used);
}

void make2(ll pos, ll val, ll used) {
	if(val > s || val < 0 || used > k)
		return;
	if(pos == n){
		for(int i = 0; i <= k - used; i++)
			ans += dp[i][s - val];
		return;
	}
	if(ar[pos] <= 18)
		make2(pos + 1, val + fac[ar[pos]], used + 1);
	make2(pos + 1, val, used);
	make2(pos + 1, val + ar[pos], used);
}

int main() {

	ll m;

	cin >> n >> k >> s;

	for (int i = 0; i < n; i++)
		cin >> ar[i];

	m = n;
	n = (n / 2) + (n % 2);

	make(0, 0, 0);

	swap(n, m);

	make2(m, 0, 0);

	cout << ans;

}