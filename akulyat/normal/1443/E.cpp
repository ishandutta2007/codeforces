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

int n, sz, q;
ll now;
vector<int> p;
vector<ll> f;
bool viv = false;


void get_p(ll now);

void prepare() {
	sz = min(n, 15);
	f.push_back(1);
	for (int i = 1; i < sz + 2; i++)
		f.push_back(f.back() * i);
	now = 0;		
	get_p(now);
}

void get_p(ll now) {
	if (viv)
		cout << "get_p(" << now << ")" << endl;
	set<int> left;
	p.clear();
	p.resize(sz);
	for (int i = 0; i < sz; i++)
		left.insert(i);
	for (int i = 0; i < sz; i++) {
		ll can = f[sz - 1 - i];
		ll need = now / can;
		now -= can * need;
		auto z = left.begin();
		while (need--)
			z++;
		p[i] = *z;
		left.erase(z);
	}
	if (viv) {
		cout << "see: ";
		for (auto i : p)
			cout << i << ' ';
		cout << endl;
	}
}

void nxt() {
	ll add;
	cin >> add;
	now += add;
	get_p(now);
}

ll sum(ll l, ll r) {
	r = min(r, (ll)n - sz - 1);
	if (r < l)
		return 0;
	return (l + r) * (r - l + 1) / 2;
}

ll seg(ll l, ll r) {
	if (viv)  {
		cout << "count on " << l << ' ' << r;
	}
	l = max(0ll, l);
	ll res = 0;
	for (int i = l; i <= r; i++)
		res += p[i] + (n - sz);
	if (viv) {
		cout << " see " << res << endl;
	}
	return res;
}

void count() {
	int l, r;
	cin >> l >> r;
	l--, r--;


	ll ans = (r - l + 1);
	ans += sum(l, r);
	l -= (n - sz);
	r -= (n - sz);
	ans += seg(l, r);
	cout << ans << '\n';
}

void work() {
	int tp;
	cin >> tp;
	tp--;
	if (tp)
		nxt();
	else
		count();
}

void solve() {
	cin >> n >> q; 
	prepare();
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