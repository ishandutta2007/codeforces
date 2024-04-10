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
 
 
ll n;
vector<ll> m;
bool viv = false;

void solve() {
	ll n, n1, n2;
	vector<ll> m1, m2;
	cin >> n >> n1 >> n2;
	for (ll i = 0; i < n1; i++) {
		ll a;
		cin >> a;
		m1.push_back(a);
	}
	for (ll i = 0; i < n2; i++) {
		ll a;
		cin >> a;
		m2.push_back(a);
	}

	if (*max_element(m1.begin(), m1.end()) > *max_element(m2.begin(), m2.end()))
		cout << "YES\n";
	else
		cout << "NO\n";
}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    	solve();


    return 0;
}