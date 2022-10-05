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
vector<ll> m;
vector<ll> tp;
bool viv = false;

void check(string s) {
	cout << s << endl;
	ll res;
	cin >> res;
	m.push_back(res);
	if (res == 0 || res == -1)
		exit(0);	
}

void solve() {
	check("a");	
	n = m.back();
	string s;
	for (ll i = 0; i < n; i++)
		s += 'b';
	check(s);
	a = m.back();
	n++;
	s += 'b';
	vector<ll> pl;
	for (ll i = 0; i < n - 1; i++) {
		s[i] = 'a';
		check(s);
		if (m.back() < a)
			pl.push_back(i);
		s[i] = 'b';
	}
	if (pl.size() < a)
		pl.push_back(n - 1);
	for (auto i : pl)
		s[i] = 'a';
	check(s);
}
 
int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    while (t--)
    	solve();


    return 0;
}