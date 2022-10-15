#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 1000;
int X[4] = { 1, 0, -1, 0 }, Y[4] = { 0, 1, 0, -1 };
int n, m;
char ar[MAX][MAX];
int ans = 0;
int used[MAX][MAX];
vector<ii> vec;
bool ok = true;
void dfs(int x, int y, int t) {
	used[x][y] = true;
	for (int x1 = x - 1; x1 <= x + 1; x1++) {
		for (int y1 = y - 1; y1 <= y + 1; y1++) {
			if (x1 < 0 || y1 < 0 || x1 == n || y1 == m) {
				ok = false;
				continue;
			}
			if (ar[x1][y1] == '1' || used[x1][y1])
				continue;
			dfs(x1, y1, t);
		}
	}
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (0 <= i && i < n && 0 <= j && j < m) {
				if (used[i][j] != t && ar[i][j] == '1') {
					used[i][j] = t;
					vec.push_back(make_pair(i, j));
				}
			}
		}
	}
}
int sz = 0;
int s = 0;
int used2[MAX][MAX];
void dfs2(int x, int y, int t) {
	int q = 0;
	used2[x][y] = t;
	s++;
	for (int i = 0; i < 4; i++) {
		int x1 = x + X[i], y1 = y + Y[i];
		if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && used[x1][y1] == t
				&& ar[x1][y1] == '1') {
			q++;
			if (used2[x1][y1] != t)
				dfs2(x1, y1, t);
		}
	}
	if (q != 2)
		ok = false;
}
void solve(int x, int y) {
	sz++;
	vec.clear();
	ok = true;
	dfs(x, y, sz);
	s = 0;
	if (vec.empty())
		return;
	dfs2(vec[0].first, vec[0].second, sz);
	//cout << ok << " " << s << " " << vec.size() << endl;
	if (s != (int) vec.size())
		ok = false;
	if (ok) {
		ans = max(ans, (int) vec.size());
	}
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
	//output;
#else

#endif

	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> ar[i][j];
		}
	}

	for(int i = 1; i < n; i++) {
		for(int j = 1; j < m; j++) {
			if(ar[i][j] == '1' && ar[i][j] == ar[i - 1][j] && ar[i][j] == ar[i][j - 1] && ar[i][j] == ar[i - 1][j - 1])
			ans = 4;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(ar[i][j] == '0' && !used[i][j])
			solve(i, j);
		}
	}

	cout << ans << endl;

}