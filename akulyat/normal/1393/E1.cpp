#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef int 	        ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 

ll n;
vector<string> v;
vector<vector<int>> dp;
vector<vector<int>> simple, fast, slow;
bool viv = false;

bool dif(int num, int p1, int p2) {
	if (p1 >= v[num - 1].size() || p2 > v[num].size())
		return true;
	if (p1 < 0 || p2 < 0)
		return true;
	return v[num - 1][p1] != v[num][p2];
}

void prepare() {
	simple.resize(n);
	slow.resize(n);
	fast.resize(n);
	for (int i = 0; i < n; i++)
		simple[i].resize(v[i].size() + 1),
		fast[i].resize(v[i].size() + 1),
		slow[i].resize(v[i].size() + 1);
	for (int i = 1; i < n; i++) {
		int last = v[i].size();
		simple[i].back() = last;
		for (int j = v[i].size() - 1; j >= 0; j--) {
			if (dif(i, j, j))
				last = j;
			simple[i][j] = last;
		}
	}
	for (int i = 1; i < n; i++) {
		int last = v[i].size();
		slow[i].back() = last;
		for (int j = v[i].size() - 1; j >= 0; j--) {
			if (dif(i, j - 1, j))
				last = j;
			slow[i][j] = last;
		}
	}
	for (int i = 1; i < n; i++) {
		int last = v[i].size();
		fast[i].back() = last;
		for (int j = v[i].size() - 1; j >= 0; j--) {
			if (dif(i, j + 1, j))
				last = j;
			fast[i][j] = last;
		}
	}

	if (viv) {
		cout << "simple" << endl;
		for (auto l : simple) {
			for (auto i : l)
				cout << i << ' ';
			cout << endl;
		}
		cout << "slow" << endl;
		for (auto l : slow) {
			for (auto i : l)
				cout << i << ' ';
			cout << endl;
		}
		cout << "fast" << endl;
		for (auto l : fast) {
			for (auto i : l)
				cout << i << ' ';
			cout << endl;
		}
	}
}

char cmp(int num, int p1, int p2) {
	bool b1 = (p1 < 0) || (p1 >= v[num - 1].size());
	bool b2 = (p2 < 0) || (p2 >= v[num].size());
	if (b1 && b2)
		return 0;
	if (b1)
		return 1;
	if (b2)
		return -1;
	if (v[num - 1][p1] == v[num][p2])
		return 0;
	if (v[num - 1][p1] > v[num][p2])
		return -1;
	if (v[num - 1][p1] < v[num][p2])
		return 1;
}

bool good(int num, int p1, int p2) {
	ll d1 = simple[num][0];
	if (d1 < min(p1, p2)) {
		if (cmp(num, d1, d1) == 1)
			return true;
		if (cmp(num, d1, d1) == -1)
			return false;
	}

	if (p1 <= p2) {
		ll d2 = fast[num][p1];
		if (d2 < max(p1, p2)) {
			if (cmp(num, d2 + 1, d2) == 1)
				return true;
			if (cmp(num, d2 + 1, d2) == -1)
				return false;
		}
	}
	if (p1 >= p2) {		
		ll d2 = p2 + 1;
		if (d2 < slow[num].size())
			d2 = slow[num][d2];
		if (d2 <= max(p1, p2)) {
			if (cmp(num, d2 - 1, d2) == 1)
				return true;
			if (cmp(num, d2 - 1, d2) == -1)
				return false;
		}
	}
	ll d3 = max(p1, p2) + 1;

	if (d3 < simple[num].size())
		d3 = simple[num][d3];

	if (cmp(num, d3, d3) == -1)
		return false;
	return true;
}

void solve() {
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	prepare();

	dp.resize(n);
	for (int i = 0; i < n; i++)
		dp[i].resize(v[i].size() + 1);

	for (auto &i : dp[0])
		i = 1;
	if (viv) {
		cout << "dp" << endl;
		for (auto i : dp[0]) {
			cout << i << ' ';
		}
		cout << endl;
	}
	for (int i = 1; i < n; i++) {
		for (int p1 = 0; p1 < dp[i - 1].size(); p1++) {
			for (int p2 = 0; p2 < dp[i].size(); p2++) {
				if (good(i, p1, p2)) {
					dp[i][p2] += dp[i - 1][p1];
					if (viv)
						cout << "add " << i << ' ' << p2 << " with " << p1 << endl;
					if (dp[i][p2] >= mod)
						dp[i][p2] -= mod;
				}
			}
		}
		if (viv) {
			for (auto i : dp[i]) {
				cout << i << ' ';
			}
			cout << endl;
		}
	}

	ll res = 0;
	for (auto i : dp.back()) {
		res += i;
		if (res >= mod)
			res -= mod;
	}

	cout << res << '\n';
}

int main() {
	// viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	// cin >> t;
	while (t--)
		solve();

	return 0;
}