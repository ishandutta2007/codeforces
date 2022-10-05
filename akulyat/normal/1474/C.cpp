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

ll n;
vector<ll> v;
bool viv = false;

bool work(vector<ll> v, int pl) {
	swap(v[pl], v[n - 2]);
	int c = v.back() + v[n - 2];
	vector<pll> ans(1, {v[n - 2], v[n - 1]});

	multiset<int> s;
	for (int i = 0; i < n - 2; i++)
		s.insert(-v[i]);
	int cc = v[n - 1];

	while (s.size()) {
		int a = -(*s.begin());
		s.erase(s.begin());
		int b = -(cc - a);
		if (!s.count(b))
			return false;
		s.erase(s.find(b));
		b = -b;
		ans.push_back({a, b});
		cc = max(a, b);		
	}
	cout << "YES\n";
	cout << c << '\n';
	for (auto p : ans)
		cout << p.F << ' ' << p.S << '\n';
}

void solve() {
	cin >> n;
	n *= 2;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1; i++)
		if (work(v, i)) 
			return;
	cout << "NO\n";
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