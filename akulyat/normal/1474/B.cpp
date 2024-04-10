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
vector<ll> v, p;
	set<ll> s;
bool viv = false;

vector<ll> erat(int last) {
	vector<bool> prime(last + 1, true);
	vector<ll> res;
	for (int i = 2; i <= last; i++) {
		if (prime[i])
			res.push_back(i);
		if ((ll)i * i < last)
			for (int j = i * i; j <= last; j += i)
				prime[j] = false;
	}
	return res;
}


void solve() {
	ll d;
	cin >> d;

	ll a = d + 1;
	a = *s.lower_bound(a);
	ll b = a + d;
	b = *s.lower_bound(b);
	cout << a * b << '\n';
}

int main() {
	p = erat(100 * kk);
	for (auto i : p)
		s.insert(i);
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}