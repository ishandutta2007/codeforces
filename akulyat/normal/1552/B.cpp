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
vector<vector<int>> v;
bool viv = false;

bool cool(int a, int b) {
	int cnt = 0;
	for (int i = 0; i < 5; i++)
		cnt += v[a][i] < v[b][i];
	return cnt >= 3;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &l : v) {
		l.resize(5);
		for (auto &i : l) 
			cin >> i;
	}
	int bst = 0;
	for (int i = 1; i < n; i++)
		if (cool(i, bst))
			bst = i;
	int ans = bst;
	for (int i = 0; i < n; i++)
		if (i != bst) {
			if (cool(i, bst))
				ans = -2;
		}
	ans++;
	cout << ans << '\n';
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