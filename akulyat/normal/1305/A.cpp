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


ll n;
vector<ll> m;
bool viv = false;

void solve() {
	cin >> n;
	vector<ll> m1, m2;
	m1.resize(n);
	m2.resize(n);
	for (auto &i : m1)
		cin >> i;
	for (auto &i : m2)
		cin >> i;
	sort(m1.begin(), m1.end());
	sort(m2.begin(), m2.end());
	for (auto i : m1)
		cout << i << ' ';
	cout << '\n';
	for (auto i : m2)
		cout << i << ' ';
	cout << '\n';
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