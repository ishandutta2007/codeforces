#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long     ll;
typedef long double   ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n;
bool viv = false;


void solve() {
	ll n, k;
	string s;
	cin >> n >> k >> s;

	ll on = 0;
	for (auto i : s)
		on += (i == '1');

	ll ans = inf;
	for (int i = 0; i < k; i++) {
		ll cnt = 0, mon = 0;
		vector<ll> v;
		for (int j = i; j < n; j += k) {
			cnt++;
			mon += (s[j] == '1');
			v.push_back(s[j] == '1');
		}
		ll add = 0;		
		if (mon != 0) {
			ll llans = cnt - mon;
			vector<ll> pr, sf;
			pr.push_back(0);
			for (auto i : v)  {
				if (!i)
					pr.push_back(pr.back() - 1);
				else
					pr.push_back(pr.back() + 1);
			}
			reverse(v.begin(), v.end());
			sf.push_back(0);
			for (auto i : v)  {
				if (!i)
					sf.push_back(sf.back() - 1);
				else
					sf.push_back(sf.back() + 1);
			}
			reverse(v.begin(), v.end());
			reverse(sf.begin(), sf.end());

			ll mn = mod;
			for (int i = 0; i < sf.size(); i++) {
				if (i >= 0)
					mn = min(mn, pr[i - 0]);
				llans = min(llans, cnt - mon + mn + sf[i]);
			}
			// for (auto i : pr)
			// 	cout << i << ' ';
			// cout << endl;
			// for (auto i : sf)
			// 	cout << i << ' ';
			// cout << endl;
			add = llans;
		}
		add = min(add, mon);
		ll lans = (on - mon) + add;
		ans = min(ans, lans);
	}
	cout << ans << '\n';


}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}