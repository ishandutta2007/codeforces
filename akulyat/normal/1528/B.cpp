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
const long long mod = 998244353;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n;
vector<ll> v;
bool viv = false;


ll mn[2 * ml];
ll cnt[2 * ml];

vector<ll> erat(int last) {
	vector<bool> prime(last + 1, true);
	vector<ll> res;
	for (int i = 2; i <= last; i++) 
		mn[i] = mod;
	for (int i = 2; i <= last; i++) {
		if (prime[i]) {
			res.push_back(i);
			mn[i] = i;
		}
		if ((ll)i * i <= last)
			for (int j = i * i; j <= last; j += i) {
				prime[j] = false;
				mn[j] = min(mn[j], (ll)i);
			}
	}
	return res;
}


void prepare() {
	auto p = erat(ml + kk);
	cnt[0] = cnt[1] = 1;
	for (int i = 2; i < ml + 100; i++) {
		ll dv = mn[i];
		int c = 0;	
		ll val = i;	
		while (val % dv == 0)
			val /= dv, c++;
		if (!c) {
			cout << i << ' ' << dv << endl;
			exit(0);
		}
		cnt[i] = cnt[val] * (c + 1);
	}
	// for (int i = 1; i < 30; i++)
	// 	cout << i << ' ' << cnt[i] << endl;
}

void solve() {
	cin >> n;
	vector<ll> dp(n + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	ll sum = 2;
	for (int i = 2; i <= n; i++) {
		dp[i] = sum + (cnt[i] - 1);
		dp[i] += mod;
		dp[i] %= mod;
		sum += dp[i];
		sum %= mod;
	}
	cout << dp.back() << '\n';
}

int main() {
	prepare();
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}