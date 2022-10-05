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
 
 
ll n, t;
vector<vector<ll>> m;
vector<ll> mi, ma, sum;
bool viv = false;

void solve() {
	cin >> n;
	ll ans = 0;
	sum.resize(ml + 10);
	ll kol = 0;
	for (ll i = 0; i < n; i++) {
		ll k;
		cin >> k;
		m.push_back({});
		for (ll j = 0; j < k; j++) {
			ll a;
			cin >> a;
			m.back().push_back(a);
		}
		bool bad = true;
		for (ll j = 1; j < k; j++)
			if (m[i][j] > m[i][j - 1])
				bad = false;
		if (bad) {
			mi.push_back(*min_element(m[i].begin(), m[i].end()));			
			ma.push_back(*max_element(m[i].begin(), m[i].end()));
			sum[mi.back()]++;
		} else
			kol++;
	}
	ans += kol * n + n * kol - kol * kol;
	for (ll i = 1; i < sum.size(); i++)
		sum[i] += sum[i-1];
	for (auto i : ma)
		if (i)
			ans += sum[i-1];
	cout << ans << endl;
}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    while (t--)
    	solve();


    return 0;
}