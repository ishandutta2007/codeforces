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

ll n, sum;
vector<int> v;
bool viv = false;

bool a(vector<int> v) {
	for (auto i : v)
		if (i & 1)
			return true;
	return false;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i, sum += i;

	vector<bool> dp(2000 * n + 1, false);
	dp[0] = true;
	for (auto val : v)
		for (int i = dp.size(); i >= val; i--)
			dp[i] = dp[i] | dp[i - val];

	if (sum & 1 || !dp[sum / 2]) {
		cout << 0 << '\n';
		return;
	}

	while (!a(v)) 
		for (auto &i : v) i >>= 1;

	int odd = 0;
	while (!(v[odd] & 1))
		odd++;
	cout << 1 << '\n';
	cout << odd + 1 << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}