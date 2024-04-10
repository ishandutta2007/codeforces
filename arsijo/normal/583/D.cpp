#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define x first
#define y second
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef double ld;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
const ld E = 1e-6;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
const ll MAX = 5000 + 1;
#else
const ll MAX = 2e5 + 1;
#endif

#ifdef LOCAL
//#define DEBUG
#endif

int dp[100][100], size;

int pre_solve(int *ar, int n, int v) {
	int dp[n];
	ms(dp);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ar[i] <= v) {
			dp[i] = 1;
			for (int j = i - 1; j >= 0; j--)
				if (ar[j] <= ar[i])
					dp[i] = max(dp[i], dp[j] + 1);
			ans = max(ans, dp[i]);
		}
	}
	return ans;
}

int suff_solve(int *ar, int n, int v) {
	int dp[n];
	ms(dp);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ar[i] >= v) {
			//cout << "ar[" << i << "] >= " << v << endl;
			dp[i] = 1;
			for (int j = i - 1; j >= 0; j--)
				if (ar[j] <= ar[i])
					dp[i] = max(dp[i], dp[j] + 1);
			ans = max(ans, dp[i]);
		}
	}
	return ans;
}

int solve(int *ar, int n, int v1, int v2) {
	int dp[n];
	ms(dp);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v1 <= ar[i] && ar[i] <= v2) {
			dp[i] = 1;
			for (int j = i - 1; j >= 0; j--)
				if (ar[j] <= ar[i])
					dp[i] = max(dp[i], dp[j] + 1);
			ans = max(ans, dp[i]);
		}
	}
	return ans;
}

int solve(int *ar, int n, int v) {
	int dp[n];
	ms(dp);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--)
			if (ar[j] <= ar[i])
				dp[i] = max(dp[i], dp[j] + 1);
		ans = max(ans, dp[i]);
	}
	return ans;
}

ll solve_(int *ar, int n, int t) {
	ll dp1[size], dp2[size];
	ms(dp1);
	vector<ll> v;
	for (int i = 0; i < min(100, t); i++) {
		for (int j = 0; j < size; j++) {
			dp2[j] = 0;
			for (int z = 0; z <= j; z++)
				dp2[j] = max(dp2[j], dp1[z] + dp[z][j]);
			//cout << dp2[j] << endl;
		}
		for (int i = 0; i < size; i++)
			dp1[i] = dp2[i];
		ll ans = 0;
		for (int i = 0; i < size; i++)
			ans = max(ans, dp1[i]);
		v.push_back(ans);
		//cout << ans << endl;
	}
	ll ans = v.back();
	//cout << ans << endl;
	if (t > 100) {
		ans += (ll) (t - 100) * (v[v.size() - 1] - v[v.size() - 2]);
	}
	return ans;
}

int main() {

	sync;
#ifdef LOCAL
	input;
#else

#endif

	int n, t;
	cin >> n >> t;

	int ar[n], a[301];
	ms(a);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		a[ar[i]]++;
	}

	int res = -1;
	vector<int> r;

	set<int> s;

	for (int i = 1; i <= 300; i++) {
		if (a[i])
			s.insert(i);
		if (a[i] >= res) {
			if (a[i] > res) {
				r.clear();
				res = a[i];
			}
			if (res == a[i])
				r.push_back(i);
		}
	}

	size = (int) s.size();
	vector<int> v;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		v.push_back(*it);

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			dp[i][j] = solve(ar, n, v[i], v[j]);
			//cout << "dp " << i << " " << j << " " << dp[i][j] << endl;
		}
	}

	if (t == 1) {
		cout << solve(ar, n, 1);
	} else {
		cout << (ll) solve_(ar, n, t);
	}

}