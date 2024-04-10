#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 


ll n, k, ans;
vector<ll> v, p; 
bool viv = false;

void check(vector<ll> v) {
	vector<ll> sam(v.size(), 1);
	for (int i = 1; i < v.size(); i++)
		if (v[i] == v[i - 1])
			sam[i] += sam[i - 1];
	for (auto i : sam)
		if (i >= k) {
			cout << 0 << endl;
			exit(0);
		}
}

ll sum(ll l, ll r) {
	r++;
	return p[r] - p[l];	
}

void gg(ll val) {
	ans = min(ans, val);
}

ll getp(ll len, ll pos) {
	if (v[pos - len] == v[pos])
		return 0;

	ll lans = 0;
	lans += v[pos] * (pos);
	lans -= sum(0, pos - 1);
	lans -= (pos - len);
	return lans;
}

ll gets(ll len, ll pos) {
	if (v[pos + len] == v[pos])
		return 0;

	ll lans = 0;
	lans += sum(pos + 1, n - 1);
	lans -= v[pos] * (n - pos - 1);
	lans -= ((n - pos - 1) - len);
	return lans;
}

void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	sort(v.begin(), v.end());
	check(v);

	p.push_back(0);
	for (auto i : v)
		p.push_back(p.back() + i);

	ans = inf;

	for (ll i = 0; i < n; i++) {
		ll p1 = min(i, k - 1);
		ll s1 = k - 1 - p1;
		ll s2 = min(n - i - 1, k - 1);
		ll p2 = k - 1 - s2;

		ll lans1 = 0;
		lans1 += getp(p1 ,i);
		lans1 += gets(s1, i);

		ll lans2 = 0;
		lans2 += getp(p2, i);
		lans2 += gets(s2, i);

		ans = min(lans1, ans);
		ans = min(lans2, ans);

		
	}

	cout << ans << endl;
}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
//	cin >> t;
	while (t--)
		solve();

	return 0;
}