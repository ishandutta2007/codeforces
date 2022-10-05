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

ll n, W;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> W;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	for (int i = 0; i < n; i++) {
		if (v[i] >= (W + 1) / 2 && v[i] <= W) {
			cout << 1 << '\n';
			cout << i + 1 << '\n';
			return;
		}
	}		
	vector<int> num;
	ll have = 0;
	for (int i = 0; i < n; i++) {
		if (have + v[i] <= W) {
			num.push_back(i);
			have += v[i];
		}
	}
	if (have * 2 >= W) {
		cout << num.size() << '\n';
		for (auto i : num)
			cout << i + 1 << ' ';
		cout << '\n';
		return;
	}
	cout << "-1\n";
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