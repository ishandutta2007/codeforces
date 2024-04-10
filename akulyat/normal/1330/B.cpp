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
bool viv = false;
vector<ll> v;

void solve() {
	cin >> n;
	v.clear();
	v.resize(n);
	for (auto &i : v)
		cin >> i;	
	set<ll> s;
	multiset<ll> ans1, ans2;
	for (int i = 0; i < n - 1; i++) {
		s.insert(v[i]);
		if (i + 1 == s.size() && s.size() == *s.rbegin())
			ans1.insert(i + 1);
	}
	s.clear();
	reverse(v.begin(), v.end());
	for (int i = 0; i < n - 1; i++) {
		s.insert(v[i]);
		if (i + 1 == s.size() && s.size() == *s.rbegin())
			ans2.insert(n - i - 1);
	}
	vector<ll> ans;
	for (auto i : ans1)
		if (ans2.count(i))
			ans.push_back(i);
	cout << ans.size() << '\n';
	for (auto l : ans)
		cout << l << ' ' << n - l << '\n';

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