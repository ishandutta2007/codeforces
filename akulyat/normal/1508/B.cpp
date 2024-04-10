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
	k--;
	if (viv)
		cout << "see: " << k << '\n';
	v.resize(n - 1);
	for (int i = 0; i < v.size(); i++) {
		v[i] = k & 1;
		k >>= 1;
	}
	if (k) {
		cout << "-1\n";
		return;
	}
	reverse(v.begin(), v.end());

	if (viv) {
		cout << "\t";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}

	vector<ll> seg;
	seg.push_back(0);
	for (int i = 0; i < n - 1; i++)
		if (!v[i])
			seg.push_back(i + 1);
	seg.push_back(n);

	vector<ll> ans;
	for (int j = 1; j < seg.size(); j++) {
		int l = seg[j - 1];
		int r = seg[j];
		vector<ll> sub;
		for (int i = l; i < r; i++)
			sub.push_back(i);
		reverse(sub.begin(), sub.end());
		for (auto i : sub)
			ans.push_back(i);
	}

	for (auto &i : ans)
		i++;
	for (auto &i : ans)
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