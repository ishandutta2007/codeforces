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

ll dp[11][65][11];
ll dp2[11][65][11];

int used[10];

int prob;

void change(int v) {
	if (used[v]) {
		prob--;
	} else {
		prob++;
	}
	used[v] = !used[v];
}

ll c[100][100];

ll solve(int b, ll r) {
	if (r == 0)
		return 0;
	vector<int> v;
	while (r) {
		v.push_back(r % b);
		r /= b;
	}
	reverse(v.begin(), v.end());
	ll ans = 0;
	for (int i = 1; i < (int) v.size(); i++) {
		ans += dp[b][i][0];
	}
	//cout << "@ " << ans << endl;
	int n = (int) v.size();
	ans += (v[0] - 1) * dp2[b][n - 1][1] / b;
	//cout << "$$ " << ans << endl;
	ms(used);
	prob = 0;
	for (int i = 1; i < n; i++) {
		change(v[i - 1]);
		//cout << "+ " << v[i - 1] << endl;
		for (int j = 0; j < v[i]; j++) {
			change(j);
			//cout << dp[b][n - i - 1][prob] << endl;
			ans += dp2[b][n - i - 1][prob] / c[b][prob];
			change(j);
		}
	}
	ms(used);
	prob = 0;
	for (int a : v) {
		change(a);
	}
	if (prob == 0) {
		ans++;
	}
	return ans;
}

int check(int n, int b) {
	ms(used);
	while (n) {
		used[n % b] = !used[n % b];
		n /= b;
	}
	for (int i = 0; i < b; i++) {
		if (used[i]) {
			return false;
		}
	}
	return true;
}

int solve_long(int b, int l, int r) {
	int ans = 0;
	for (int i = l; i <= r; i++) {
		if (check(i, b)) {
			ans++;
		}
	}
	return ans;
}

ll solve(int b, ll l, ll r) {
	return solve(b, r) - solve(b, l - 1);
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(4);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	c[0][0] = 1;
	for(int i = 1; i < 100; i++) {
		c[i][i] = c[i][0] = 1;
		for(int j = 1; j < i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}

	for(int sz = 2; sz <= 10; sz++) {
		dp[sz][1][1] = sz - 1;
		dp[sz][0][0] = 1;
		for(int i = 1; i < 63; i++) {
			for(int j = 0; j <= sz; j++) {
				if(j) {
					dp[sz][i + 1][j - 1] += dp[sz][i][j] * j;
				}
				if(j < sz) {
					dp[sz][i + 1][j + 1] += dp[sz][i][j] * (sz - j);
				}
			}
		}
	}
	for(int sz = 2; sz <= 10; sz++) {
		dp2[sz][1][1] = sz;
		dp2[sz][0][0] = 1;
		for(int i = 1; i < 63; i++) {
			for(int j = 0; j <= sz; j++) {
				if(j) {
					dp2[sz][i + 1][j - 1] += dp2[sz][i][j] * j;
				}
				if(j < sz) {
					dp2[sz][i + 1][j + 1] += dp2[sz][i][j] * (sz - j);
				}
			}
		}
	}

	int t;
	cin >> t;
	while(t--) {
		int b;
		ll l, r;
		cin >> b >> l >> r;
		cout << solve(b, l, r) << endl;
	}

}