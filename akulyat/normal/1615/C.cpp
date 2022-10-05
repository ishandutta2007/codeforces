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
string a, b;


void solve() {
	cin >> n;
	cin >> a >> b;
	int s = 0, c = 0;
	int a0 = 0;
	int a1 = 0;
	int b0 = 0;
	int b1 = 0;
	int c00 = 0;
	int c01 = 0;
	int c10 = 0;
	int c11 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '1')
			a1++;
		else
			a0++;
		if (b[i] == '1')
			b1++;
		else
			b0++;
		if (a[i] == b[i])
			s++;
		else
			c++;
		if (a[i] == '0' && b[i] == '0')
			c00++;
		if (a[i] == '0' && b[i] == '1')
			c01++;
		if (a[i] == '1' && b[i] == '0')
			c10++;
		if (a[i] == '1' && b[i] == '1')
			c11++;
	}
	int ans = mod;
	// if (abs(c00 - c11) <= 1)
	// 	ans = min(ans, c00 + c11);
	// if (abs(c01 - c10) <= 1)
	// 	ans = min(ans, c01 + c10);
	// if (!(a0 == b0) && !(1 + a0 == b1)) {
	// 	cout << "-1\n";
	// 	return;
	// }
	if (c % 2 == 0 && a1 == b1)
		ans = min(ans, c);
	if (s % 2 == 1 && (1 + a0 == b1))
		ans = min(ans, s);

	if (ans == mod)
		ans = -1;
	cout << ans << '\n';
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