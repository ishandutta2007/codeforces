#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef int       ll;
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

ll n, m;
vector<ll> v1, v2;
vector<ll> p1, p2;
bool viv = false;

ll work(vector<ll> v, vector<ll> p) {
	int n = v.size();
	int m = p.size();
	
	sort(v.begin(), v.end());
	sort(p.begin(), p.end());

	ll good = 0;
	set<ll> sp;
	for (auto i : p)
		sp.insert(i);

	for (auto i : v)
		good += (sp.find(i) != sp.end());
	ll ans = good;


	int l = 0;
	int r = 0;
	for (int j = 0; j < n; j++) {
		good -= (sp.find(v[j]) != sp.end());
		int p1 = v[j];
		int p2 = mod + ml;
		if (j + 1 != n)
			p2 = v[j + 1];		

		while (r < m && p[r] < p1)
			r++;
		while (r < m && p[r] < p2) {
			while (l < r && (p[r] - p[l] + 1) > (j + 1))
				l++;
			ans = max(ans, good + (r - l + 1));
			r++;
		}

	}
	return ans;
}

void solve() {
	cin >> n >> m;
	v1.clear();
	v2.clear();
	p1.clear();
	p2.clear();
	for (int i = 0; i < n; i++) {
		int pl;
		cin >> pl;
		if (pl > 0)
			v1.push_back(pl);
		else
			v2.push_back(-pl);
	}
	for (int i = 0; i < m; i++) {
		int pl;
		cin >> pl;
		if (pl > 0)
			p1.push_back(pl);
		else
			p2.push_back(-pl);
	}
	ll ans = 0;
	ans += work(v1, p1);
	ans += work(v2, p2);
	cout << ans << '\n';
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