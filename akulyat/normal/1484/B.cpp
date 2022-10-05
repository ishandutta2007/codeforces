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

	set<int> dif;
	vector<int> all;
	for (int i = 1; i < n; i++) {
		dif.insert(v[i] - v[i - 1]);
		all.push_back(v[i] - v[i - 1]);
	}
	if (dif.size() <= 1) {
		cout << "0\n";
		return;
	}

	if (dif.size() >= 3) {
		cout << "-1\n";
		return;		
	}

	vector<int> pos, neg;
	for (auto i : dif)
		if (i > 0)
			pos.push_back(i);
		else
			if (i < 0)
				neg.push_back(i);
	if (pos.empty() || neg.empty()) {
		cout << "-1\n";
		return;				
	}

	int m = pos[0] - neg[0];
	int c = pos[0];

	for (auto i : v)
		if (i >= m) {
			cout << "-1\n";
			return;
		}

	cout << m << ' ' << c << '\n';
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