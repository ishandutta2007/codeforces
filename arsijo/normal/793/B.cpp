#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e13 + 7;
const ld E = 1e-7;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef M_PI
#define M_PI 3.141592653589793238462643383
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
template<typename T>
inline T sqr(T t) {
	return (t * t);
}
inline void read(ll &n) {
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
char wwww[19];
int kkkk;
inline void write(ll y) {
	long long x = y;
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
	putchar(' ');
}

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 1e3 + 10;

char ar[MAX][MAX];

bool ok1[MAX][MAX];
bool ok2[MAX][MAX];

int X[4] = { 1, 0, -1, 0 };
int Y[4] = { 0, 1, 0, -1 };

void yes() {
	cout << "YES" << endl;
	exit(0);
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(12);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> ar[i][j];
		}
	}

	int x1, y1, x2, y2;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(ar[i][j] == 'S') {
				x1 = i, y1 = j;
			}
			if(ar[i][j] == 'T') {
				x2 = i, y2 = j;
			}
		}
	}

	ok2[x2][y2] = true;

	for(int q = 0; q < 4; q++) {
		int x = x2, y = y2;
		while(1 <= x && x <= n && 1 <= y && y <= m && ar[x][y] != '*') {
			ok2[x][y] = true;
			x += X[q], y += Y[q];
		}
	}

	for(int q = 0; q < 4; q++) {
		int x = x1, y = y1;
		while(1 <= x && x <= n && 1 <= y && y <= m && ar[x][y] != '*') {
			ok1[x][y] = true;
			if(ok2[x][y])
			yes();
			x += X[q], y += Y[q];
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(ok1[i][j]) {
				for(int q = 0; q < 4; q++) {
					int x = i, y = j;
					while(1 <= x && x <= n && 1 <= y && y <= m && ar[x][y] != '*') {
						if(ok2[x][y])
						yes();
						x += X[q], y += Y[q];
					}
				}
			}
		}
	}

	cout << "NO" << endl;

}