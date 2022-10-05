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

ll n;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	vector<ll> v(n);
	vector<ll> p(n);
	for (auto &i : v)
		cin >> i;
	for (auto &i : p)
		cin >> i;

	vector<ll> vec;
	for (int i = 0; i < n; i++)
		if (!p[i])
			vec.push_back(v[i]);
	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
		if (!p[i])
			v[i] = vec.back(), vec.pop_back();
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