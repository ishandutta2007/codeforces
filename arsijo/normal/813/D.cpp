#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-9;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".DAT"); _write(x ".SOL")
#define output _write("output.txt")
#define input _read("input.txt")
#define prev time_prev
#ifndef M_PI
#define M_PI acos(-1)
#endif
#define remove tipa_remove
#define next tipa_next
#define left tipa_left
#define right tipa_right
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
inline bool read(int &n) {
	n = 0;
	_minus = false;
	while (true) {
		ccc = getchar();
		if (ccc == ' ' || ccc == '\n') {
			if (ccc == '\n')
				return true;
			break;
		}
		if (ccc == '-') {
			_minus = true;
			continue;
		}
		n = n * 10 + ccc - '0';
	}
	if (_minus)
		n *= -1;
	return false;
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
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 5e3 + 10;

int t[MAX][7];

int n;

int ar[MAX];

int n1[MAX], n2[MAX];

int dp1[MAX];

int dp2[MAX][MAX];

inline void upd(int &a, int b) {
	a = max(a, b);
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

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> ar[i];
	}

	for(int i = n; i; i--) {
		for(int j = 0; j < 7; j++) {
			t[i][j] = t[i + 1][j];
		}
		t[i][ar[i] % 7] = i;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(n1[i] == 0 && ar[i] - ar[j] == 1) {
				n1[i] = j;
			}
			if(n2[i] == 0 && ar[j] - ar[i] == 1) {
				n2[i] = j;
			}
		}
	}

	int ans = 0;

	for(int i = 1; i <= n; i++) {
		upd(dp1[i], 1);
		upd(dp1[t[i + 1][ar[i] % 7]], dp1[i] + 1);
		upd(dp1[n1[i]], dp1[i] + 1);
		upd(dp1[n2[i]], dp1[i] + 1);

	}

	dp1[0] = 0;

	for(int i = 1; i <= n; i++) {
		int p1 = i + 1, p2 = i + 1;
		for(int j = i + 1; j <= n; j++) {
			while(p1 <= n && (p1 == j || ar[p1] - ar[i] != 1)) {
				p1++;
			}
			while(p2 <= n && (p2 == j || ar[i] - ar[p2] != 1)) {
				p2++;
			}
			int res = max(dp1[i] + 1, dp2[i][j]);
			upd(ans, res);
			if(n1[j]) {
				upd(dp2[i][n1[j]], res + 1);
			}
			if(n2[j]) {
				upd(dp2[i][n2[j]], res + 1);
			}
			if(p1 <= n) {
				upd(dp2[j][p1], res + 1);
			}
			if(p2 <= n) {
				upd(dp2[j][p2], res + 1);
			}
			int w = t[j + 1][ar[i] % 7];
			if(w) {
				upd(dp2[j][w], res + 1);
			}
			w = t[j + 1][ar[j] % 7];
			if(w) {
				upd(dp2[i][w], res + 1);
			}
		}
	}

	cout << ans << endl;

}