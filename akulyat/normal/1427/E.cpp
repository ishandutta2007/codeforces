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
const long long inf = ml * ml * ml * (kk / 1000) - 10; 
const long long MX = kk * 49; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, val;
ll cnt;
vector<ll> v;
vector<pair<int, pll>> ans;
bool viv = false;

void sh() {
	cout << ans.size() << '\n';
	for (auto p : ans) {
		if (p.F == 0)
			cout << p.S.F << " + " << p.S.S << '\n';
		if (p.F == 1)
			cout << p.S.F << " ^ " << p.S.S << '\n';
	}
	exit(0);
}

void s(ll a, ll b) {
	if ((a + b) > inf)
		return;
	// cout << a << " + " << b << endl;
	ans.push_back({0, {a, b}});
	v.push_back(a + b);
	cnt++;
}

void x(ll a, ll b) {
	if ((a ^ b) > inf)
		return;
	ans.push_back({1, {a,  b}});
	// cout << a << " ^ " << b << endl;
	v.push_back(a ^ b);
	if (v.back() == 1)
		sh();
	cnt++;
}

void sums() {
	for (int i = 0; i < 22; i++) {
		s(v.back(), v.back());		
	}
	v.push_back(v[0]);
	for (int i = 0; i < 10; i++) {
		s(v[0], v.back());		
	}
}

void ls() {
	set<ll> st;
	for (auto i : v)
		st.insert(i);
	v.clear();
	for (auto i : st)
		v.push_back(i);
}

void add(bool tp) {
	if (viv)
		cout << "add " << tp << endl;
	ll n = v.size();
	if (cnt > MX)
		return;
	// random_shuffle(v.begin(), v.end());
	if (viv)
		cout << "add " << tp << endl;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (!tp)
				s(v[i], v[j]);
			if (tp)
				x(v[i], v[j]);
			if (cnt > MX)
				return;
		}
	}
	ls();
}

void worker() {
	ls();
	n = v.size();
	for (int i = 1; i < n; i++)	{
		// cout << (v[i] ^ v[i - 1]) << ' ';
		if ((v[i] ^ v[i - 1]) == 2) {
			x(v[i], v[i - 1]);
			if (viv)
				cout << "Cool" << endl;
			i = n;
		}
	}
	if (viv)
		cout << endl;
	pll bst = {0, 0};
	ll res = mod * mod;
	for (int i = 1; i < n; i++)	{
		for (int j = max(0, i - 50); j < i; j++)
			if ((v[i] ^ v[j]) & 1)
				if ((v[i] ^ v[j]) < res) {
					res = (v[i] ^ v[j]);
					bst = {v[i], v[j]};
				}
	}
	if (viv)
		cout << "res = " << res << endl;
	vector<ll> have;
	have.push_back(0);
	while (have.back() < res) {
		have.push_back(2 + have.back());
	}
	for (auto i : have) {
		if ((i ^ res) == 1) {
			x(i, res);
			sh();
			exit(0);
		}
	}
	assert(false);
	exit(0);
}

bool is_2(ll v) {
	return (v != 0) && ((v & (v - 1)) == 0);
}

int mm(ll v) {
	ll c = 0;
	while (v)
		c++, v >>= 1;
	return c;
}

void pl(ll a, ll b) {
	if (a == 0 || b == 0)
		return;
	while (b != 0) {
		if (a < b)
			swap(a, b);
		ll ob = b;
		while (mm(b) < mm(a)) {
			s(b, b);
			b *= 2;
		}
		// cout << a << ' ' << ob << ' ' << b << endl;
		x(a, b);
		a = a ^ b;
		b = ob; 
		if (a < b)
			swap(a, b);
	}
	if (viv)
		cout << "see " << a << endl;
}

void ss() {
	vector<ll> vv;
	ls();
	random_shuffle(v.begin(), v.end());
	for (int i = 0; i < min((ll)v.size(), (ll)30); i++) {
		vv.push_back(v[i]);
	}
	ls();
	if (viv)
		cout << vv.size() << endl;
	for (int i = 0; i < vv.size(); i++)
		for (int j = 0; j < i; j++)
			pl(vv[i], vv[j]);
}

void bb() {
	vector<ll> st;
	for (auto i : v)
		if (!(i & (i - 1)) && (i != 0))
			st.push_back(i);
	sort(st.begin(), st.end());
	assert(st.size());
	ll s2 = st[0];

	ll odd = 0;
	vector<ll> o;
	for (auto i : v)
		if (i & 1)
			o.push_back(i);
	odd = o[0];

	ll step = s2;
	while (step < mod) {
		if ((odd & step)) {
			x(odd, step);
			odd ^= step;
		}
		s(step, step);
		step *= 2;
	}
	if (odd == 1)
		sh();
	if (viv)
		cout << "left " << odd << endl;  

	while (!is_2(odd)) {
		while (odd < s2) {
			s(odd, odd);
			odd *= 2;
		}
		x(odd, s2);
		odd ^= s2;
	}
	if (viv)
		cout << odd << " created";
	bb();
}

void check() {
	ls();
	n = v.size();
	for (int i = 1; i < n; i++) {
		if (!((v[i] ^ v[i - 1]) & 1))
			if (viv)
				cout << (v[i] ^ v[i - 1]) << ' ';
	}
	for (int i = 1; i < n; i++) {
		// cout << v[i] << ' ';
		// cout << v[i] - v[i - 1] << ' ';
		if (((v[i] ^ v[i - 1]) & 1))
			cout << v[i] - v[i - 1] << ' ';
		if ((v[i] ^ v[i - 1]) == 1) {
			x(v[i], v[i - 1]);
			sh();
			exit(0);
		}
		if (v[i] == 1 || v[i - 1] == 1) {
			sh();
			exit(0);
		}
	}
	bb();
	assert(false);
}

void small() {
	ls();
	vector<ll> a;
	vector<ll> b;
	for (auto i : v)
		if (i & 1)
			a.push_back(i);
		else
			b.push_back(i);
	while (a.size() > 20)
		a.pop_back();
	while (b.size() > 20)
		b.pop_back();
	for (auto i : a)
		v.push_back(i);
	for (auto i : b)
		v.push_back(i);
}

void show() {
	if (!viv)
		return;
	cout << "SHOW(" << v.size() << "): ";
	for (auto i : v)
		if (!(i & (i - 1)) && (i != 0))
		cout << i << ' ';
	cout << endl;
}

void stp() {
	set<ll> st;
	for (auto i : v)
		st.insert(i);
	ll n = v.size(); 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 42; j++) {
			ll want = v[i] ^ (1ll << j);
			if (st.find(want) != st.end()) {
				x(v[i], want);
				return;
			}
		}
	}
}

void solve() {
	cin >> val;
	v.push_back(val);
	sums();
	for (int i = 0; i < 5; i++) {
		add(false);
		// small();
		show();
		add(true);
		// small();
	}
	show();
	stp();
	ss();
	bb();
	// worker();
	// check();
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