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
int n, a, b;
deque<int> v;


void solve() {
	cin >> n >> a >> b;
	if (a + b + 2 > n) {
		cout << "-1\n";
		return;
	} 
	if (abs(a - b) > 1) {
		cout << "-1\n";
		return;
	} 
	bool inv = false;
	if (a < b)
		swap(a, b), inv=true;

	v.resize(n);
	iota(v.begin(), v.end(), 0);
	bool tp = false;
	vector<int> pr;
	while (a || b) {
		assert(a >= 0);
		assert(b >= 0);
		if (!tp) {
			pr.push_back(v.back());
			v.pop_back();
			a--;
		} else {
			pr.push_back(v.front());
			v.pop_front();
			b--;
		}
		tp ^= true;
	}
	for (auto i : pr)
		v.push_front(i);


	if (!inv)
		for (auto &i : v)
			i = n - 1 - i;
	for (auto i : v)
		cout << i + 1 << ' ';
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