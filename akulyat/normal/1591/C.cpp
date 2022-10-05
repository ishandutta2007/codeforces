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
#ifdef DEBUG
	mt19937 rng(1033);
#else
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());	
#endif
int rnd(int mod) { return uniform_int_distribution<int>(0, mod - 1)(rng); }


bool viv = false;
int n, k;
vector<int> v, a, b, ans;

void solver(vector<int> v) {
	// sort(v.rbegin(), v.rend());
	sort(v.begin(), v.end());
	while (v.size()) {
		vector<int> sub;
		while (v.size() && sub.size() < k)
			sub.push_back(v.back()), v.pop_back();
		int val = max(sub.back(), sub[0]);
		ans.push_back(val);
	}
}

void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	a.clear();
	b.clear();

	for (auto i : v)
		if (i > 0)
			a.push_back(abs(i));
		else
			b.push_back(abs(i));

	ans.clear();
	solver(a);
	solver(b);

	ll res = 0;
	sort(ans.begin(), ans.end());
	for (auto i : ans)
		res += 2 * i;
	// cout << "\tans = ";
	// for (auto i : ans)
	// 	cout << i << ' ';
	// cout << endl;

	res -= ans.back();

	cout << res << '\n';
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}