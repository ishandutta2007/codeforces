#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define In insert
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7, maxn = 1e6 + 100;
ll n, fac[maxn], dp[maxn], a[maxn];

ll powe(ll a, ll b){
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	ll ret = powe (a, b / 2);
	ret = (ret * ret) % mod;
	if (b % 2 == 1)
		ret = ret * a % mod;
	return ret % mod;
}

ll f(ll a, ll num){
	ll ret = fac[n];
	ll p = fac[num];
	ll q = fac[n - num];
	ll qp = (q * p) % mod;
	ret = ret * powe(qp, mod - 2);
	ret %= mod;
	ret = (ret * fac[num - 1]) % mod;
	ret = (ret * fac[n - num]) % mod;
	return (ret * a) % mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	ll cnt = 0;
	int nm = 1;
	for (int i = n - 2; i >= 0; i--){
		if (a[i] == a[i + 1])
			nm ++;
		else
			break;
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (fac[i - 1] * i) % mod;
	for (int i = 0; i < n; i++){
		if (i > 0 and a[i] == a[i - 1])
			cnt ++;
		else
			cnt = 0;
		dp[i] = n - i + cnt;
	}
	ll ans = 0;
	for (int i = 0; i < n; i++){
		if (dp[i] == 1)
			continue;
		if (a[i] == a[n - 1])
			continue;
		ans += f(a[i], dp[i]);
		ans %= mod;
	}
	cout << ans << endl;
}