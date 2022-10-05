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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
vector<ll> v;
bool viv = false;

bool have(vector<vector<int>> &f, int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	return f[x][y];
}
void check(vector<vector<int>> &f, int x, int y) {
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (have(f, x + i, y + j))
				return;
	f[x][y] = 1;
}

vector<vector<int>> work(vector<vector<int>> f, int x, int y) {
	f[x][y] = 1;
	for (int j = 0; j < m; j++) {
		check(f, 0, j);
	}
	for (int i = 0; i < n; i++) {
		check(f, i, m - 1);
	}
	for (int j = m - 1; j >= 0; j--) {
		check(f, n - 1, j);
	}
	for (int i = n - 1; i >= 0; i--) {
		check(f, i, 0);
	}
	return f;
}

int cnt(vector<vector<int>> f) {
	int res = 0;
	for (auto l : f)
		for (auto i : l)
			res += i;
	return res;
}

void print(vector<vector<int>> f) {
	for (auto l : f) {
		for (auto i : l)
			cout << i;
		cout << '\n';
	}
	cout << '\n';
}

void solve() {
	cin >> n >> m;
	vector<vector<int>> f(n, vector<int>(m, 0));
	auto f1 = work(f, 0, 0);
	auto f2 = work(f, 0, 1);
	auto f3 = work(f, 1, 0);
	if (cnt(f2) > cnt(f1))
		f1 = f2;
	if (cnt(f3) > cnt(f1))
		f1 = f3;
	print(f1);
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}