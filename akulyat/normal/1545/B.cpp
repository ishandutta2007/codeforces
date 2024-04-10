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

ll n, z;
vector<ll> f, fi;
string s;
bool viv = false;

ll bpow(ll val, ll mod, ll st = -1) {
	if (st == -1)
		st = mod - 2;
	if (st == 0)
		return 1;
	ll res = bpow(val, mod, st >> 1);
	res = res * res, res %= mod;
	if (st & 1)
		res *= val, res %= mod;
	return res;
}

ll inv(ll val) {
	return bpow(val, mod);
}

void prepare() {
	f.push_back(1);
	int l = ml / 2;
	for (int i = 1; i < l; i++)
		f.push_back(f.back() * i), f.back() %= mod;
	for (auto i : f)
		fi.push_back(inv(i));
}


ll C(int n, int k) {
	if (n < 0 || k < 0 || k > n)
		return 0;
	ll res = f[n];
	res %= mod;
	res *= fi[k];
	res %= mod;
	res *= fi[n - k];
	res %= mod;
	return res;
}

vector<int> get(string s) {
	int n = s.size();
	int ones = 0;
	vector<int> res;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1')
			ones++;
		else {
			if (ones & 1)
				ones--;
			res.push_back(i - ones);
		}
	}
	return res;
}

void solve() {
	cin >> n;
	cin >> s;
	z = 0;
	for (auto i : s)
		z += (i == '0');

	auto pl1 = get(s);
	reverse(s.begin(), s.end());
	auto pl2 = get(s);
	reverse(s.begin(), s.end());

	int k = pl1.size();
	for (int i = 0; i < k; i++) {
		pl2[i] = n - 1 - pl2[i];
	}
	reverse(pl2.begin(), pl2.end());

	if (viv) {
		cout << "\t\t";
		for (auto i : pl1)
			cout << i << ' ';
		cout << endl;
		cout << "\t\t";
		for (auto i : pl2)
			cout << i << ' ';
		cout << endl;
		for (int i = 0; i < k; i++) {
			if (pl2[i] - pl1[i] != pl2[0] - pl1[0]) {
				cout << "BAD" << endl;
				exit(1);
			}
		}
	}

	int sh = 0;
	if (pl1.size())
		sh = pl2[0] - pl1[0];

	if (viv) {
		if (sh & 1) {
			cout << "ODD" << endl;
			exit(1);
		}
	}

	sh /= 2;
	if (sh < 0)
		sh = -sh;

	ll ans = C(z + sh, z);
	cout << ans << '\n';
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