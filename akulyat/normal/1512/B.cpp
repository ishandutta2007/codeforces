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
vector<string> v;
bool viv = false;


void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	pll a, b;
	a = {-1, -1};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == '*')
				if (a.F == -1)
					a = {i, j};
				else
					b = {i, j};
		}
	}
	if (a.F == b.F) {
		a.F--;
		b.F--;
		if (a.F < 0)
			b.F += n, a.F += n;
	} else if (a.S == b.S) {
		a.S--;
		b.S--;
		if (a.S < 0)
			b.S += n, a.S += n;
	} else
		swap(a.F, b.F);
	v[a.F][a.S] = '*';
	v[b.F][b.S] = '*';
	for (auto i : v)
		cout << i << '\n';
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