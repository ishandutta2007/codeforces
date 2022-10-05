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
vector<ll> a, b;
bool viv = false;

vector<ll> all(vector<ll> a) {
	for (auto &i : a)
		if (i == -1)
			i = 1;
	return a;
}

vector<ll> noth(vector<ll> a) {
	for (auto &i : a)
		if (i == -1)
			i = 0;
	return a;
}

int solver(vector<ll> a, vector<ll> b) {
	int la = 0, ba = 5;
	int lb = 0, bb = 5;
	for (int i = 0; i < 10; i++) {
		int it = i / 2;
		if (i & 1) {
			if (b[it] == 0)
				bb--;
			else
				lb++;
		} else {
			if (a[it] == 0)
				ba--;
			else
				la++;
		}
		if (ba < lb)
			return i + 1;
		if (bb < la)
			return i + 1;
	}
	return 10;
}

void solve() {
	string s;
	cin >> s;
	a.assign(5, -1);
	b.assign(5, -1);
	for (int i = 0; i < 10; i++) {
		if (s[i] != '?') {
			if (i & 1)
				b[i / 2] = s[i] - '0';
			else
				a[i / 2] = s[i] - '0';
		}
	}
	vector<ll> fa, fb;
	fa = all(a);
	fb = noth(b);
	ll res1 = solver(fa, fb);
	fa = noth(a);
	fb = all(b);
	ll res2 = solver(fa, fb);
	cout << min(res1, res2) << '\n';
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