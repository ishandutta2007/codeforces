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
int n;
vector<int> v;

// int solver(deque<ll> v) {
// 	if (v.empty())
// 		return 0;

// 	vector<ll> df;
// 	df.push_back(-inf);
// 	for (int i = 1; i < v.size() + 1; i++) {
// 		if (df.size() == 1 || df[df.size() - 2] <= df[df.size() - 1]) {
// 			df.push_back(v[i] - v[i - 1]);
// 			if (viv)
// 				cout << "added " << df.back() << endl;
// 		}
// 		else {
// 			df.back() += (v[i] - v[i - 1]);
// 			if (viv)
// 				cout << "upped to " << df.back() << endl;
// 		}
// 	}
// 	ll lres = (int)v.size() + 1 - (int)df.size();
// 	v.pop_front();
// 	ll lres2 = 1 + solver(v);
// 	// ll lres2 = lres;
// 	return min(lres, lres2);
// }

int tr(int pl) {
	vector<int> a = {pl, pl + 1};
	while (a.back() != n) {
		int val = 2 * v[a.back()] - v[a[0]];
		int p = lower_bound(v.begin() + a.back() + 1, v.end(), val) - v.begin();
		a.push_back(p);

		// if (add.count( h(a[a.size() - 2], a.back()) ))
		// 	break;
	}
	int lres = 0;
	// lres = add[h(a[a.size() - 2], a.back())];
	int res = a.size() + lres;

	// for (auto i : a)
	// 	cout << i << ' ';
	// cout << ": Adder " << lres;
	// cout << endl;
	// while (a.size() >= 2) {
	// 	// cout << "\t" << a[a.size() - 2] << ' ' << a.back() << " get " << lres << endl;
	// 	add[h(a[a.size() - 2], a.back())] = lres;
	// 	lres++;
	// 	a.pop_back();
	// }
	return res;
}

int solver2() {
	int res = 0;
	for (int i = n - 2; i >= 0; i--)	
		if (!i || v[i] != v[i - 1])
		res = max(res, tr(i));
	return n + 1 - res;
}

unordered_map<ll, int> add;
 
inline h(int a, int b) {
	return ml * a + b;
}

int tr3(int pl) {
	vector<int> a = {pl, pl + 1};
	while (a.back() != n) {
		ll val = 2 * v[a.back()] - v[a[a.size() - 2]];
		int p = lower_bound(v.begin() + a.back() + 1, v.end(), val) - v.begin();
		a.push_back(p);
 
		if (add.count( h(a[a.size() - 2], a.back()) ))
			break;
	}
	int lres = add[h(a[a.size() - 2], a.back())];
	int res = a.size() + lres;
 
	// for (auto i : a)
	// 	cout << i << ' ';
	// cout << ": Adder " << lres;
	// cout << endl;
	while (a.size() >= 2) {
		// cout << "\t" << a[a.size() - 2] << ' ' << a.back() << " get " << lres << endl;
		add[h(a[a.size() - 2], a.back())] = lres;
		lres++;
		a.pop_back();
	}
	return res;
}
 
int solver3() {
	int res = 0;
	for (int i = n - 2; i >= 0; i--)	
		res = max(res, tr3(i));
	return n + 1 - res;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	add.clear();

	v.push_back(2 * mod);

	// int res = solver(v);
	int res = solver2();
	int res2 = solver3();
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