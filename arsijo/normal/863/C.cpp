#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
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

int a[4][4], b[4][4];

int dp[4][4];

pair<ll, ll> dp2[4][4];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(4);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	ll k;
	int x, y;
	cin >> k >> x >> y;

	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}

	for(int i = 1; i <= 3; i++) {
		for(int j = 1; j <= 3; j++) {
			cin >> b[i][j];
		}
	}

	bool w = false;

	ll ans1 = 0, ans2 = 0;

	for(ll i = 1; i <= k; i++) {
		if(!w && dp[x][y]) {
			w = true;
			ll w = (k - i) / (i - dp[x][y]);
			w = max(0LL, w - 2);
			if(w) {
				ans1 += (ans1 - dp2[x][y].first) * w;
				ans2 += (ans2 - dp2[x][y].second) * w;
				i += w * (i - dp[x][y]);
			}
		}
		dp2[x][y] = make_pair(ans1, ans2);
		dp[x][y] = i;
		if(x != y) {
			if(abs(x - y) == 1) {
				if(max(x, y) == x) {
					ans1++;
				} else {
					ans2++;
				}
			} else {
				if(x == 1) {
					ans1++;
				} else {
					ans2++;
				}
			}
		}
		int x1 = a[x][y], y1 = b[x][y];
		x = x1, y = y1;

	}

	cout << ans1 << " " << ans2 << endl;

}