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

ll n, k;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> k;
	if (2 * k > n - 1) {
		cout << "-1\n";
		return;
	}	
	v.resize(n);
	for (int i = 0; i < n; i++)
		v[i] = i + 1;
	for (int i = 0; i < k; i++)
		swap(v[n - 1 - 2 * i], v[n - 2 - 2 * i]);
	for (auto i : v)
		cout << i << ' ';
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