#include <bits/stdc++.h>
 
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
const long long mod = ml * kk + 7;;
const long long inf = ml * ml * ml + 7;
 
 
ll n;
vector<pll> m;
vector<ll> m1;
vector<vector<ll>> v;
map<ll, vector<ll>> all;
bool viv = false;

bool bad() {
	vector<ll> a(4, 0);
	for (auto i : m)
		a[(i.F & 1) * 2 + (i.S & 1)]++;
	// for (auto i : a)
	// 	cout << i << ' ';
	// cout << endl;
	ll res = 0;
	for (auto i : a)
		res += (i == 0);
	return res == 3;
}

void change() {
	for (auto &i : m) {
		if (i.F & 1)
			i.F++;
		if (i.S & 1)
			i.S++;
		i.F /= 2;
		i.S /= 2;
	}
}

void solve() {
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a += ml;
		b += ml;
		m.push_back({a, b});
	}

	while (bad())
		change();

	vector<vector<ll>> a(4);
	ll cnt = 0;
	for (auto i : m) {
		cnt++;
		a[(i.F & 1) * 2 + (i.S & 1)].push_back(cnt);
	}

	ll v1 = 0, v2 = 3;
	if ((a[0].size() == 0 && a[3].size() == 0) || (a[1].size() == 0 && a[2].size() == 0)) 
		v2 = 1;

		

	vector<ll> ans;
	for (auto i : a[v1])
		ans.push_back(i);
	for (auto i : a[v2])
		ans.push_back(i);


	cout << ans.size() << endl;
	for (auto i : ans)
		cout << i << ' ';


}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
    	solve();


    return 0;
}