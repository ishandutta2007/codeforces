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
string s;
vector<vector<ll>> ans;
bool viv = false;

bool can() {
	if (s.empty())
		return false;
	for (ll i = 0; i < (ll)s.size() - 1; i++) {
		if (s[i] == '(' && s[i + 1] == ')')
			return true;
	}
	return false;
}

void build() {
	ll n = s.size();

	vector<ll> p, sf;
	p.push_back(0);
	for (ll i = 0; i < s.size(); i++)
		p.push_back(p.back() + (s[i] == '('));
	sf.push_back(0);
	for (ll i = (ll)s.size() - 1; i >= 0; i--)
		sf.push_back(sf.back() + (s[i] == ')'));
	reverse(sf.begin(), sf.end());
	ll pr = 0;
	for (ll i = 0; i < n; i++) {
		if (p[i] == sf[i])
			pr = i;
	}
//	cout << pr << endl;
	string s2;
	vector<ll> add;
	for (ll i = 0; i < n; i++) {
		if (i < pr) {
			if (s[i] == '(')
				add.push_back(i);
			else
				s2 += s[i];
		} else {
			if (s[i] == ')')
				add.push_back(i);
			else
				s2 += s[i];
		}
	}
	ans.push_back(add);
	s = s2;

//	cout << s << endl;
}

void solve() {
	cin >> s;
	n = s.size();
	while (can()) 
		build();
	cout << ans.size() << '\n';
	for (auto v : ans) {
		cout << v.size() << '\n';
		for (auto i : v)
			cout << i + 1 << ' ';
		cout << '\n';
	}
}


int main() {
//  viv = true;
	srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();


    return 0;
}