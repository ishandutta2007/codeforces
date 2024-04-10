#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-5;
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

const int MAX = 2e3 + 10;

int a[MAX], b[MAX], c[MAX];

map<ii, int> dp[MAX][MAX];

int n, p, k;

inline int upd(int &a, int b){
	a = max(a, b);
	return a;
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n >> p >> k;

	int h;
	cin >> h;
	while(h--) {
		int t;
		cin >> t;
		a[t] = 1;
	}

	cin >> h;
	while(h--) {
		int t;
		cin >> t;
		b[t] = 1;
	}

	for(int i = 1; i <= n; i++) {
		if(a[i] || b[i])
		c[i] = 1;
		a[i] += a[i - 1], b[i] += b[i - 1], c[i] += c[i - 1];
		//cout << i << " " << c[i] << endl;
	}

	//cout << a[n] << " " << b[n] << " " << c[n] << endl;
	dp[1][0][make_pair(0, 0)] = 0;

	int ans = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= p; j++) {
			for(pair<ii, int> a : dp[i][j]) {
				ans = max(ans, a.second);
				//cout << i << " " << j << " " << a.first.first << " " << a.first.second << " " << a.second << endl;
				if(a.first.first == 0) {
					upd(dp[i][j + 1][make_pair(k, a.first.second)], a.second);
				}
				if(a.first.second == 0) {
					upd(dp[i][j + 1][make_pair(a.first.first, k)], a.second);
				}
				int d = min(a.first.first, a.first.second);
				if(d) {
					int to = i + d;
					if(to > n) {
						ans = max(ans, a.second + c[n] - c[i - 1]);
					} else {
						//cout << "to " << to << " " << j << " " << a.second + c[to] - c[i - 1] << endl;
						upd(dp[to][j][make_pair(a.first.first - d, a.first.second - d)], a.second + c[to - 1] - c[i - 1]);
					}
				} else {
					int res = a.second;
					if(a.first.first){
						res += ::a[i] - ::a[i - 1];
					}
					if(a.first.second){
						res += b[i] - b[i - 1];
					}
					upd(ans, upd(dp[i + 1][j][make_pair(max(0, a.first.first - 1), max(0, a.first.second - 1))], res));
				}
			}
		}
	}

	cout << ans << endl;

}