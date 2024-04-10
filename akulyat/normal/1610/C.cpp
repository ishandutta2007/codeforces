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
vector<int> a, b;

bool can(int k) {
	int w1 = k - 1;
	int w2 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= w1 && b[i] >= w2) {
			w1--, w2++;
		}
	}
	return w2 >= k;
}

void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];

	int l = 0;
	int r = n + 1;
	while (l + 1 < r) {
		int m = l + r >> 1;
		if (can(m))
			l = m;
		else
			r = m;
	}
	cout << l << endl;
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