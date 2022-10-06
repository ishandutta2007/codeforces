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


void solve() {
	string s;
	cin >> n;
	cin >> s;
	int c0, c1;
	c0 = c1 = 0;
	map<pii, int> cnt;
	for (int i = 0; i < n; i++) {
		c0 += (s[i] == 'K');
		c1 += (s[i] == 'D');
		int lc0 = c0, lc1 = c1;
		int g = __gcd(lc0, lc1);
		lc0 /= g;
		lc1 /= g;
		// cnt[{lc0, lc1}]++;
		cout << ++cnt[{lc0, lc1}] << ' ';
	}
	cout << '\n';
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