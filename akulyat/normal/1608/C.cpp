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
vector<int> a, b, cool;
vector<vector<int>> e;

void build(vector<int> a) {
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int p1, int p2) {
		return a[p1] < a[p2];
	});
	for (int i = 1; i < n; i++) {
		e[ord[i - 1]].push_back(ord[i]);
	}
	cool.push_back(ord.back());
}

vector<bool> ans;

void work(int v) {
	if (ans[v])
		return;
	ans[v] = true;
	for (auto u : e[v])
		work(u);
}

void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	cool.clear();
	for (auto &i : a)
		cin >> i;
	for (auto &i : b)
		cin >> i;

	e.assign(n, {});
	build(a);
	build(b);

	ans.assign(n, 0);
	work(cool[0]);
	work(cool[1]);

	for (auto i : ans)
		cout << i;
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