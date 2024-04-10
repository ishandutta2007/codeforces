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

int ans(vector<int> a) {
	cout << "? ";
	for (auto i : a)
		cout << i << ' ';
	cout << endl;
	int pos;
	cin >> pos;
	return pos;
}

int get_pl(int df) {
	vector<int> a(n, df);
	a.back() = 0;
	int add = 1 - (min(df, 0));
	for (auto &i : a)
		i += add;

	int res = ans(a);
	assert(res != 0);
	return res;
}

bool nice(int val) {
	vector<int> a(n, 1);
	a.back() = val;
	return ans(a) != 0;
}

void solve() {
	cin >> n;
	int lst = n;
	for (int i = 2; i <= n; i++)
		if (nice(i))
			lst--;

	vector<int> ans(n, -1);
	ans.back() = lst;
	for (int df = -n + lst; df < lst; df++)
		if (df) {
			int pl = get_pl(df);
			pl--;
			ans[pl] = lst - df;
		}

	for (auto i : ans)
		assert(i != -1);
	cout << "! ";
	for (auto i : ans)
		cout << i << ' ';
	cout << endl;
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