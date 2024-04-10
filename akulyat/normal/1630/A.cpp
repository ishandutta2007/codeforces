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
	if (k == n - 1) {
		if (n == 4) {
			cout << "-1\n";
			cout << '\n';
			return;
		}
		cout << n - 2 << ' ' << n - 1 << '\n';		
		cout << 0 << ' ' << n - 4 << '\n';		
		cout << 1 << ' ' << 3 << '\n';
		for (int i = 1; i < n / 2; i++) {
			int j = n - 1 - i;
			if (i != 0 && i != 1 && i != 3) {
				cout << i << ' ' << j << '\n';
			}
		}
		cout << '\n';
		return;
	}

	cout << k << ' ' << n - 1 << '\n';
	if (k != 0)
		cout << n - 1 - k << ' ' << 0 << '\n';
	for (int i = 1; i < n / 2; i++) {
		int j = n - 1 - i;
		if (i == k || j == k) {

		} else {
			cout << i << ' ' << j << '\n';
		}
	}
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