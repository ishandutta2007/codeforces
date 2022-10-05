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
int n, x;
vector<int> v;

bool nice(vector<int> &v, int l, int r) {
	if (l < 0 || r >= v.size() || l == r)
		return true;
	int sum = 0;
	for (int i = l; i <= r; i++) {
		// if (!used[i])
		// 	return true;
		sum += v[i];
	}
	if (sum >= x * (r - l + 1))
		return true;
	return false;
}
// bool can(vector<int> &v, vector<bool> &used, int pl) {
// 	used[pl] = true;
// 	for (int i = pl - 3; i <= pl; i++) {
// 		for (int j = pl; j <= pl + 3; j++) {
// 			if (!nice(v, used, i, j)) {
// 				used[pl] = false;
// 				return false;
// 			}
// 		}
// 	}
// 	used[pl] = false;
// 	return true;
// }

bool nice(vector<int> vec) {
	if (viv)
		cout << "nice()" << endl;
	int n = vec.size();
	for (int i = 0; i < n; i++) 
		for (int j = i; j < n; j++)
			if (!nice(vec, i, j))
				return false;
	if (viv)
		cout << "/nice()" << endl;
	return true;
}

void solve2() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	cin >> x;

	int U = 5;
	vector<vector<int>> dp(n, vector<int>(U, 0));
	vector<int> best(n, 0);
	for (int i = 0; i < n; i++) {
		if (i)
			best[i] = dp[i][0] = best[i - 1];

		vector<int> vec;
		vec.push_back(v[i]);
		for (int mask = 1; mask < U; mask++) {
			if (nice(vec)) {
				if (i == 0)
					dp[i][mask] = 0 + 1;
				else {
					dp[i][mask] = dp[i - 1][mask - 1] + 1;
					if (mask == U - 1 && i)
						dp[i][mask] = best[i - 1] + 1;
				}
				if (viv)
					cout << "\tdp[" << i << "][" << mask << "] = " << dp[i][mask] << endl;
				best[i] = max(best[i], dp[i][mask]);
			} else {
				break;
			}
			if (i - mask >= 0)
				vec.push_back(v[i - mask]);
			else
				break;
		}
	}
	if (viv) {
		cout << "best = ";
		for (auto i : best)
			cout << i << ' ';
		cout << endl;
	}
	cout << best.back() << '\n';
}

// void solve() {
// 	cin >> n;
// 	v.resize(n);
// 	for (auto &i : v)
// 		cin >> i;
// 	cin >> x;

// 	vector<int> ord(n);
// 	iota(ord.begin(), ord.end(), 0);

// 	sort(ord.begin(), ord.end(), [&](int a, int b){
// 		return v[a] > v[b];
// 	});

// 	vector<bool> used(n, false);
// 	int ans = 0;
// 	for (int i = 0; i < n; i++) {
// 		int pl = ord[i];
// 		if (can(v, used, pl)) {
// 			used[pl] = false;
// 			ans++;
// 		} else {
// 			cout << ans << '\n';
// 			if (viv) {
// 				cout << "\tused = ";
// 				for (auto i : used)
// 					cout << i;
// 				cout << endl;
// 				cout << "\tfailed at " << i << endl;
// 			}
// 			return;
// 		}
// 	}
// 	cout << ans << '\n';
// }

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve2();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}