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
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	map<ll, ll> cnt, have;

	vector<ll> val = {2, 4, 6, 8};

	for (auto i : v) {
		cnt[i]++;
		for (auto v : val)
			if (cnt[i] == v)
				have[v]++;
	}


	ll q;
	cin >> q;
	while (q--) {
		string s;
		ll add;
		cin >> s >> add;
		if (s[0] == '+') {
			cnt[add]++;
			for (auto v : val)
				if (cnt[add] == v)
					have[v]++;
		}
		if (s[0] == '-') {
			for (auto v : val)
				if (cnt[add] == v)
					have[v]--;
			cnt[add]--;
		}
		bool can = false;
		if (have[8])
			can = true;
		if (have[6] && have[2] >= 2)
			can = true;
		if (have[4] >= 2)
			can = true;
		if (have[4] && have[2] >= 3)
			can = true;

		if (can)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}