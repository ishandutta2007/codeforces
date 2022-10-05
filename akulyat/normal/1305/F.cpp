#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
using namespace std;

 /*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// */


#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 


ll n;
vector<ll> m, p, rm;
vector<vector<ll>> v;
bool viv = false;

vector<long long> erat(long long last) {
	vector<bool> bad;
	vector<long long> r;
	for (long long i = 0; i < last + 10; i++)
	    bad.push_back(true);
	for (long long i = 2; i <= last; i++)
	    if (bad[i])
	        {
	        long long j = 2;
	        while (j * i <= last)
	            {
	            bad[j * i] = false;
	            j++;
	            }
	        r.push_back(i);
	        }
	return r;
	}

ll ran() {
	ll res = 0;
	for (ll i = 0; i < 8; i++) {
		ll a = rand() % kk;
		ll b = rand() % kk;
		res *= a;
		res += b;
		res %= mod;
	}
	return res;
}

void solve() {
	cin >> n;
	m.resize(n);
	for (auto &i : m)
		cin >> i;
	rm = m;
	for (ll i = 0; i < n; i++) {
		if (m[i] > 1)
			m.push_back(m[i] - 1);
		m.push_back(m[i] + 1);
	}
	n = m.size();
	p = erat(2 * ml);

	vector<ll> cool;
	ll con = 169;
	for (ll i = 0; i < con; i++) {
		cool.push_back(m[ran() % m.size()]);
	}
	for (ll i = 0; i < min(10ll, (ll)m.size()); i++) {
		cool.push_back(m[i]);
	}

	for (auto vv : cool) {
		v.push_back({});
		ll val = vv;
		for (auto d : p) {
			if (!(val % d)) {
				v.back().push_back(d);
				while (!(val % d))
					val /= d;
			}
		}
		if (val != 1)
			v.back().push_back(val);		
	}

	unordered_map<ll, int> cnt;
//	gp_hash_table<ll, int> cnt;
	for (auto vv : v) 
		for (auto val : vv) 
			cnt[val]++; 


	vector<ll> check;
	check.push_back(2);
	check.push_back(3);
	check.push_back(5);

	ll cc = 1;
	for (auto p : cnt) {
		if (viv)
			cout << p.F << ' ' << p.S << endl;
		if (p.S >= cc) 
			check.push_back(p.F);
	}

	ll ans = n;
	for (auto val : check) {
		ll lans = 0;
		for (int i = 0; i < rm.size(); i++) {
			ll ost = rm[i] % val;
			if (rm[i] < val)
				lans += val - rm[i];
			else
				lans += min(ost, val - ost);
		}
		if (viv)
			cout << "with " << val << ' ' << lans << endl;
		ans = min(ans, lans);
	}
	cout << ans << endl;
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