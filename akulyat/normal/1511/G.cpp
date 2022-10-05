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

const int K = 20;

ll n, m;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n >> m;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;	
	sort(v.begin(), v.end());	

	vector<vector<bool>> dp(K, vector<bool>(4 * ml, false));
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < K; j++) {
			int sh = 1 << (j + 1);
			dp[j][i] = dp[j][i + sh];
			int l = lower_bound(v.begin(), v.end(), i) - v.begin();
			int r = lower_bound(v.begin(), v.end(), i + (sh >> 1)) - v.begin();
			dp[j][i] = dp[j][i] ^ ((r - l) & 1);
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;

		int zero = true;
		for (int j = 0; j < K; j++) {
			int fr = 1 << (j);
			int st = l + fr;
			int sh = fr << 1;

			int fn = st + (r - l) / sh * sh;
			while (fn >= r)
				fn -= sh;
			while (fn < r)
				fn += sh;

			bool nice = (dp[j][st] == dp[j][fn]);

			if (st != fn) {
				int prev = fn - sh;
				int nxt = prev + fr;
				prev = r;
				prev = min(prev, nxt);

				int l = lower_bound(v.begin(), v.end(), prev) - v.begin();
				int r = lower_bound(v.begin(), v.end(), nxt) - v.begin();
				nice = (nice) ^ ((r - l) & 1);
			}

			zero = zero & nice;
		}

		if (zero) 
			cout << "B";
		else
			cout << "A";
	}

	cout << '\n';
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