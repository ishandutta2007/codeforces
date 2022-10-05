#include <bits/stdc++.h>
 
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
const long long mod = ml * kk + 7;;
const long long inf = ml * ml * ml + 7;
 
 
ll n, t, a, b;
vector<pll> m;
vector<ll> tp;
bool viv = false;

void solve() {
	cin >> n >> t >> a >> b;
	tp.clear();
	tp.resize(n);
	m.clear();
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		tp[i] = a;
	}
	ll la, lb;
	la = lb = 0;
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		if (tp[i])
			m.push_back({a, 1}), lb++;
		else
			m.push_back({a, 0}), la++;
	}
	ll sum = 0;
	sort(m.begin(), m.end());
	m.push_back({inf, -1});
	ll rans = 0;
	ll can = m[0].F - 1;
	if (can >= 0) {
		ll add;
		add = min(la, can / a);
		rans += add;
		can -= add * a;

		add = min(lb, can / b);
		rans += add;
		can -= add * b;
	}

	for (ll i = 0; i < n; i++) {
		if (m[i].S) {
			sum += b;
			lb--;
		} else {
			sum += a;
			la--;
		}
		ll can = min(t, m[i+1].F - 1) - sum;
		if (can >= 0) {
			ll ans = i + 1;
			if (viv)
				cout << ans << ' ' << can << ' ';
			ll add;
			add = min(la, can / a);
			ans += add;
			can -= add * a;

			add = min(lb, can / b);
			ans += add;
			can -= add * b;
			rans = max(rans, ans);
			if (viv)	
				cout << i << ' ' << rans << endl;		
		}
	}
	cout << rans << '\n';
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