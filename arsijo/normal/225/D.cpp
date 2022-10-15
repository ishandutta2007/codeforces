#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define endl "\n"
#define def(f) make(#f);
#define y1 dads
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
#ifdef LOCAL
typedef long double ld;
#else
typedef long double ld;
#endif
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-9;
const ll MOD = 1e9 + 7;
#define mod % MOD
template<typename T>
inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int n, m, len;
const int MAX = 16;
char ar[MAX][MAX];
int dp[MAX][MAX][1 << 16];

const int INF = 1e9;

int X[4] = { 0, 1, 0, -1 }, Y[4] = { 1, 0, -1, 0 };

bool find(vector<ii> vec, ii a) {
	for (int i = 0; i < (int) vec.size(); i++)
		if (vec[i] == a) {
			dbg << "find " << a.first << " " << a.second << endl;
			return true;
		}
	dbg << "not find" << endl;
	return false;
}

int solve(int x, int y, int mask) {
	assert(mask < (1 << (2 * len)));
	dbg << x << " " << y << " " << mask << endl;
	if (dp[x][y][mask] == -1) {
		dp[x][y][mask] = -2;
		vector<ii> vec;
		vec.push_back(make_pair(x, y));
		int m = mask;
		for (int i = 0; i < len; i++) {
			int a = m % 4, x = vec.back().first, y = vec.back().second;
			x += X[a], y += Y[a];
			vec.push_back(make_pair(x, y));
			m >>= 2;
		}
		vec.pop_back();
		m = mask;
		m <<= 2;
		m %= (1 << (2 * len));
		int ans = INF;
		for (int i = 0; i < 4; i++) {
			int x1 = x + X[(i + 2) % 4], y1 = y + Y[(i + 2) % 4];
			dbg << x1 << " " << y1 << " " << ar[x1][y1] << endl;
			if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < ::m && ar[x1][y1] != '#'
					&& !find(vec, make_pair(x1, y1))) {
				ans = min(ans, solve(x1, y1, m + i) + 1);
			}
		}
		dbg << "end" << endl;
		return dp[x][y][mask] = ans;
	}
	if (dp[x][y][mask] == -2)
		return INF;
	return dp[x][y][mask];
}

int solve_2(int x, int y, int mask, int xa, int ya) {
	queue<pair<ii, ii> > q;
	q.push(make_pair(make_pair(x, y), make_pair(mask, 0)));
	dp[x][y][mask] = 0;
	while (!q.empty()) {
		int x = q.front().first.first, y = q.front().first.second, mask =
				q.front().second.first, val = q.front().second.second;
		q.pop();
		if(x == xa && y == ya)
			return val;
		vector<ii> vec;
		vec.push_back(make_pair(x, y));
		int m = mask;
		for (int i = 0; i < len; i++) {
			int a = m % 4, x = vec.back().first, y = vec.back().second;
			x += X[a], y += Y[a];
			vec.push_back(make_pair(x, y));
			m >>= 2;
		}
		vec.pop_back();
		m = mask;
		m <<= 2;
		m %= (1 << (2 * len));
		for (int i = 0; i < 4; i++) {
			int x1 = x + X[(i + 2) % 4], y1 = y + Y[(i + 2) % 4];
			if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < ::m && ar[x1][y1] != '#'
					&& !find(vec, make_pair(x1, y1)) && dp[x1][y1][m + i] == -1) {
				dp[x1][y1][m + i] = val + 1;
				q.push(make_pair(make_pair(x1, y1), make_pair(m + i, val + 1)));
			}
		}
	}
	return -1;
}

int main() {

	cout.precision(11);

	cout << fixed;
	sync;
	srand(time(NULL));
#ifdef LOCAL
	input;
#else

#endif

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ar[i][j];

	int xa, ya;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (ar[i][j] == '@')
				xa = i, ya = j;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int z = 0; z < (1 << 16); z++)
				dp[i][j][z] = -1;

	vector<ii> vec;
	for (int z = 1; z <= 9; z++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ar[i][j] == z + '0') {
					vec.push_back(make_pair(i, j));
				}
			}
		}
	}

	len = (int) vec.size() - 1;
	int mask = 0;
	for (int i = (int) vec.size() - 2; i >= 0; i--) {
		int res = 0;
		for (int j = 0; j < 4; j++) {
			if (vec[i].first + X[j] == vec[i + 1].first
					&& vec[i].second + Y[j] == vec[i + 1].second)
				res = j;
		}
		mask <<= 2;
		mask |= res;
	}

	int ans = solve_2(vec[0].first, vec[0].second, mask, xa, ya);
	cout << (ans >= INF ? -1 : ans);

}