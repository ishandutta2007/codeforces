#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

ll M, X;
vector <pii> f;
vector < vector <ll> > ords;

void load() {
	scanf("%lld%lld", &M, &X);
}

int vp(ll x, ll p) {
	int res = 0;
	for (; !(x % p); x /= p)
		res++;
	return res;
}

vector <pii> factor(ll x) {
	vector <pii> res;
	for (int i = 2; (ll)i * i <= x; i++) 
		if (!(x % i)) {
			int tmp = vp(x, i);
			res.push_back({i, tmp});
			while (tmp--)
				x /= i;
		}
	if (x > 1)
		res.push_back({x, 1});
	return res;
}

ll add(ll x, ll y, ll mod) {
	x += y;
	if (x >= mod)
		x -= mod;
	return x;
}

ll mul(ll x, ll y, ll mod) {
	ll res = 0;
	for (; y; y /= 2) {
		if (y % 2)
			res = add(res, x, mod);
		x = add(x, x, mod);
	}
	return res;
}

ll pot(ll x, ll y, ll mod) {
	ll res = 1;
	for (x %= mod; y; y /= 2) {
		if (y % 2)
			res = mul(res, x, mod);
		x = mul(x, x, mod);
	}
	return res;
}

ll order(ll prime) {
	vector <pii> tmp = factor(prime - 1);
	
	ll res = 1;
	for (auto it : tmp) {
		vector <ll> powers;
		ll curr = 1;
		for (int i = 0; i <= it.second; i++) {
			powers.push_back(curr);
			curr *= it.first;
		}
		int lo = 0, hi = it.second + 1;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (pot(X, (prime - 1) / powers[it.second - mid], prime) == 1)
				hi = mid;
			else
				lo = mid + 1;
		}
		res *= powers[lo];
	}
	
	return res;
}

vector <ll> get_ords(ll prime, int ex) {
	vector <ll> res;
	res.push_back(1);
	
	ll ord = order(prime), curr = 1;
	for (int i = 0; i < ex; i++)
		curr *= prime;
		
	int tmp = vp(curr - add(pot(X, ord, curr), curr - 1, curr), prime);
	
	if (prime > 2 || tmp > 1) {
		for (int i = 1; i <= min(tmp, ex); i++)
			res.push_back(ord);
		for (int i = min(tmp, ex) + 1; i <= ex; i++) {
			ord *= prime;
			res.push_back(ord);
		}
		return res;
	}
	
	tmp = vp(X + 1, 2) + 1;
	res.push_back(1);
	for (int i = 2; i <= min(tmp, ex); i++)
		res.push_back(2);
	ord = 2;
	for (int i = min(tmp, ex) + 1; i <= ex; i++) {
		ord *= 2;
		res.push_back(ord);
	}
	
	return res;
}

ll gen_divs(int pos, ll phi, ll lcm) {
	if (pos == f.size())
		return phi / lcm;
	ll res = 0, curr = 1;
	for (int i = 0; i <= f[pos].second; i++) {
		res += gen_divs(pos + 1, phi * curr, ords[pos][i] / __gcd(lcm, ords[pos][i]) * lcm);
		if (!i)
			curr = f[pos].first - 1;
		if (i)
			curr *= f[pos].first;
	}
	return res;
}

ll solve() {
	if (X == 1)
		return M;
		
	f = factor(M);
		
	for (auto it : f)
		ords.push_back(get_ords(it.first, it.second));
	
	return gen_divs(0, 1, 1);
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}