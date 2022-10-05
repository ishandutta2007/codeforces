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
vector<vector<ll>> all;
bool viv = false;

void mk1(int i, int j) {
	v[i] += v[j];
	all.push_back({1, i, j});
}

void mk2(int i, int j) {
	v[j] -= v[i];
	all.push_back({2, i, j});
}

void work(int i, int j) {
	mk1(i, j);
	mk2(i, j);
	mk1(i, j);
}

void print() {
	cout << all.size() << '\n';
	for (auto v : all) {
		cout << v[0] << ' ';
		cout << v[1] + 1 << ' ';
		cout << v[2] + 1 << '\n';
	}
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;	
	all.clear();
	auto was = v;
	for (auto &val : was)
		val = -val;
	for (int i = 1; i < n; i += 2) {
		work(i - 1, i);
		work(i - 1, i);
	}	
	if (viv) {
		cout << "see: ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}
	print();
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