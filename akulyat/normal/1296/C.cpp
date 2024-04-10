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
 
ll n, m, k;
vector<ll> v;
bool viv = false;

ll has(ll x, ll y) {
	return x * ml + y;
}

void add(vector<pair<ll, pll>> &ans, map<ll, ll> &las, ll h, ll ind) {
	ans.push_back({ind - las[h], {las[h], ind}});
}

void solve() {
	ll n;
	string s;
	cin >> n;
	cin >> s;
	ll x = 0, y = 0;
	vector<pair<ll, pll>> ans;
	map<ll, ll> las;
	las[0] = -1;
	for (ll i = 0; i < n; i++) {
		if (s[i] == 'L')
			x--;
		if (s[i] == 'R')
			x++;
		if (s[i] == 'D')
			y--;
		if (s[i] == 'U')
			y++;
		if (las.count(has(x, y))) {
			add(ans, las, has(x, y), i);
		}
		las[has(x, y)] = i;
	}
	sort(ans.begin(), ans.end());
	if (ans.size()) {
		cout << ans[0].S.F + 2 << ' ' << ans[0].S.S + 1 << '\n';
	} else
		cout << "-1\n";
}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();


    return 0;
}