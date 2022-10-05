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

int n, q;
int pre = 0;
bool viv = false;

void bad_end() {
	exit(0);
}

int ask(int l, int r) {
	r = min(r, n);
	cout << "? " << l << ' ' << r - 1 << endl;
	ll res = 0;
	cin >> res;
	if (viv)
		cout << "get " << res << '\n';
	if (res == -1)
		bad_end();
	return (r - l) - res;
}

int get() {
	int k;
	cin >> k;
	return k;
}

bool bad(int l, int r) {
	return ask(l, r) == 0;
}

void work() {
	int l = pre;
	int sh = 1;
	while (bad(l, l + sh))
		sh <<= 1;
}

void solve() {
	cin >> n >> q;
	int l = 0;
	int r = n;
	int k = get();
	if (viv)
		cout << "work " << k << endl;
	while (l + 1 != r) {
		int m = l + r >> 1;
		if (ask(1, m + 1) < k)
			l = m;
		else
			r = m;
	}
	cout << "! " << r << endl;
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