#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<int, int> pint;
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;;
const long long inf = ml * ml * ml + 7;
 
 
ll n, i, j, p, k;
vector<ll> m;
bool viv = false;

bool can(ll num) {
	if (num > n)
		return false;
	vector<ll> v = m;
	while (v.size() > num)
		v.pop_back();
	ll sum = 0;
	while (v.size() >= k) {
		sum += v.back();
		for (ll j = 0; j < k; j++)
			v.pop_back();
	}
	for (auto i : v)
		sum += i;
	if (viv)	
		cout << num << " is normal " << sum << ' ' << p << endl;
	return sum <= p;
}

void solve() {
	cin >> n >> p >> k;
	m.clear();
	m.resize(n);
	for (auto &i : m)
		cin >> i;
	sort(m.begin(), m.end());
	ll l, r;
	l = 0;
	r = n + 1;
	while (l + 1 < r) {
		ll mi = l + r >> 1;
		if (can(mi) || can((mi + k - 1) / k * k))
			l = mi;
		else
			r = mi;
		if (viv)
			cout << "turn to " << l << ' ' << r << endl;
	}
	cout << l << '\n';
}
 
int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    	solve();


    return 0;
}