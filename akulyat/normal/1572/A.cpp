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
vector<int> lvl;
vector<bool> used;

bool DFS(int g) {
	if (used[g])
		return false;
	used[g] = true;
	int mx = -1;
	for (auto gg : v[g]) {
		if (lvl[gg] == -1) {
			if (!DFS(gg))
				return false;
		}
		mx = max(mx, lvl[gg] - 1 + (gg > g));
	}
	lvl[g] = mx + 1;
	return true;
}

void solve() {
	cin >> n;
	v.assign(n, {});
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v[i].resize(k);
		for (auto &g : v[i])
			cin >> g, g--;
	}
	lvl.assign(n, -1);
	used.assign(n, false);
	for (int i = 0; i < n; i++)
		if (lvl[i] == -1) {
			if (!DFS(i)) {
				cout << "-1\n";
				return;
			}
		}
	int ans = 0;
	for (auto i : lvl)
		ans = max(ans, i + 1);
	cout << ans << '\n';
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