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
vector<int> ans;

void maker(int l) {
	int val = (v[l] ^  v[l + 1] ^ v[l + 2]);
	v[l] = v[l + 1] = v[l + 2] = val;
	ans.push_back(l);
}

void work(int pl1, int pl2, int pl3, int pl0) {
	if (viv) {
		cout << "work(" << pl1 << ' ' << pl2 << ' ' << pl3 << ' ' << pl0 << ")" << endl;
		cout << "v = ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}
	int sum = 0;
	sum += v[pl1];
	sum += v[pl2];
	sum += v[pl3];
	if (sum == 0)
		return;
	if (sum == 3) {
		assert(false);
	}
	if (sum == 2) {
		maker(min(pl1, pl3));
		return;
	}
	if (sum == 1) {
		if (v[pl1]) {
			maker(min(pl1, pl3));
			maker(min(pl0, pl2));
		}	}
}

void printer() {
	cout << "YES\n";
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i + 1 << ' ';
	cout << '\n';
}

void solver(int pl) {
	for (int i = pl; i < n - 2; i++) {
		work(i, i + 1, i + 2, i - 1);
	}
	for (int i = pl; i >= 2; i--) {
		work(i, i - 1, i - 2, i + 1);
	}
	printer();
}

void solve() {
	cin >> n;
	v.resize(n);
	int cnt = 0;	
	ans.clear();
	for (auto &i : v)
		cin >> i, cnt += i;
	if (cnt & 1 || cnt == n) {
		cout << "NO\n";
		return;
	} 
	if (cnt == 0) {
		printer();
		return;
	}

	int c = 0;
	for (int i = 0; i < n; i++) {
		c += v[i];
		if (!(c & 1) && v[i] == 0) {
			solver(i);
			return;
		}
	}
	for (int i = 0; i < n - 2; i++) {
		if (cnt + 2 < n) {
			if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 0)
				maker(i), cnt += 2;
		}
	}
	if (viv) {
		cout << "v1 = ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}
	for (int i = 0; i < n - 2; i++) {
		if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 1)
			maker(i);
	}
	if (viv) {
		cout << "v2 = ";
		for (auto i : v)
			cout << i << ' ';
		cout << endl;
	}
	c = 0;
	for (int i = 0; i < n; i++) {
		c += v[i];
		if (!(c & 1) && v[i] == 0) {
			solver(i);
			return;
		}
	}
	cout << "NO\n";
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