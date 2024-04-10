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
	n += 2;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	sort(v.begin(), v.end());

	ll sum = 0;
	for (int i = 0; i < n - 2; i++)
		sum += v[i];
	if (v[n - 2] == sum || v[n - 1] == sum) {
		v.pop_back();
		v.pop_back();
		for (auto i : v)
			cout << i << ' ';
		cout << '\n';
		return;
	}

	ll rsum = v.back();
	for (int i = n - 3; i >= 0; i--) {
		sum += v[i + 1];
		sum -= v[i];
		if (sum == rsum) {
			v.pop_back();
			for (int j = 0; j < v.size(); j++)
				if (j != i)
					cout << v[j] << ' ';
			cout << '\n';
			return;
		}
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