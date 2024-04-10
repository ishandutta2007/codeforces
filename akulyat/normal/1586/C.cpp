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
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


bool viv = false;
int n, m;
vector<string> v;

bool p(int i, int j) {
	return v[i][j] == '.';
}

bool b(int i, int j) {
	return v[i][j] == 'X';
}

void solve() {
	cin >> n >> m;
	vector<bool> nice(m, false);
	v.resize(n);
	for (auto &s : v)
		cin >> s;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (b(i - 1, j) && b(i, j - 1))
				nice[j] = true;
		}
	}
	vector<int> sum(m + 1, 0);
	for (int i = 0; i < m; i++)
		sum[i + 1] = sum[i] + nice[i];
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		// l--;
		if (sum[r] - sum[l]) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	// cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}