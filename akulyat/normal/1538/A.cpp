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
vector<pll> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &p : v)
		cin >> p.F;
	for (int i = 0; i < n; i++)
		v[i].S = i;
	sort(v.begin(), v.end());
	int a = v[0].S;
	int b = v[n - 1].S;
	if (a > b)
		swap(a, b);
	ll ans1 = b + 1;
	ll ans2 = n - a;
	ll ans = a + 1 + n - b;
	ans = min(ans, ans1);
	ans = min(ans, ans2);
	cout << ans << endl;
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