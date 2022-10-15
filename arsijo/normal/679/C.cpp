#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-5;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
//#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
inline void read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n')
			break;
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
}
char wwww[12];
int kkkk;
inline void write(int x) {
	kkkk = 0;
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	else
		while (x) {
			++kkkk;
			wwww[kkkk] = char(x % 10 + '0');
			x /= 10;
		}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar('\n');
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 511;
int ar[MAX][MAX];
int dp[MAX][MAX];
bool used2[MAX][MAX];
int used[MAX * MAX], size[MAX * MAX];
int color[MAX][MAX];
int n, k;
int sz = 0;
int sum = 0;

inline void _add(int x, int y) {
	if (!ar[x][y]) {
		if (used[color[x][y]]++ == 0) {
			//cout << "+ " << color[x][y] << endl;
			sum += size[color[x][y]];
		}
	}
}

inline void _remove(int x, int y) {
	if (!ar[x][y]) {
		if (--used[color[x][y]] == 0) {
			//cout << "- " << color[x][y] << endl;
			sum -= size[color[x][y]];
		}
	}
}

inline void add(int x, int y) {
	x--;
	for (int i = 0; i <= k + 1; i++, x++) {
		_add(x, y);
	}
}

inline void remove(int x, int y) {
	x--;
	for (int i = 0; i <= k + 1; i++, x++) {
		_remove(x, y);
	}
}

bool check(int x) {
	return 1 <= x && x <= n;
}

bool check(int x, int y) {
	return check(x) && check(y);
}

int X[4] = { 1, 0, -1, 0 }, Y[4] = { 0, 1, 0, -1 };

int get_sum(int x1, int y1, int x2, int y2) {
	int ans = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
	_remove(x1 - 1, y1 - 1);
	_remove(x1 - 1, y2 + 1);
	_remove(x2 + 1, y1 - 1);
	_remove(x2 + 1, y2 + 1);
	ans += sum;
	_add(x1 - 1, y1 - 1);
	_add(x1 - 1, y2 + 1);
	_add(x2 + 1, y1 - 1);
	_add(x2 + 1, y2 + 1);

	return ans;
}

int main() {

#ifdef LOCAL
	input;
	//output;
#else

#endif

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			ar[i][j] = c == 'X';
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]
					+ ar[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!ar[i][j] && !used2[i][j]) {
				sz++;
				queue<ii> q;
				q.push(make_pair(i, j));
				used2[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					color[x][y] = sz;
					q.pop();
					size[sz]++;
					for (int i = 0; i < 4; i++) {
						int x1 = x + X[i], y1 = y + Y[i];
						if (check(x1, y1) && !ar[x1][y1] && !used2[x1][y1]) {
							used2[x1][y1] = true;
							q.push(make_pair(x1, y1));
						}
					}
				}
			}
		}
	}

	int ans = 0;

	for (int i = 1; i + k - 1 <= n; i++) {
		for (int j = 0; j <= k; j++) {
			add(i, j);
		}
		for (int j = k; j <= n; j++) {
			add(i, j + 1);
			ans = max(ans, get_sum(i, j - k + 1, i + k - 1, j));
			remove(i, j - k);
		}
		for (int j = n - k + 1; j <= n + 1; j++) {
			remove(i, j);
		}
	}

	cout << ans << endl;

}