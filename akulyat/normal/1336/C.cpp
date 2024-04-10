#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

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
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 


ll n;
vector<ll> v;
vector<vector<ll>> gdp;
vector<ll> var;
bool viv = false;
string s, t;

ll prepare(string &s, string &t) {
	vector<vector<ll>> dp;
	dp.resize(s.size() + 1);
	for (auto &l : dp)
		l.resize(s.size() + 1);
	for (int i = 0; i < (ll)dp.size() - 1; i++) {
		dp[i + 1][i] = 1;
	}

	for (int i = 0; i < min(s.size(), t.size()); i++) {
		for (int l = 0; l < s.size(); l++) {
			int r = l + i;
			if (r < s.size()) {
				if (s[l] == t[i]) {		
					dp[l][r] += dp[l + 1][r];
					if (dp[l][r] >= mod)
						dp[l][r] -= mod;
				}
				if (s[r] == t[i]) {		
					if (r == 0) 
						dp[l][r] += 1;
					else
						dp[l][r] += dp[l][r - 1];
					if (dp[l][r] >= mod)
						dp[l][r] -= mod;
				}
			if (viv)
				cout << "dp " << l << ' ' << r << ' ' << dp[l][r] << endl;
			}
		}
		ll add = dp[s.size() - 1 - i][s.size() - 1];
		// if (t[i] == s[s.size() - 1 - i]) 
			// add -= dp[s.size() - i][s.size() - 1];
		var.push_back(add);
	}
	while (var.size() < s.size())
		var.push_back(0);
	if (viv) {
		for (auto i : var)
			cout << i << ' ';
		cout << endl;	
	}
}

void dd(string &s, string &t) {
	int l, n;
	l = t.size();
	n = s.size();
	vector<vector<ll>> dp;
	dp.resize(l + 1);
	for (auto &st : dp)
		st.resize(n + 1, 0);
	dp[0][0] = 1;

	for (int i = 0; i < l; i++) {
		dp[i + 1][0] = i + 2;
		for (int j = n - 1; j >= 0; j--) {
			dp[i + 1][j + 1] = dp[i][j + 1];
			if (t[i] == s[j]) {
				dp[i + 1][j + 1] += dp[i][j];
				if (dp[i + 1][j + 1] >= mod)
					dp[i + 1][j + 1] -= mod;
			if (viv)	
				cout  << "dddp " << i << ' ' << j << ' ' << dp[i + 1][j + 1] << '\n';
			}
		}
	}
	gdp = dp;
}

void solve() {
	cin >> t;
	cin >> s;

	ll l, n;
	l = t.size();
	n = s.size();

	prepare(s, t);
	reverse(t.begin(), t.end());
	dd(s, t);
	reverse(t.begin(), t.end());

	ll ans = 0;
	for (int i = 0; i < s.size(); i++) {
		ll v1 = var[i];
		ll v2 = 0;
		if (i + 1 == s.size())
			v2 = 1;
		if (viv)
			cout << (ll)t.size() - i - 2 << ' ' << s.size() - i - 1 << endl;

		if ((ll)t.size() - i - 2 >= 0 && s.size() - i - 1 >= 0)
			v2 += gdp[(ll)t.size() - i - 2][s.size() - i - 1];

		ll lans =  v1 * v2;


		lans %= mod;
		if (viv)
			cout << "cons " << i + 1 << ' ' << v1 << ' ' << v2 << endl;
		ans += lans;
		if (ans >= mod)
			ans -= mod;
	}

	if (viv)
		cout << ans << endl;

	ll st = 2;
	for (int i = 0; i < t.size(); i++) {
		ll lans = 0;
		if ((ll)t.size() - i - 1 >= 0) {
			if ((ll)t.size() - i - 1 >= 1) 
				lans = st * (gdp[t.size() - i - 1][s.size()] - gdp[t.size() - i - 2][s.size()]);
			else
				lans = st * gdp[t.size() - i - 1][s.size()];
		}
		lans %= mod;
                if (lans < 0)
                    lans += mod;
		if (viv)
			cout << "add " << lans << " by last " << t.size() - i - 1 << endl;
		ans += lans;
		if (ans >= mod)
			ans -= mod;

		st *= 2;
		st %= mod;
	}

	cout << ans << '\n';
}


int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
//	cin >> t;
	while (t--)
		solve();

	return 0;
}