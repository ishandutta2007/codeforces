#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("avx2")

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


ll n, lef;
bool viv = false;
vector<ll> v;

void solve() {
	cin >> n >> lef;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i;	

	set<ll> s;
	for (int i = 1; i < 1000; i++)
		s.insert(i);
	for (auto i : v)
		s.erase(i);

	vector<ll> ans;
	for (auto i : s)
		ans.push_back(i);
	ll res = ans[lef - 1];	
	while (!s.count(res + 1))
		res++;
	cout << res << '\n';
}


int main() {
	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}