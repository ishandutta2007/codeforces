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

ll n;
vector<ll> v;
bool viv = false;

bool bt(int a, int j) {
	return (a >> j) & 1;
}

int cnt(int a) {
	int res = 0;
	while (a)
		res += (a & 1), a >>= 1;
	return res;
}

int get(int a, int b) {
	if (a > b)
		return 0;
	if (cnt(b) > cnt(a))
		return 0;

	int ca = 0, cb = 0;
	for (int i = 0; i <= 29; i++) {
		ca += bt(a, i);
		cb += bt(b, i);
		if (cb > ca)
			return 0;
	}
	return 1;
}

int get2(int a, int b) {
	for (int i = 0; i < 30; i++) {
	// for (int i = 29; i >= 0; i--) {
		if (!bt(a, i) && bt(b, i))
			return 0;
		if (bt(a, i) && !bt(b, i)) {
			a += (1 << i);
		}
	}
	return (a == b);
}

void solver() {
	int k = 32;
	for (int j = 0; j < k; j++) {
		cout << j << ":\t";
		for (int i = 0; i < k; i++) {
			cout << get(j, i);
			if (!((i + 1) % 8))
				cout << ' ';
		}
		if (!((j + 1) % 8))
			cout << endl;
		cout << '\n';
	}
}

void solve() {
	int a, b;
	cin >> a >> b;
	if (get(a, b))
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// solver();
	cin >> t;
	while (t--)
		solve();

	return 0;
}