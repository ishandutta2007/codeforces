#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-10;
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
char wwww[12];
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

int main() {

	sync;
	srand(time(NULL));
	cout.precision(5);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;
	char ar[n][n];
	int x1 = INT_MAX, x2 = INT_MIN;
	int y1 = INT_MAX, y2 = INT_MIN;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> ar[i][j];
			if(ar[i][j] == '4') {
				x1 = min(x1, i);
				x2 = max(x2, i);
				y1 = min(y1, j);
				y2 = max(y2, j);
			}
		}
	}
	if(x1 == INT_MAX) {
		cout << "No" << endl;
		return 0;
	}

	int need[n][n];
	ms(need);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int a = 0;
			if((i == x1 - 1 || i == x2 + 1) && (y1 - 1 <= j && j <= y2 + 1))
			a++;
			if((j == y1 - 1 || j == y2 + 1) && (x1 - 1 <= i && i <= x2 + 1))
			a++;
			need[i][j] = (a == 0 ? 0 : a == 1 ? 2 : 1);
			if(x1 <= i && i <= x2 && y1 <= j && j <= y2)
			need[i][j] = 4;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(ar[i][j] - '0' != need[i][j]){
				cout << "No" << endl;
				return 0;
			}
		}
	}

	cout << "Yes" << endl;

}