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

ll n, k;
vector<ll> v;
bool viv = false;

void inv(vector<ll> &v) {
	ll ma = -mod;
	for (auto i : v)
		ma = max(i, ma);
	for (auto &i : v) 
		i = ma - i;
}

void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	ll cnt = 5;
	while (k > 0 && cnt > 0)
		inv(v), cnt--, k--;
	k &= 1;
	for (int i = 0; i < k; i++) 
		inv(v);	
	for (auto i : v)
		cout << i << ' ';
	cout << '\n';
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