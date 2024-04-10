#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e13 + 7;
const ld E = 1e-12;
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

int main() {
	sync;
	srand(time(NULL));
	cout.precision(12);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int now = 0;

	vector<pair<ld, int> > vec;
	ld first = 0, second = 1e18;
	for(int i = 0; i < n; i++) {
		ld x, y, a, b;
		cin >> x >> y >> a >> b;
		if(abs(a) + abs(b) < E) {
			if(x1 < x && x < x2 && y1 < y && y < y2) {
				now++;
				continue;
			} else {
				cout << -1 << endl;
				return 0;
			}
		}
		if(x1 <= x && x <= x2 && y1 <= y && y <= y2) {
			ld t = 1e18;
			if(a < 0) {
				t = min(t, (x1 - x) / a);
			}
			if(a > 0) {
				t = min(t, (x2 - x) / a);
			}
			if(a == 0){
				if(x == x1 || x == x2){
					cout << -1 << endl;
					return 0;
				}
			}
			if(b == 0){
				if(y == y1 || y == y2){
					cout << -1 << endl;
					return 0;
				}
			}
			if(b < 0) {
				t = min(t, (y1 - y) / b);
			}
			if(b > 0) {
				t = min(t, (y2 - y) / b);
			}
			first = max(first, (x == x1 || x == x2 || y == y1 || y == y2 ? E : 0));
			second = min(second, t - E);
		} else {
			if(b == 0) {
				ld t1 = (x1 - x) / a;
				ld t2 = (x2 - x) / a;
				if(t1 > t2) {
					swap(t1, t2);
				}
				if(y <= y1 || y >= y2){
					cout << -1 << endl;
					return 0;
				}
				if(t1 < -E) {
					cout << -1 << endl;
					return 0;
				}
				first = max(first, t1 + E);
				second = min(second, t2 - E);
				vec.push_back(make_pair(t2 - E, -1));
			} else if(a == 0) {
				ld t1 = (y1 - y) / b;
				ld t2 = (y2 - y) / b;
				if(t1 > t2) {
					swap(t1, t2);
				}
				if(x <= x1 || x >= x2){
					cout << -1 << endl;
					return 0;
				}
				if(t1 < -E) {
					cout << -1 << endl;
					return 0;
				}
				first = max(first, t1 + E);
								second = min(second, t2 - E);
			} else {
				ld tx1 = (x1 - x) / a;
				ld tx2 = (x2 - x) / a;
				ld ty1 = (y1 - y) / b;
				ld ty2 = (y2 - y) / b;
				if(tx1 > tx2)
					swap(tx1, tx2);
				if(ty1 > ty2)
					swap(ty1, ty2);
				tx1 = max(tx1, (ld) 0);
				ty1 = max(ty1, (ld) 0);
				first = max(first, max(tx1, ty1) + E);
				second = min(second, min(tx2, ty2) - E);
			}
		}
	}
	if(now == n){
		cout << 0 << endl;
		return 0;
	}
	if(first + E < second){
		cout << first << endl;
		return 0;
	}
	cout << -1 << endl;

}