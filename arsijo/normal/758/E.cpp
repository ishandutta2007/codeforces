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
ll MOD = 1e9 + 7;
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
#define remove tipa_remove
#define next tipa_next
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

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n;
const int MAX = 2e5 + 10;
vector<ii> vec[MAX];
ll a[MAX], b[MAX], c[MAX], d[MAX];
ll r[MAX];
ll dp[MAX];

void dfs1(int pos, int prev = -1) {
	dp[pos] = 0;
	for (ii a : vec[pos]) {
		if (a.first == prev)
			continue;
		dfs1(a.first, pos);
		int ind = a.second;
		if (d[ind] < dp[a.first]) {
			cout << -1 << endl;
			exit(0);
		}
		ll remove = min(d[ind] - dp[a.first], (ll) c[ind] - 1);
		c[ind] -= remove;
		d[ind] -= remove;
		r[ind] = remove;
		dp[pos] += dp[a.first] + c[ind];
	}
}

void dfs2(int pos, int prev = -1, ll can_add = 0) {
	assert(can_add >= 0);
	ll max_val = dp[pos] + can_add;
	for (ii a : vec[pos]) {
		if (a.first == prev)
			continue;
		int ind = a.second;
		int to = a.first;
		ll w = min((ll) 1e9 - c[ind], min(r[ind], max_val - dp[pos]));
		c[ind] += w, d[ind] += w;
		dp[pos] += w;
		ll g = dp[to];
		dfs2(to, pos, min(max_val - dp[pos], d[ind] - dp[to]));
		assert(g <= dp[to]);
		dp[pos] -= g;
		dp[pos] += dp[to];
	}
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
	for(int i = 1; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		vec[a[i]].push_back(make_pair(b[i], i));
		vec[b[i]].push_back(make_pair(a[i], i));
	}

	dfs1(1);
	dfs2(1, -1, 1e16);
	cout << n << endl;
	for(int i = 1; i < n; i++) {
		cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endl;
	}

}