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

int n;
vector<int> a, b;
bool viv = false;

int cnt(vector<int> v) {
	sort(v.rbegin(), v.rend());
	int k = v.size() - v.size() / 4;
	int res = 0;
	for (int i = 0; i < k; i++)
		res += v[i];
	if (viv) {
		cout << "see: ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
		cout << "\tANS = " << res << endl;
	}
	return res;
}

bool can(int add) {
	auto fa = a, fb = b;
	for (int i = 0; i < add; i++) {
		fa.push_back(100);
		fb.push_back(0);
	}
	if (cnt(fa) >= cnt(fb))
		return true;
	return false;
}

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	b.resize(n);
	for (auto &i : b)
		cin >> i;
	int l = -1;
	int r = n + 1;
	while (l + 1 < r) {
		int m = l + r >> 1;
		if (can(m))
			r = m;
		else
			l = m;
	}
	cout << r << '\n';
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