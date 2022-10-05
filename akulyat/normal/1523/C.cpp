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

void print(vector<int> &now) {
	for (int i = 0; i < now.size(); i++) {
		cout << now[i];
		if (i + 1 == now.size())
			cout << '\n';
		else
			cout << '.';
	}
}

void work(vector<int> &now, int lvl) {
	if (lvl == n)
		return;
	int value = v[lvl];
	if (value == 1) {
	} else {
		while (now.size() && now.back() != value - 1)
			now.pop_back();		
		if (now.empty()) {
			cout << "BAD" << endl;;
			exit(1);
		}
		now.pop_back();
	}
	now.push_back(value);
	print(now);
	work(now, lvl + 1);
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	vector<int> now;
	work(now, 0);
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