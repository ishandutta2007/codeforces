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


ll n, l, r;
bool viv = false;
vector<ll> v;

void solve() {
	cin >> n >> l >> r;
	l--, r--;

	vector<pll> v;	
	for (int i = 0; i < n; i++) {
		v.push_back({i, 2 * (n - 1 - i)});
	}	
	ll sl = 0;
	vector<ll> ans;
	for (int i = 0; i < n; i++) {
		ll sr = sl + v[i].S - 1;
		if (max(l, sl) <= min(r, sr)) {
			vector<ll> loc;
			for (int j = 0; j < v[i].S / 2; j++) {
				loc.push_back(i);
				loc.push_back(i + j + 1);
			}
			for (int j = 0; j < loc.size(); j++)
				if (sl + j >= l && sl + j <= r)
					ans.push_back(loc[j]);
		}
		sl = sr + 1;		
	}

	if (r == sl)
		ans.push_back(0);

	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}