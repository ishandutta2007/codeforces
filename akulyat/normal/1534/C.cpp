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
vector<ll> a, b;
bool viv = false;


void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i, i--;
	b.resize(n);
	for (auto &i : b)
		cin >> i, i--;

	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			cout << "0\n";
			return;
		}
	}


	vector<ll> p(n);
	for (int i = 0; i < n; i++)
		p[a[i]] = b[i];
	vector<int> col(n, -1);
	ll c = 0;
	for (int i = 0; i < n; i++)
		if (col[i] == -1) {
			c++;
			int now = i;
			while (col[now] == -1)
				col[now] = 0, now = p[now];
		}
	ll ans = 1;
	while (c--)
		ans *= 2, ans %= mod;
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