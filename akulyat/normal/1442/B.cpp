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

ll n, k;
vector<ll> a, b;
bool viv = false;

struct lst {
	vector<int> l;
	vector<int> r;
	vector<int> val;

	lst(int sz) {
		l.resize(n, -1);
		r.resize(n, -1);
		val.resize(n, -1);
	}
};

void solve() {
	cin >> n >> k;
	a.resize(n);
	b.resize(k);
	for (auto &i : a)
		cin >> i, i--;
	for (auto &i : b)
		cin >> i, i--;

	vector<int> p(n);
	for (int i = 0; i < n; i++)
		p[a[i]] = i;
	for (auto &i : a)
		i = p[i];
	for (auto &i : b)
		i = p[i];

	vector<bool> used(n, false);
	for (auto i : b)
		used[i] = true;
	for (int i = 0; i < n; i++)
		if (!used[i])
			a[i] = n;

	lst l(n);
	for (int i = 0; i < n - 1; i++) {
		l.r[i] = i + 1;
		l.l[i + 1] = i;
	}
	for (auto i : b)
		l.val[i] = i;
	
	ll ans = 1;
	for (auto i : b) {
		int good = 0;
		if (l.l[i] != -1 && l.val[l.l[i]] == -1)
			good++;
		if (l.r[i] != -1 && l.val[l.r[i]] == -1)
			good++;
		if (!good) {
			cout << "0\n";
			return;
		}

		ans *= good;
		if (ans >= mod)
			ans -= mod;

		l.val[i] = -1;
		if (l.l[i] != -1)
			l.l[i] = l.l[l.l[i]];
		else {
			if (l.r[i] != -1)
				l.r[i] = l.r[l.r[i]];
		}
	} 

	cout << ans << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}