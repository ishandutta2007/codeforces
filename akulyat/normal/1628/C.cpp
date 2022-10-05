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
int n;
vector<vector<int>> v;

void change() {
	vector<vector<int>> v2 = v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v[i][j] = v2[n - 1 - j][i];
		}
	}
}

ll work() {
	ll ans = 0;
	for (int sum = 0; sum <= 2 * n; sum += 4) {
		bool need = true;
		for (int i = 0; i < n; i++) {
			int j = sum - i;
			if (0 <= j && j < n) {
				if (need) {
					// cout << "use " << i << ' ' << j << endl;
					ans ^= v[i][j];
				}
				need ^= true;
			}
		}
	}
	return ans;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &l : v) {
		l.resize(n);
		for (auto &i : l)
			cin >> i;
	}	
	ll res = 0;
	res ^= work();
	change();
	res ^= work();
	cout << res << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}