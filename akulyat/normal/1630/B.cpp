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
vector<int> v;


void solve() {
	cin >> n >> k;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	vector<int> cnt(n + 3, 0);
	for (auto i : v)
		cnt[i]++;

	int r = 0;
	int sum = 0;
	vector<pii> seg;
	for (int l = 1; l <= n; l++) {
		sum -= cnt[l - 1];
		while (r < cnt.size() && sum - (n - sum) < k) {
			sum += cnt[r];
			r++;
		}
		if (sum - (n - sum) >= k)
			seg.push_back({l, r - 1});
	}
	assert(seg.size());

	sort(seg.begin(), seg.end(), [](pii a, pii b){
		return (a.S - a.F) < (b.S - b.F);
	});

	int l = seg[0].F;
	r = seg[0].S;

	int next_l = 0;
	int bal = 0;
	vector<pii> ans;
	for (int i = 0; i < n; i++) {
		if (l <= v[i] && v[i] <= r) 
			bal++;
		else
			bal--;
		if (bal > 0) {
			ans.push_back({next_l, i});
			next_l = i + 1;
			bal = 0;
		}
	}
	while (ans.size() > k)
		ans.pop_back();
	ans.back().S = n - 1;

	cout << l << ' ' << r << '\n';
	for (auto p : ans)
		cout << p.F + 1 << ' ' << p.S + 1 << '\n';
	cout << '\n';
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