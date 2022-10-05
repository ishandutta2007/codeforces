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

ll n, m, k, can;
vector<vector<ll>> v;
vector<vector<ll>> all;
bool viv = false;


void solver(vector<ll> v) {
	vector<vector<ll>> dp(can + 1, vector<ll>(k, -mod));
	dp[0][0] = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = can - 1; j >= 0; j--) {
			for (int was = 0; was < k; was++) {
				ll will = was + v[i];
				will %= k;
				dp[j + 1][will] = max(dp[j + 1][will], dp[j][was] + v[i]);
				// cout << j + 1 << ' ' << will << ' ' << dp[j][was] + v[i] << endl;
			}
		}
	}
	vector<ll> mx(k, -mod);
	for (int i = 0; i <= can; i++)
		for (int j = 0; j < k; j++)
			mx[j] = max(mx[j], dp[i][j]);
	all.push_back(mx);
}

void work(){
	vector<ll> can(k, -mod);
	can[0] = 0;
	for (auto &l : all) {
		// for (auto i : l)
		// 	cout << i << ' ';
		// cout << endl;
		vector<ll> fcan(k, -mod);
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++) {
				int u = i + j;
				if (u >= k)
					u -= k;
				fcan[u] = max(fcan[u], can[i] + l[j]);
			}
		can = fcan;
	}
	cout << can[0] << endl;
}

void solve() {
	cin >> n >> m >> k;
	can = m / 2;
	v.resize(n);
	for (auto &l : v) {
		l.resize(m);
		for (auto &i : l)
			cin >> i;
		sort(l.begin(), l.end());
	}
	for (auto &l : v)
		solver(l);
	work();
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