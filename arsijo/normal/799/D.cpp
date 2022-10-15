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

int a, b, h, w, n;

int ans = INT_MAX;

vector<ii> vec;

ll get(ll a, ll b, int c, ll d) {
	for (int i = 0; i < c; i++) {
		a = min(d, a * b);
	}
	return a;
}

int need(ll a, ll b, ll d) {
	int ans = 0;
	while (a < d) {
		a *= b;
		ans++;
	}
	return ans;
}

inline void upd(int &a, int b) {
	a = min(a, b);
}

void dfs(int pos, ll h, ll w, int used) {
	if (a <= h && b <= w) {
		ans = min(ans, used);
		return;
	}
	if ((int) vec.size() == pos || used >= ans)
		return;
	if (a <= h) {
		if (need(w, vec[pos].first, b) <= vec[pos].second) {
			upd(ans, used + need(w, vec[pos].first, b));
		} else {
			dfs(pos + 1, h, get(w, vec[pos].first, vec[pos].second, b),
					used + vec[pos].second);
		}
		return;
	}
	if (b <= w) {
		if (need(h, vec[pos].first, a) <= vec[pos].second) {
			upd(ans, used + need(h, vec[pos].first, a));
		} else {
			dfs(pos + 1, get(h, vec[pos].first, vec[pos].second, a), w,
					used + vec[pos].second);
		}
		return;
	}
	for (int i = 0; i <= (int) vec[pos].second; i++) {
		if (get(h, vec[pos].first, i, a) == a
				&& get(w, vec[pos].first, vec[pos].second - i, b) == b) {
			upd(ans,
					used + need(h, vec[pos].first, a)
							+ need(w, vec[pos].first, b));
		} else {
			dfs(pos + 1, get(h, vec[pos].first, i, a), get(w, vec[pos].first, vec[pos].second - i, b), used + vec[pos].second);
		}
	}
}

void solve() {
	if (a <= h && b <= w) {
		ans = 0;
		return;
	}
	dfs(0, h, w, 0);
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

	cin >> a >> b >> h >> w >> n;
	ans = INT_MAX;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.rbegin(), v.rend());
	ll ans = 1;
	ld t = 0;
	for(int i = 0; i < (int) v.size() && t <= 15; i++) {
		ans *= v[i];
		t += log10(v[i]);
		if(!vec.empty() && vec.back().first == v[i]) {
			vec.back().second++;
		} else {
			vec.push_back(make_pair(v[i], 1));
		}
	}

	solve();
	swap(a, b);
	solve();

	if(::ans == INT_MAX)
		::ans = -1;
	cout << ::ans << endl;

}