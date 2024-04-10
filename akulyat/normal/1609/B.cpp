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
int n, q, sum;
string s;
vector<bool> v;

bool abc(int pl) {
	if (s[pl] != 'a')
		return false;
	if (s[pl + 1] != 'b')
		return false;
	if (s[pl + 2] != 'c')
		return false;
	return true;
}

void make(int pl, char c) {
	for (int i = pl - 2; i <= pl; i++) {
		if (0 <= i && i < n - 2) {
			if (v[i])
				sum--;
		}
	}
	s[pl] = c;
	for (int i = pl - 2; i <= pl; i++) {
		if (0 <= i && i < n - 2) {
			v[i] = abc(i);
			sum += v[i];
		}
	}
}

void solve() {
	cin >> n >> q;
	cin >> s;
	v.clear();
	if (n - 2 > 0)
		v.resize(n - 2);
	sum = 0;
	for (int i = 0; i < v.size(); i++) {
		v[i] = abc(i);
		sum += v[i];
	}

	// cout << sum << '\n';
	while (q--) {
		int pl;
		string t;
		cin >> pl >> t;
		pl--;
		make(pl, t[0]);
		cout << sum << '\n';
		// cout << "\t" << s << endl;;
		// cout << "\t";
		// for (auto i : v)
		// 	cout << i << ' ';
		// cout << endl;
	}


}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(20);
	int t = 1; 
	// cin >> t;
	while (t--)
		solve();

	#ifdef DEBUG
		cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
	#endif
}