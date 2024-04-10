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
	string s;
	cin >> n >> s;
	m.clear();
	ll now = 1;
	s += '>';
	for (ll i = 0; i < s.size(); i++) {
		if (s[i] == '<')
			now++;
		else
			m.push_back(now), now = 1;
	}
	// for (auto i : m)
	// 	cout << i << ' ';
	// cout << endl;

	vector<ll> ans1, ans2;
	ll val = n;
	for (ll i = 0; i < m.size(); i++) {
		vector<ll> v;
		for (ll j = val; j > val - m[i]; j--)
			v.push_back(j);
		reverse(v.begin(), v.end());
		for (auto i : v)
			ans1.push_back(i);
		val -= m[i];
	}
	for (auto i : ans1)
		cout << i << ' ';
	cout << '\n';

	vector<vector<ll>> vec;
	vec.resize(m.size());
	ll v = m.size();
	ll add = 1;
	for (ll i = 0; i < v; i++) {
		vec[i].push_back(v - i);
		for (ll j = 1; j < m[i]; j++)
			vec[i].push_back(v + add), add++;
	}
	for (auto v : vec)
		for (auto i : v)
			ans2.push_back(i);

	for (auto i : ans2)
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