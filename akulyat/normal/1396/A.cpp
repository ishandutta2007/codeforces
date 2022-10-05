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
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	if (n == 1) {
		for (int j = 0; j < 3; j++) {
			cout << 1 << ' ' << 1 << '\n' << -v[0] << '\n';
			v[0] = 0;
		}
		exit(0);
	}


	cout << 1 << ' ' << n - 1 << '\n';
	for (int i = 0; i < n - 1; i++) {
		ll need = (v[i] / n) * n;
		ll dif = v[i] - need;
		ll add = dif * (n - 1);
		cout << add << ' ';
		v[i] += add;
	}
	cout << '\n';
	cout << 2 << ' ' << n << '\n';
	for (int i = 1; i < n; i++) {
		ll need = (v[i] / n) * n;
		ll dif = v[i] - need;
		ll add = dif * (n - 1);
		cout << add << ' ';
		v[i] += add;
	}
	cout << '\n';
	cout << 1 << ' ' << n << '\n';
	for (int i = 0; i < n; i++) {
		cout << -v[i] << ' ';
	}
	cout << '\n';
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