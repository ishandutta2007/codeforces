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
 
ll n, m, k;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	vector<ll> m(n);
	ll sum = 0;
	for (auto &i : m)
		cin >> i, sum += i;
	bool bad = true;
	for (ll i = 0; i < n - 1; i++)
		if ((m[i] + m[i+1]) & 1)
			bad = false;

	if (bad && !(sum & 1))
		cout << "NO\n";
	else
		cout << "YES\n";



}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
        solve();


    return 0;
}