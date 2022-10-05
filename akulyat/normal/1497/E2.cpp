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

ll n, k;
vector<ll> v;
vector<int> go;
bool viv = false;

vector<ll> erat(int last) {
	vector<bool> prime(last + 1, true);
	vector<int> mn(last + 1, mod);
	// vector<ll> res;
	for (int i = 2; i <= last; i++) {
		if (prime[i]) {
			mn[i] = i;
			// res.push_back(i);
			if ((ll)i * i <= last)
				for (int j = i * i; j <= last; j += i) {
					mn[j] = min(mn[j], i);
					prime[j] = false;
				}
		}
	}
	go.resize(last + 1, 1);
	for (int i = 2; i < go.size(); i++) {
		if (go[i / mn[i]] % mn[i] == 0) {
			go[i] = go[i / mn[i]] / mn[i];
		} else
			go[i] = go[i / mn[i]] * mn[i];
	}
	// for (int i = 1; i < 20; i++)
	// 	cout << mn[i] << '\n';
	// for (int i = 1; i < 20; i++)
	// 	cout << go[i] << '\n';
	return {};
}

vector<ll> erat2(int last) {
	vector<bool> prime(last + 1, true);
	go.resize(last + 1, 1);
	for (int i = 2; i <= last; i++) 
		go[i] = i;
	for (int i = 2; i <= last; i++) {
		if (prime[i]) {
			if ((ll)i * i <= last)
				for (int j = i * i; j <= last; j += i * i) {
					prime[j] = false;
					while (go[j] / (i * i) * (i * i) == go[j])
						go[j] /= (i * i);
				}
		}
	}
	return {};
}


void prepare() {
	erat2(10 * ml + 10);
}

void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i = go[i];
	// cout << "v = ";
	// for (auto &i : v)
	// 	cout << i << ' ';
	// cout << endl;
	map<int, int> lst;
	int dp[n + 1][k + 1];
	int aim[n + 1][k + 1];
	for (int i = 0; i <= k; i++) 
		dp[0][i] = aim[0][i] = 0;
	for (int i = 0; i < n; i++) {
		int me = i + 1;

		int pr = 0;
		if (lst.count(v[i]))
			pr = lst[v[i]] + 1;

		for (int j = 0; j <= k; j++) 
			dp[me][j] = mod;
		for (int j = 0; j <= k; j++) {
			int a = aim[me - 1][j];
			a = max(a, pr);
			int b = mod;
			if (j)
				b = aim[me - 1][j - 1];
			aim[me][j] = min(a, b);
			// cout << "aim[" << me << "][" << j << "] = " << aim[me][j] << ' ' << a << ' ' << b << endl;
			for (int u = j; u <= k; u++) {
				dp[me][u] = min(dp[me][u], dp[aim[me][j]][u - j] + 1);
			}
		}
		lst[v[i]] = i;
	}
	cout << dp[n][k] << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	prepare();
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}