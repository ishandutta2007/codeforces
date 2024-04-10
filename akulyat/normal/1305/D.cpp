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
vector<set<ll>> reb;
set<ll> lst;
bool viv = false;

void ans(ll v) {
	cout << "! " << v + 1 << endl;
	exit(0);
}

void who(ll a, ll b) {
	cout << "? " << a + 1 << ' ' << b + 1 << endl;
	ll v;
	cin >> v;
	v--;
	if (v == a || v == b)
		ans(v);
}

void check(ll v) {
	if (reb[v].size() <= 1)
		lst.insert(v);
}

void work() {
	ll a = *lst.begin();
	lst.erase(lst.begin());
	ll b = *lst.begin();
	lst.erase(lst.begin());

	ll sa = (*reb[a].begin());
	ll sb = (*reb[b].begin());

	who(a, b);
	reb[a].clear();
	reb[b].clear();
	reb[sa].erase(a);
	reb[sb].erase(b);
	check(sa);
	check(sb);
}

void solve() {
	cin >> n;
	reb.resize(n);
	for (ll i = 0; i < n - 1; i++) {
		ll a, b;
		cin >> a >> b;
		a--, b--;		
		reb[a].insert(b);
		reb[b].insert(a);
	}
	for (ll i = 0; i < n; i++)
		check(i);

	while (lst.size() > 1)
		work();
	ans(*lst.begin());
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