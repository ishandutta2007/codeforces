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

const int MAX_N = 7e4 + 10;
const int MAX_S = 10;
const int MAX_SIZE = MAX_N * MAX_S * (MAX_S - 2);
int to[MAX_SIZE][MAX_S];
int problem[MAX_N][MAX_S][MAX_S];
string s[MAX_N];
int n;

int main() {
	sync;
	srand(time(NULL));
	cout.precision(4);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		for(char &c : s[i]) {
			c -= '0';
		}
	}

	int sz = 0;

	for(int i = 1; i <= n; i++) {
		string s = ::s[i];
		for(int l = 0; l < 9; l++) {
			int now = 0;
			for(int r = l; r < 9; r++) {
				if(!to[now][s[r]]) {
					break;
				}
				now = to[now][s[r]];
				problem[i][l][r] = true;
			}
		}
		for(int l = 0; l < 9; l++) {
			int now = 0;
			for(int r = l; r < 9; r++) {
				if(!to[now][s[r]]) {
					to[now][s[r]] = ++sz;
				}
				now = to[now][s[r]];
			}
		}
	}

	ms(to);

	sz = 0;

	for(int i = n; i; i--) {
		string s = ::s[i];
		for(int l = 0; l < 9; l++) {
			int now = 0;
			for(int r = l; r < 9; r++) {
				if(!to[now][s[r]]) {
					break;
				}
				now = to[now][s[r]];
				problem[i][l][r] = true;
			}
		}
		for(int l = 0; l < 9; l++) {
			int now = 0;
			for(int r = l; r < 9; r++) {
				if(!to[now][s[r]]) {
					to[now][s[r]] = ++sz;
				}
				now = to[now][s[r]];
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		string ans = "";
		for(int len = 0; len < 9 && (int) ans.size() == 0; len++) {
			for(int j = 0; j + len < 9; j++) {
				if(!problem[i][j][j + len]) {
					ans = s[i].substr(j, len + 1);
					break;
				}else{
					//cout << "! " << i << " " << j << " " << j + len << endl;
				}
			}
		}
		for(char &c : ans) {
			c += '0';
		}
		cout << ans << endl;
	}

}