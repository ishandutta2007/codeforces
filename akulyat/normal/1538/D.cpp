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

ll a, b, k;
vector<ll> v;
bool viv = false;
vector<ll> p;

vector<ll> erat(int last) {
	vector<bool> prime(last + 1, true);
	vector<ll> res;
	for (int i = 2; i <= last; i++) {
		if (prime[i])
			res.push_back(i);
		if ((ll)i * i <= last)
			for (int j = i * i; j <= last; j += i)
				prime[j] = false;
	}
	return res;
}


void prepare() {
	p = erat(40 * kk);
	// cout << p.size() << endl;
}

void solve() {
	cin >> a >> b >> k;
	if (k == 0) {
		if (a == b)
			cout << "YES\n";
		else
			cout << "NO\n";
		return;
	}
	if (k == 1) {
		if (((a % b == 0) || (b % a == 0)) && a != b)
			cout << "YES\n";
		else
			cout << "NO\n";
		return;
	}
	int ca = 0, cb = 0;
	for (auto d : p) {
		while (a % d == 0)
			ca++, a /= d;
	}
	for (auto d : p) {
		while (b % d == 0)
			cb++, b /= d;
	}
	if (a - 1)
		ca++;
	if (b - 1)
		cb++;
	if (ca + cb >= k)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	prepare();
	while (t--)
		solve();

	return 0;
}