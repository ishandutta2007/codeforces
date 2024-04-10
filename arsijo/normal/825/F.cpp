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

const int MAX = 8e3 + 10;

int pref[MAX], dp[MAX];

string s;

inline void upd(int &a, int b) {
	a = min(a, b);
}

int _log10[MAX];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(4);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	for(int i = 1; i < MAX; i++) {
		_log10[i] = _log10[i / 10] + 1;
	}

	cin >> s;

	int n = (int) s.size();

	for(int i = 1; i <= n; i++) {
		dp[i] = 1e9;
	}

	for(int i = 0; i < n; i++) {
		pref[0] = 0;
		int sz = (int) s.size();
		for(int i = 1; i < sz; i++) {
			int j = pref[i - 1];
			while(j > 0 && s[j] != s[i]) {
				j = pref[j - 1];
			}
			if(s[i] == s[j]) {
				j++;
			}
			pref[i] = j;
		}
		upd(dp[i + 1], dp[i] + 2);
		for(int j = i + 2; j <= n; j++) {
			int sz = j - i;
			int p = pref[j - i - 1];;
			if(p) {
				p = sz - p;
				if(sz % p == 0) {
					upd(dp[j], dp[i] + _log10[sz / p] + p);
				} else {
					upd(dp[j], dp[i] + 1 + sz);
				}
			} else {
				upd(dp[j], dp[i] + 1 + sz);
			}
		}
		s.erase(s.begin());
	}

	cout << dp[n] << endl;

}