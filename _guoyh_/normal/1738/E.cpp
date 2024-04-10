# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 200051;
const int P = 998244353;
ll pwr(ll x, ll y){
	x %= P;
	y= (y % (P - 1) + (P - 1)) % (P - 1);
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}
ll fac[MAXN], ifac[MAXN];
ll C(int u, int v){
	if (v < 0 || v > u) return 0;
	else return fac[u] * ifac[v] % P * ifac[u - v] % P;
}
int T, n;
ll a[MAXN];
ll s[MAXN];
ll wrk(int lft, int rgt){
	int pl = lft, pr = rgt;
	while (pl <= rgt && a[pl] == 0) pl++;
	while (pr >= lft && a[pr] == 0) pr--;
	if (pl > rgt) return (lft == 1 && rgt == n) ? pwr(2, rgt - lft) : pwr(2, rgt - lft + 2);
	ll d = (lft == 1 && rgt == n) ? C(pl - 1 + n - pr, pl - 1) : C(pl - lft + 1 + rgt - pr + 1, pl - lft + 1);
	for (; pl < pr; pl++){
		while (pl < pr && s[rgt] - s[pr - 1] < s[pl] - s[lft - 1]) pr--;
		if (s[rgt] - s[pr - 1] == s[pl] - s[lft - 1]) return wrk(pl + 1, pr - 1) * d % P;
	}
	return d;
}
int main(){
	ios::sync_with_stdio(false);
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < MAXN; i++){
		fac[i] = fac[i - 1] * i % P;
		ifac[i] = pwr(fac[i], -1);
	}
	cin >> T;
	while (T--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
		}
		int pl = 1, pr = n;
		while (pl <= n && a[pl] == 0) pl++;
		while (pr >= 1 && a[pr] == 0) pr--;
		cout << wrk(1, n) << '\n';
	}
	return 0;
}