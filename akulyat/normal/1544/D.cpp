#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> v;
set<int> s;
bool viv = false;

vector<int> take(bool str) {
	vector<int> ord(n);
	for (int i = 0; i < n; i++)
		ord[i] = i;
	if (str)
		reverse(ord.begin(), ord.end());

	auto fs = s;
	vector<int> ans(n, -1);
	for (auto i : ord) {
		if (fs.count(v[i])) {
			ans[i] = v[i];
			fs.erase(v[i]);
		}
	}
	return ans;
}

bool work(vector<int> ans) {
	vector<int> pl;
	for (int i = 0; i < n; i++)
		if (ans[i] == -1)
			pl.push_back(i);
	vector<int> pp;
	set<int> spp;
	for (int i = 0; i < n; i++)
		if (!s.count(i)) {
			spp.insert(i);
			pp.push_back(i);
		}

	set<int> com;
	for (auto i : pl)
		if (spp.count(i))
			com.insert(i);


	vector<int> pla, plb;
	vector<int> ppa, ppb;

	for (auto i : pl) {
		if (com.count(i))
			pla.push_back(i);
		else
			plb.push_back(i);
	}
	for (auto i : pp) {
		if (com.count(i))
			ppa.push_back(i);
		else
			ppb.push_back(i);
	}

	if (pla.size() == 1) {
		if (plb.size() == 0)
			return false;
		if (pla[0] == ppa[0]) {
			swap(pla[0], plb[0]);
		}
	} else {
		if (pla.size()) {
			pla.push_back(pla[0]);
			reverse(pla.begin(), pla.end());
			pla.pop_back();
			reverse(pla.begin(), pla.end());
		}
	}

	for (int i = 0; i < pla.size(); i++)
		ans[pla[i]] = ppa[i];
	for (int i = 0; i < plb.size(); i++)
		ans[plb[i]] = ppb[i];

	cout << s.size() << '\n';
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
	return true;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i, i--;
	s.clear();
	for (auto i : v)
		s.insert(i);
	{
		auto ans = take(true);
		if (work(ans))
			return;
	}
	{
		auto ans = take(false);
		if (work(ans))
			return;
	}
	assert(false);
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}