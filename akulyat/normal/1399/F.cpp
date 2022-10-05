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
const long long inf = ml * ml * ml + 7; 

ll n;
vector<pii> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &p : v)
		cin >> p.F >> p.S;

	set<ll> s;
	for (auto p : v) 
		s.insert(p.F),
		s.insert(p.S);

	vector<ll> p;
	for (auto i : s)
		p.push_back(i);

	map<ll, ll> mp;
	for (int i = 0; i < p.size(); i++)
		mp[p[i]] = i;

	for (auto &p : v)
		p.F = mp[p.F],
		p.S = mp[p.S];

	if (viv) {
		cout << "Seg: \n";
		for (auto p : v)
			cout << p.F << ' ' << p.S << '\n';
		cout << endl;
	}

	ll sz = p.size();
	vector<vector<int>> dp(sz + 1, vector<int>(sz + 1));
	vector<vector<int>> lr(sz + 1);
	for (auto p : v)
		lr[p.F].push_back(p.S);

	for (auto &line : lr)
		sort(line.begin(), line.end());

	int ans = 0;
	for (int len = 0; len < sz; len++) {
		for (int l = 0; l < sz - len; l++) {
			int r = l + len;
			if (l < r)
				dp[l][r] = dp[l + 1][r];
			for (auto rg : lr[l]) {
				if (rg < r) {
					if (viv)
						cout << "was " << dp[l][r] << ' ';
					if (viv)
						cout << "look [" << l << ", " << rg << "]" << endl;
					dp[l][r] = max(dp[l][r], dp[l][rg] + dp[rg + 1][r]);
					if (viv)
						cout << " now " << dp[l][r] << endl;
				}
				if (rg == r)  {
					if (viv)
						cout << "was " << dp[l][r] << ' ';
					if (viv)
						cout << "look [" << l << ", " << rg << "] ";
					dp[l][r]++;
					if (viv)
						cout << " now " << dp[l][r] << endl;
				}
			}
			ans = max(ans, dp[l][r]);
			if (viv)
				cout << "dp[" << l << "][" << r << "] = " << dp[l][r] << endl << endl;
		}
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