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
	ll n;
	string s;
	cin >> n;
	cin >> s;
	string a1, a2;
	bool was = false;
	for (int i = 0; i < n; i++) {
		if (was) {
			a1 += '0';
			a2 += s[i];
		} else {
			if (s[i] == '2')
				a1 += '1', a2 += '1';
			else {
				if (s[i] == '0')
					a1 += '0', a2 += '0';
				else {
					a1 += '1', a2 += '0', was = true;;
				}
			}
		}
	}
	cout << a1 << '\n';
	cout << a2 << '\n';	
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