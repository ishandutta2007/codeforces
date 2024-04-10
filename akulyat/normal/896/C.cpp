#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
using namespace std;
 
#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 
typedef set<pair<pll, ll>> sex; 
 
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
 
ll n, m, seed, vmax, x, y;
vector<ll> v;
sex seg;
bool viv = false;
 
ll rnd() {
	ll ret = seed;
	seed = (seed * 7 + 13) % 1000000007;
	return ret;
}
 
long long obr(long long v, ll st, long long mod) {
    v %= mod;
    if (v < 0)
        v += mod;
    vector<long long> bin;
    long long l = 0;
    while(st > 0) {
        bin.push_back(st & 1);
        st /= 2;
        l++;
    }

    vector<long long> sq;
    sq.push_back(v);
    for (int i = 1; i < l; i++) {
        long long s = sq.back();
        s *= s;
        s %= mod;
        sq.push_back(s);
    }

    long long ans = 1;
    for (int i = 0; i < l; i++)
        if (bin[i]) {
            ans *= sq[i];
            ans %= mod;
        }
    return ans;
}
 
void show() {
	cout << "Now it looks like:\n";
	for (auto i : seg)
		cout << "On " << i.F.F << ' ' << i.F.S << " we have " << i.S << endl;
	cout << "______________________ That's all ______________________" << endl;  
}
 
void build() {
	for (ll i = 0; i < n; i++)
		seg.insert({{i, i}, v[i]});
}
 
sex mine(ll l, ll r) {
	auto lb = seg.lower_bound({{l + 1, -1}, -1});
	auto rb = seg.lower_bound({{r + 1, -1}, -1});
	auto lb2 = rb;
	sex res;
	if (lb == rb) {
		lb--;
		ll l1 = (*lb).F.F;
		ll r2 = (*lb).F.S;
		ll l2 = l;
		ll r1 = r;
		ll val = (*lb).S;
 
		seg.erase(lb);
		res.insert({{l2, r1}, val});
		if (l1 <= l2 - 1)
			seg.insert({{l1, l2 - 1}, val});
		if (r1 + 1 <= r2)
			seg.insert({{r1 + 1, r2}, val});		
		return res;
	}
 
	lb--;
	while (lb != rb) {
		auto it = *lb;
		res.insert(it);
		lb++;
	}
	for (auto i : res)
		seg.erase(i);
	sex stay, back, er;
	for (auto i : res) {
		if (i.F.F < l) {
			er.insert(i);
			stay.insert({{l, i.F.S}, i.S});
			back.insert({{i.F.F, l - 1}, i.S});
		}
		if (r < i.F.S) {
			er.insert(i);
			stay.insert({{i.F.F, r}, i.S});
			back.insert({{r + 1, i.F.S}, i.S});
		}
	}
	for (auto i : er)
		res.erase(i);
	for (auto i : stay)
		res.insert(i);
	for (auto i : back)
		seg.insert(i);
	return res;
}
 
void turn_back(sex &work) {
	for (auto p : work)
		seg.insert(p);	
}
 
void add(ll l, ll r, ll x) {
	auto work = mine(l, r);
	sex work_new;
	for (auto i : work)
		work_new.insert({i.F, i.S + x});
	for (auto i : work_new)
		seg.insert(i);
}
 
void make(ll l, ll r, ll x) {
	auto work = mine(l, r);
	seg.insert({{l, r}, x});	
}
 
ll k_stat(ll l, ll r, ll k) {
	auto work = mine(l, r);
	multiset<pll> who;
	for (auto i : work)
	who.insert({i.S, i.F.S - i.F.F + 1});
 
	vector<pll> who_vec;
	for (auto i : who)
		who_vec.push_back(i);
	reverse(who_vec.begin(), who_vec.end());
	while (k >= who_vec.back().S && who_vec.size())
		k -= who_vec.back().S, who_vec.pop_back();
	if (who_vec.empty()) {
		cout << "Palundra, k_stat doesn't work" << endl;
		for (auto i : who)
			cout << i.F << ' ' << i.S << "; ";
		cout << endl;
		exit(0);
	}
	turn_back(work);
	return who_vec.back().F;
}
 
ll sum_pows(ll l, ll r, ll x, ll y) {
	auto work = mine(l, r);
	ll res = 0;
	for (auto p : work) {
		res += (p.F.S - p.F.F + 1) * obr(p.S, x, y);
		res %= y;
	}
	turn_back(work);
	return res;
}
 
void solve() {
	cin >> n >> m >> seed >> vmax;
	v.resize(n);
	for (auto &i : v)
		i = (rnd() % vmax) + 1;
	build();
 
 
	while (m--) {
		ll op = (rnd() % 4) + 1;
		ll l = (rnd() % n);
		ll r = (rnd() % n);
 
		if (l > r) 
			swap(l, r);
 
		if (op == 3)
			x = (rnd() % (r - l + 1)) + 1;
		else
			x = (rnd() % vmax) + 1;
 
		if (op == 4)
			y = (rnd() % vmax) + 1;
 
		if (op == 1)  {
			if (viv)
				cout << "!!! Add " << x << " on " << l << ' ' << r << endl;
			add(l, r, x);
		}
		if (op == 2)  {
			if (viv)
				cout << "!!! Make " << x << " on " << l << ' ' << r << endl;
			make(l, r, x);
		}
		if (op == 3) {
			if (viv)
				cout << "Answer for quary of type 3 (on " << l << ' ' << r << "): ";
			cout << k_stat(l, r, x - 1) << '\n';
			if (viv)
				cout << endl;
		}
		if (op == 4) {
			if (viv)
				cout << "Answer for quary of type 4 (on " << l << ' ' << r << "): ";
			cout << sum_pows(l, r, x, y) << '\n';
			if (viv)
				cout << endl;
		}
		if (op < 1 || op > 4) {
			cout << "Peace of shit " << endl;
		}
		if (viv)	
			show();
	}
}
 
 
int main() {
//	viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();
 
 
    return 0;
}