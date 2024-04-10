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

const int SZ = 20 * ml + kk;

ll n;
vector<ll> v, counter;
bool viv = false;

vector<ll> erat(int last) {
	vector<bool> prime(last + 1, true);
	vector<ll> res;
	vector<int> mini(SZ, 1);
	for (int i = 1; i < SZ; i++)
		mini[i] = i;
	for (int i = 2; i <= last; i++) {
		if (prime[i]) {
			res.push_back(i);
			for (ll j = i * i; j < max(mini.size(), prime.size()); j += i) {
				if (j < mini.size()) {
					mini[j] = min(mini[j], i);
				}
				if (j < prime.size())
					prime[j] = false;
			}
		}
	}
	counter.resize(SZ, 1);
	counter[1] = 1;
	for (int i = 2; i < counter.size(); i++) {
		int prev = i / mini[i];
		counter[i] = counter[prev];
		if (prev % mini[i])
			counter[i] *= 2;
	}
	return res;
}

vector<ll> p;

void prepare() {
	p = erat(10 * kk);
}

vector<int> div(ll x) {
	vector<int> res;
	res.push_back(1);
	for (auto d : p) {
		int cnt = 0;
		while (!(x % d)) {
			cnt++;
			x /= d;
		}
		int sz = res.size();
		for (int j = 0; j < cnt; j++) {
			for (int i = 0; i < sz; i++) {
				res.push_back(d * res[j * sz + i]);
			}
		}
	}
	if (x - 1) {
		int sz = res.size();
		for (int i = 0; i < sz; i++) {
			res.push_back(x * res[i]);
		}
	}

	return res;
}

void solve() {
	ll c, d, x;	
	cin >> c >> d >> x;

	auto dd = div(x);
	ll ans = 0;

	for (auto g : dd) {
		if (!(x % g)) {
			ll cab = x / g + d;
			if (!(cab % c)) {
				ans += counter[cab / c];
			}
		}
	}
	cout << ans << '\n';
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