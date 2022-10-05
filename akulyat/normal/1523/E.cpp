#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, k;
vector<ll> f, fi;
bool viv = false;

void norm(ll &val) {
	val %= mod;
	val += mod;
	val %= mod;
}

ll bpow(ll val, ll mod, ll st = -1) {
	if (st == -1)
		st = mod - 2;
	if (st == 0)
		return 1;
	ll res = bpow(val, mod, st >> 1);
	res = res * res, res %= mod;
	if (st & 1)
		res *= val, res %= mod;
	return res;
}

ll inv(ll val) {
	if (val == 0)
		return 1;
	return bpow(val, mod);
}

void prepare() {
	f.push_back(1);
	for (int i = 1; i < 2 * ml; i++)
		f.push_back(f.back() * i), norm(f.back());
	for (auto val : f)
		fi.push_back(inv(val));
}

ll C(ll n, ll k) {
	if (n < 0 || k < 0 || n < k)
		return 0;
	ll res = 1;
	res *= f[n], norm(res);
		// res *= fi[k], norm(res);
	res *= fi[n - k], norm(res);
	return res;
}

ll count(ll n, ll p) {
	return C(n + (1 - p) * (k - 1), p);
}



void solve() {
	cin >> n >> k;
	ll ans = 1;
	ll vars = 1;
	ll prob = 1;
	for (int i = 1; i <= n; i++) {
		ll exp = vars * (n + 1 - i);
				norm(exp);		
		ll nxt = count(n, i);
		ll p_cont = prob * nxt;
				norm(p_cont);
		if (p_cont != 0)
			p_cont *= inv(exp);
				norm(p_cont);
		ll p_stop = prob - p_cont;
				norm(p_stop);

		ll add = p_stop * (i - 1);
				norm(add);
		if (viv) {
			cout << "\tadd = " << add << endl;
			cout << "\tvars = " << vars << endl;
			cout << "\texp = " << exp << endl;
			cout << "\tnxt = " << nxt << endl;
			cout << "\tp_cont = " << p_cont << endl;
			cout << "\tp_stop = " << p_stop << endl;
			cout << endl;
		}
		ans += add;
				norm(ans);

		vars = nxt;
		prob = p_cont;
	}
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	prepare();
	while (t--)
		solve();

	return 0;
}