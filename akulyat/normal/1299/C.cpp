#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
 
using namespace std;
 
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
vector<ll> m;
vector<ld> v;
bool viv = false;
vector<pair<ld, ll>> p;

bool bad() {
	if (p.size() < 2)
		return false;
	if (p[p.size() - 1].F < p[p.size() - 2].F)
		return true;
	return false;
}

bool comp() {
	ld val = 0;
	val = p[p.size() - 1].F * p[p.size() - 1].S + p[p.size() - 2].F * p[p.size() - 2].S;
	ll cnt = (p[p.size() - 1].S + p[p.size() - 2].S);
	val /= cnt;
	p.pop_back();
	p.pop_back();
	p.push_back({val, cnt});
}

void solve() {
	cin >> n;
	m.resize(n);
	for (auto &i : m)
		cin >> i, v.push_back(i);	
	for (ll i = 0; i < n; i++) {
		p.push_back({v[i], 1});
		while (bad())
			comp();
	}
	cout.precision(20);
	for (auto pr : p) {
		for (ll i = 0; i < pr.S; i++)
			cout << fixed << pr.F << '\n';
	}
}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}