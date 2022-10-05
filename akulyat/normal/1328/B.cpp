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
vector<ll> v;
bool viv = false;


void solve() {
	ll n, k;
	cin >> n >> k;
	k--;
	ll kol = 1;
	string s;
	s.resize(n, 'a');
	while (k >= kol) 
		k -= kol, kol++;
	s[s.size() - 1 - kol] = 'b';
	s[s.size() - 1 - k] = 'b';
	cout << s << '\n';
}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}