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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	v.clear();
	for (int i = 0; i < n; i++)
		if (s[i] == '*')
			v.push_back(i);

	vector<bool> need(v.size(), false);
	need.back() = need[0] = true;
	int last = v[0];
	for (int i = 0; i < v.size(); i++)
		if (v[i] - last > k) {
			need[i - 1] = true;
			last = v[i - 1];
		}
	int ans = 0;
	for (auto i : need)
		ans += i;
	cout << ans << '\n';

	// for (auto i : need)
	// 	cout << i << ' ';
	// cout << endl;
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