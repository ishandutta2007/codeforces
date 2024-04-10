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


ll n, k;
bool viv = false;
vector<ll> v, p;
set<ll> st;
string s;

void bad() {
	cout << -1 << '\n';
	exit(0);
}

void check(ll pl) {
	if (pl >= n - 1)
		return;
	if (pl < 0)
		return;
	if (v[pl] == 1 && v[pl + 1] == 0)
		st.insert(pl);
	else
		st.erase(pl);
}

void solve() {
	cin >> n >> k;
	cin >> s;
	for (auto i : s)
		v.push_back(i == 'R');

	p.push_back(0);
	for (int i = n - 1; i >= 0; i--)
		p.push_back(p.back() + (v[i] == 1));
	reverse(p.begin(), p.end());
	ll maxi = 0;
	for (int i = 0; i < n; i++) 
		if (v[i] == 1) {
			int me = n - i;
			me -= p[i];
			maxi += me;
		}

	if (maxi < k)
		bad();

	for (int i = 0; i < n; i++)
		check(i);

	int lef = maxi;
	vector<vector<ll>> ans;
	for (int i = 0; i < k; i++) {
		ll can = st.size();
		ll need = min(can, 1 + (lef - (k - i)));
		lef -= need;
		if (viv)
			cout << i << ": " << can << ' ' << need << ' ' << lef << endl;
		vector<ll> u;
		for (int j = 0; j < need; j++) {
			auto z = *st.begin();
			st.erase(st.begin());
			u.push_back(z);
			swap(v[z], v[z + 1]);
		}
		if (viv) {
			cout << "CH ";
			for (auto i : u)
				cout << i << ' ';
			cout << endl;
		}
		ans.push_back(u);

		for (auto i : u) {
			check(i);
			check(i + 1);
			check(i - 1);
		}
	}

	if (lef)
		bad();

	for (auto l: ans) {
		cout << l.size() << " ";		
		for (auto i : l)
			cout << i + 1 << ' ';
		cout << '\n';
	}
}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
//	cin >> t;
	while (t--)
		solve();

	return 0;
}