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
 
 
ll n, m;
vector<string> s, t;
bool viv = false;

void prepare() {
	cin >> n >> m;
	for (ll i = 0; i < n; i++) {
		string st;
		cin >> st;
		s.push_back(st);
	}
	for (ll i = 0; i < m; i++) {
		string st;
		cin >> st;
		t.push_back(st);
	}
}

void solve() {
	ll k;
	cin >> k;
	k--;
//	k %= (n * m);
	cout << s[k % n];
	cout << t[k % m];
	cout << '\n';
}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    prepare();
    ll t = 1;
    cin >> t;
    while (t--)
    	solve();


    return 0;
}