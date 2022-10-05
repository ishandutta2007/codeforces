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
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 


ll n, k;
bool viv = false;
vector<ll> v;
string s;

void solve() {
	cin >> n >> k;
	cin >> s;
	vector<vector<ll>> cnt;
	cnt.resize(k);
	for (auto &l : cnt)
		l.resize(26);

	for (int i = 0; i < n; i++) {
		int j = k - (i % k) - 1;
		j = min((ll)j, i % k);
		cnt[j][s[i] - 'a']++;
	}

	ll ans = 0;
	for (int i = 0; i < k; i++) {
		ll mx = 0;
		ll sum = 0;
		for (auto v : cnt[i])
			sum += v, mx = max(mx, v);
		sum -= mx;
		ans += sum;
	}

	cout << ans << '\n';
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