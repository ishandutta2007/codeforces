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

ll n;
vector<string> v;
bool viv = false;

bool tr(int a, int b) {
	int cnta[2];
	int cntb[2];
	cnta[0] = cnta[1] = 0;
	cntb[0] = cntb[1] = 0;

	for (auto i : v[a])
		cnta[i - '0']++;
	for (auto i : v[b])
		cntb[i - '0']++;

	int c = -1;
	if (cnta[0] >= n && cntb[0] >= n)
		c = 0;
	if (cnta[1] >= n && cntb[1] >= n)
		c = 1;
	if (c == -1)
		return false;

	int i = 0, j = 0;
	string res;
	while (i < 2 * n && j < 2 * n) {
		int put = 1 - c;
		if (v[a][i] == v[b][j])
			put = v[a][i] - '0';
		if (v[a][i] - '0' == put)
			i++;
		if (v[b][j] - '0' == put)
			j++;
		res.push_back(char('0' + put));
	}
	while (i < 2 * n) {
		int put = v[a][i] - '0';
		i++;
		res.push_back(char('0' + put));
	}
	while (j < 2 * n) {
		int put = v[b][j] - '0';
		j++;
		res.push_back(char('0' + put));
	}


	cout << res << '\n';
	if (viv && res.size() > 3 * n) {
		cout << "BAD\n" << res.size() << '\n';
		exit(0);
	}
	return true;
}

void solve() {
	cin >> n;
	v.resize(3);
	for (auto &s : v)
		cin >> s;

	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 3; j++)
			if (tr(i, j))
				return;
	// assert(false);
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