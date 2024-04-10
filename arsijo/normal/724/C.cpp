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
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#ifndef M_PI
#define M_PI acos(-1)
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
	if (x < 0) {
		putchar('-');
		x *= -1;
	}
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
}

#ifdef LOCAL
//#define DEBUG
#endif

const int MAX = 1e5 + 2;

vector<int> v1[MAX * 2 + 10], v2[MAX * 2 + 10];

int get_1(int x, int y) {
	return x + y;
}

int get_2(int x, int y) {
	return x - y + MAX;
}

ll ans[MAX];
int _x[MAX];

int n, m;

inline bool check(int x, int y){
	return (0 <= x && x <= n && 0 <= y && y <= m);
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int k;
	cin >> n >> m >> k;

	ll INF = 1e18;

	for(int i = 1; i <= k; i++) {
		ans[i] = INF;
		int x, y;
		cin >> x >> y;
		_x[i] = x;
		v1[get_1(x, y)].push_back(i);
		v2[get_2(x, y)].push_back(i);
	}

	int x = 0, y = 0;
	int X = 1, Y = 1;

	ll time = 0;

	while((x != 0 || y != m) && (x != n || y != 0) && (x != n || y != m)) {
		if(X == Y) {
			int ind = get_2(x, y);
			for(int a : v2[ind]) {
				ans[a] = min(ans[a], time + abs(_x[a] - x));
			}
		} else {
			int ind = get_1(x, y);
			for(int a : v1[ind]) {
				ans[a] = min(ans[a], time + abs(_x[a] - x));
			}
		}
		int l = 1, r = 1e5;
		while(l < r){
			int z = (l + r + 1) >> 1;
			if(check(x + X * z, y + Y * z)){
				l = z;
			}else{
				r = z - 1;
			}
		}
		time += l;
		x += l * X;
		y += l * Y;
		if(x == n || x == 0)
			X *= -1;
		if(y == m || y == 0)
			Y *= -1;
	}

	for(int i = 1; i <= k; i++){
		cout << (ans[i] == INF ? -1 : ans[i]) << endl;
	}

}