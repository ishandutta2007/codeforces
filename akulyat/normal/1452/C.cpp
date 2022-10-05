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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v;
bool viv = false;
map<char, int> mp;

void solve() {
	mp['('] = 0;
	mp[')'] = 1;
	mp['['] = 2;
	mp[']'] = 3;
	string s;
	cin >> s;
	vector<ll> a;
	ll cnt00 = 0;
	ll cnt01 = 0;
	ll cnt10 = 0;
	ll cnt11 = 0;
	ll ans = 0;
	for (auto i : s) {
		cnt00 += (i == '(');
		cnt10 += (i == '[');
		if (i == ')') {
			if (cnt00)
				ans++, cnt00--;
		}
		if (i == ']') {
			if (cnt10)
				ans++, cnt10--;
		}
	}
	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}