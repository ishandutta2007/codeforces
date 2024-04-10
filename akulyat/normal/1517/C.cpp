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

bool emp(int x, int y) {
	if (x < 0 || y < 0)
		return false;
	if (x >= n || y >= n)
		return false;
	return v[x][y] == 0;
}

void solve() {
	cin >> n;
	vector<int> p(n, 0);
	for (auto &i : p)
		cin >> i;
	v.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		int val = p[i];
		int pl = val;
		int x = i, y = i;
		while (val--) {
			if (!emp(x, y)) {
				cout << "BAD\n";
				exit(1);
			}
			v[x][y] = pl;
			if (viv)
				cout << "put " << pl << ": " << x << ' ' << y << endl;
			if (emp(x, y - 1)) {
				y--;
			} else
				x++;
		}		
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++)
			cout << v[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}