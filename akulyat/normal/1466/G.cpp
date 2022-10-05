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
const long long mod = kk * ml + 7;
const long long inf = ml * ml * ml + 7; 
const ll p = 239;
const ll p_2 = 123457;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
ll n, q;
vector<string> s;
string alp;
bool viv = false;
 
 
vector<vector<ll>> cnt;
vector<ll> pp, pp2, p2, hc;
void prepare() {
	cnt.resize(26, vector<ll>(alp.size() + 2, 0));
	for (int i = 0; i < alp.size(); i++) {
		for (int j = 0; j < 26; j++) {
			cnt[j][i + 2] = cnt[j][i + 1] * 2 + (alp[i] == char('a' + j));
			cnt[j][i + 2] %= mod;
		}
	}
	int mx_sz = 3 * ml;
	pp.push_back(1);
	for (int i = 0; i < mx_sz; i++) {
		pp.push_back(pp.back() * p);
		pp.back() %= mod;
	}
	pp2.push_back(1);
	for (int i = 0; i < mx_sz; i++) {
		pp2.push_back(pp2.back() * p_2);
		pp2.back() %= mod;
	}
	p2.push_back(1);
	for (int i = 0; i < mx_sz; i++) {
		p2.push_back(p2.back() * 2);
		p2.back() %= mod;
	}
	hc.resize(26);
	for (auto &i : hc)
		i = uniform_int_distribution<int>(0, mod - 1)(rng);
}
ll ccnt(char c, int l, int r) {
	if (viv)
		cout << "\tccnt(" << c << ' ' << l << ' ' << r << ")\n";
	r++;
	int cn = c - 'a';
 
	ll res = cnt[cn][r];
	ll dec = cnt[cn][l];
	dec *= p2[r - l];
	res -= dec;
 
	res %= mod;
	res += mod;
	res %= mod;
	if (viv)
		cout << "\t found " << res << '\n';
	return res;
}
 
struct H {
	string s;
	int n;
	vector<ll> h, h2;
 
	H() {}
	H(string s) {build(s);}
 
	void build(vector<ll> &h, int p) {
		h.resize(n + 1);
		for (int i = 0; i < n; i++) {
			h[i + 1] = h[i] * p;
			h[i + 1] += hc[s[i] - 'a'];
			h[i + 1] %= mod;
		}
	}
 
	void build(string _s) {
		s = _s;
		n = s.size();
		build(h, p);
		build(h2, p);
	}
 
	ll gh(vector<ll> &h, vector<ll> &pp, int l, int r) {
		ll res = h[r];
		ll dec = h[l];
		dec *= pp[r - l];
		res -= dec;
		res %= mod;
		res += mod;
		res %= mod;		
		return res;
	}
 
	pll gh(int l, int r) {
		pll res;
		res.F = gh(h, pp, l, r);
		res.S = gh(h2, pp, l, r);
		return res;
	}
 
	pll pref(int len) {
		return gh(0, len);
	}
	pll suf(int len) {
		return gh(n - len, n);
	}
};
 
void work() {
	int k;
	string p;
	cin >> k >> p;
	int big = 0;
	while (s[big].size() < p.size() && big < k)
		big++;
	if (s[big].size() < p.size()) {
		cout << "0\n";
		return;
	}
 
	H h_p(p);
	H h_big(s[big]);
 
	ll ans1 = 0;
	for (int i = p.size() - 1; i < s[big].size(); i++) {
		int r = i + 1;
		int l = r - p.size();
		if (h_p.gh(0, p.size()) == h_big.gh(l, r))
			ans1++;
	}
	if (viv) {
		if (viv)
			cout << "big = " << big << " s[big] = " << s[big] << endl;
		cout << "ans1 = " << ans1 << '\n';
	}
	ans1 *= p2[k - big];
	ans1 %= mod;
 
 
	ll ans2 = 0;
	for (int i = 0; i < p.size(); i++) {
		int pl = i;
		int sl = p.size() - i - 1;
		if (h_p.pref(pl) == h_big.suf(pl) && h_p.suf(sl) == h_big.pref(sl)) {
			if (viv)
				cout << "matched by " << i << endl;
			ans2 += ccnt(p[i], big + 1, k);
		}
	}
 
	ll ans = ans1 + ans2;
	ans %= mod;
	if (viv)
		cout << "\t\t\tANS = ";
	cout << ans << '\n';
	if (viv) {
		cout << "ans1, ans2 = " << ans1 << ' ' << ans2 << endl;
		cout << endl;
	}
}
 
void solve() {
	cin >> n >> q;
	s.resize(n + 1);
	cin >> s[0];
	cin >> alp;
	prepare();
	for (int i = 0; i < n; i++) {
		if (s[i].size() < ml && s[i].size())
			s[i + 1] = s[i] + alp[i] + s[i]; 		
	}
	if (viv) {
		for (int i = 0; i <= n; i++) 
			cout << "s[" << i << "] = " << s[i] << endl;
	}	
	while (q--)
		work();
}
 
int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();
 
	return 0;
}