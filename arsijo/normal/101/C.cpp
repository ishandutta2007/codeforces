#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-8;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
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

int bx, by, cx, cy, ax, ay;

set<ii> s;

bool dfs(int x, int y, int t) {
	if (x == bx && y == by) {
		return true;
	}
	if (t > 12) {
		return false;
	}
	if (s.find(make_pair(x, y)) != s.end())
		return false;
	s.insert(make_pair(x, y));
	if (dfs(-y, x, t))
		return true;
	if (dfs(y, -x, t))
		return true;
	if (dfs(-x, -y, t))
		return true;
	if (dfs(x + cx, y + cy, t + 1))
		return true;
	return false;
}

bool solve_long(int ax, int ay, int bx, int by, int cx, int cy) {
	::ax = ax, ::ay = ay;
	::bx = bx, ::by = by;
	::cx = cx, ::cy = cy;
	s.clear();
	return dfs(ax, ay, 0);
}

bool solve(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
	for (int i = 0; i < 4; i++) {
		if (ax == bx && ay == by)
			return true;
		swap(ax, ay);
		ax *= -1;
	}
	if (cx == 0 && cy == 0)
		return false;
	for (int i = 0; i < 4; i++) {
		ll t = cx == 0 ? (by - ay) / cy : (bx - ax) / cx;
		if (ax + t * cx == bx && ay + t * cy == by)
			return true;
		swap(cx, cy);
		cx *= -1;
	}
	for (int i = 0; i < 4; i++) {
		ll x1 = cx, y1 = cy;
		ll x2 = -cy, y2 = cx;
		if (y2 * x1 - y1 * x2 != 0) {
			ll b = ((by * x1 - y1 * bx) + (y1 * ax - x1 * ay))
					/ (y2 * x1 - y1 * x2);
			if (x1 != 0 || y1 != 0) {
				ll a = x1 == 0 ?
						(by - b * y2 - ay) / y1 : (bx - b * x2 - ax) / x1;
				if (ax + a * x1 + b * x2 == bx && ay + a * y1 + b * y2 == by) {
					return true;
				}
			}
		}
		swap(ax, ay);
		ax *= -1;
	}
	return false;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;

#ifdef LOCAL
	input;
	//output;
#else

#endif

	cin >> ax >> ay >> bx >> by >> cx >> cy;
	cout << (solve(ax, ay, bx, by, cx, cy) ? "YES" : "NO") << endl;
}