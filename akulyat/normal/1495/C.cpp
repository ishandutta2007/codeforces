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

int n, m;
vector<vector<int>> v;
bool viv = false;

void read() {
	cin >> n >> m;
	if (viv && v.size())
		cout << v.size() << ' ' << v[0].size() << endl;

	v.assign(n, vector<int>(m, 0));

	for (auto &l : v) {
		string s;
		cin >> s;
		for (int i = 0; i < m; i++)
			l[i] = (s[i] == 'X');
	}
}

void write() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (v[x][y]) 
				cout << 'X';
			else
				cout << '.';
		}
		cout << '\n';
	}
	cout << '\n';
}


void solve() {
	read();
	for (int i = 0; i < n; i += 3) {
		bool need = i + 2 < n;
		bool put = !need;
		for (int j = 0; j < m; j++) {
			v[i][j] = 1;
			if (!put) {
				if (v[i + 2][j] == 1 || v[i + 1][j] == 1) {
					v[i + 1][j] = v[i + 2][j] = 1;
					if (i + 3 < n)
						put = true;
				}
			}
		}
		if (!put && (i + 3 < n))
			v[i + 1][0] = v[i + 2][0] = 1;
	}
	write();
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