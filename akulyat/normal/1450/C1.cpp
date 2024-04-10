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
vector<string> v;
bool viv = false;

ll d(vector<string> a, vector<string> b) {
	ll res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != b[i][j])
				res++;
	return res;
}

void print(vector<string> v) {
	for (auto i : v)
		cout << i << '\n';
}

void solve() {
	cin >> n;
	v.clear();
	v.resize(n);
	k = 0;
	for (auto &s : v) {
		cin >> s;	
		for (auto i : s)
			k += (i != '.');
	}
	auto v0 = v;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((i + j) % 3 == 0 && (v0[i][j] == 'X'))
				v0[i][j] = 'O';
	auto v1 = v;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((i + j) % 3 == 1 && (v0[i][j] == 'X'))
				v1[i][j] = 'O';
	auto v2 = v;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if ((i + j) % 3 == 2 && (v0[i][j] == 'X'))
				v2[i][j] = 'O';
	if (d(v0, v) * 3 <= k)
		return void(print(v0));
	if (d(v1, v) * 3 <= k)
		return void(print(v1));
	if (d(v2, v) * 3 <= k)
		return void(print(v2));
	assert(false);
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