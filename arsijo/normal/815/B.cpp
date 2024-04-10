#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
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
#define prev __prev
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
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int TT = 100;

struct str {
	ll t[TT];
	str() {
		ms(t);
	}
};

str operator+(str a, str b) {
	str ans;
	for (int i = 0; i < TT; i++) {
		ans.t[i] = (a.t[i] + b.t[i]) % MOD;
	}
	return ans;
}

str operator-(str a, str b) {
	str ans;
	for (int i = 0; i < TT; i++) {
		ans.t[i] = (a.t[i] - b.t[i] + MOD) % MOD;
	}
	return ans;
}

str dp[TT][TT];

vector<ll> get_long(int n) {
	for (int i = 1; i <= n; i++) {
		ms(dp[1][i].t);
		dp[1][i].t[i] = 1;
	}
	bool add = true;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; i + j <= n + 1; j++) {
			dp[i][j] = (
					add ? dp[i - 1][j] + dp[i - 1][j + 1] : dp[i - 1][j]
									- dp[i - 1][j + 1]);
			add = !add;
		}
	}
	vector<ll> w;
	for (int i = 1; i <= n; i++) {
		w.push_back(dp[n][1].t[i]);
	}
	return w;
}

const int MAX = 2e5 + 10;

ll fac[MAX], afac[MAX];

ll _pow(ll a, ll b) {
	return (b == 0 ? 1 : b & 1 ? a * _pow(a, b - 1) : sqr(_pow(a, b >> 1)))
			% MOD;
}

ll c(int n, int m) {
	ll ans = fac[n];
	ans = (ans * afac[m]) % MOD;
	ans = (ans * afac[n - m]) % MOD;
	return ans;
}

vector<ll> get_quick(int n) {

	vector<ll> ans;
	if (n % 4 == 1) {
		int m = n / 4;
		m *= 2;
		for (int i = 0; i < n; i++) {
			if (i & 1) {
				ans.push_back(0);
			} else {
				ans.push_back(c(m, i / 2));
			}
		}
	} else if (n % 4 == 2) {
		int m = n / 4;
		m *= 2;
		for (int i = 0; i < n; i++) {
			if (i & 1) {
				ans.push_back(ans.back());
			} else {
				ans.push_back(c(m, i / 2));
			}
		}
	} else if (n % 4 == 3) {
		int m = n / 4;
		m *= 2;
		ans.push_back(1);
		for(int i = 1; i + 1 < n; i++){
			if(i & 1){
				ans.push_back((c(m, i / 2) * 2) % MOD);
			}else{
				ans.push_back(0);
			}
		}
		ans.push_back(MOD - 1);
		ll q = _pow(2, MOD - 2);
		for(int i = 2; i + 2 < n; i += 2){
			ans[i] = ans[i + 1] - ans[i - 1];
			ans[i] += MOD;
			ans[i] %= MOD;
			ans[i] = (q * ans[i]) % MOD;
		}
	} else {
		int m = n / 2 - 1;
		for (int i = 0; i < n; i++) {
			if (i & 1) {
				ans.push_back((MOD - ans.back()) % MOD);
			} else {
				ans.push_back(c(m, i / 2));
			}
		}
	}
	return ans;
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
	fac[0] = fac[1] = 1;
	for(int i = 2; i < MAX; i++) {
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	for(int i = 0; i < MAX; i++) {
		afac[i] = _pow(fac[i], MOD - 2);
	}

	int n;
	cin >> n;

	vector<ll> q = get_quick(n);

	ll ans = 0;
	for(int i = 0; i < n; i++){
		ll a;
		cin >> a;
		ans += a * q[i];
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
	}

	cout << ans << endl;

}