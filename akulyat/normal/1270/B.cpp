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
	ll n;
	cin >> n;
	vector<ll> m;
	m.resize(n);
	for (auto &i : m)
		cin >> i;
	for (ll i = 0; i < n - 1; i++) {
		if (abs(m[i] - m[i+1]) > 1) {
			cout << "YES\n";
			cout << i + 1 << ' ';
			cout << i + 2 << '\n';
			return;
		}
	}
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