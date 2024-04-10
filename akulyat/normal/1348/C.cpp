#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

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
vector<ll> v;

bool same(vector<string> v) {
	for (int i = 1; i < v.size(); i++)
		if (v[i] != v[i - 1])
			return false;
	return true;
}

bool good(string s) {
	for (int i = 1; i < s.size(); i++)
		if (s[i] != s[i - 1])
			return true;
	return false;

}

void solve() {
	ll n, k;
	string s;	
	cin >> n >> k;
	cin >> s;
	sort(s.begin(), s.end());

	vector<string> v;
	v.resize(k);
	reverse(s.begin(), s.end());
	for (int i = 0; i < k; i++)
		v[i] += s.back(), s.pop_back();
	reverse(s.begin(), s.end());
	if (good(s) || !same(v))
		v[0] += s;
	else {
		for (int i = 0; i < s.size(); i++)
			v[i % k] += s[i]; 
	}


	auto ans = v[0];
	for (auto i : v)
		ans = max(ans, i);
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