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
//#define DEBUG
#endif
#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 2e5 + 10;

int n, m;

vector<pair<int, ii> > v[MAX];

int ans[MAX];

const int MAX_LOG = 18;
int t[MAX_LOG][MAX], y[MAX_LOG][MAX], h[MAX_LOG][MAX];

bool used[MAX];

int tt[MAX];

int get(int pos) {
	return (tt[pos] == pos ? pos : tt[pos] = get(tt[pos]));
}

int tin[MAX], tout[MAX];

int timer;

int prev_ind[MAX];

void dfs(int pos, int prev = 0) {
	tin[pos] = ++timer;
	t[0][pos] = prev;
	y[0][pos] = 2e9;
	for (int i = 1; i < MAX_LOG; i++) {
		t[i][pos] = t[i - 1][t[i - 1][pos]];
		h[i][pos] = max(h[i - 1][pos], h[i - 1][t[i - 1][pos]]);
		y[i][pos] = 2e9;
	}
	for (pair<int, ii> a : v[pos]) {
		if (a.first != prev) {
			prev_ind[a.first] = a.second.second;
			h[0][a.first] = a.second.first;
			dfs(a.first, pos);
		}
	}
	tout[pos] = ++timer;
}

inline bool upper(int a, int b) {
	return (tin[a] <= tin[b] && tout[b] <= tout[a]);
}

inline int lca(int a, int b) {
	if (upper(a, b))
		return a;
	if (upper(b, a))
		return b;
	for (int i = MAX_LOG - 1; i >= 0; i--) {
		if (t[i][a] && !upper(t[i][a], b)) {
			a = t[i][a];
		}
	}
	return t[0][a];
}

int get_min_to(int a, int b, int val) {
	int ans = 0;
	dbg cout << "$ " << a << " " << b << endl;
	for (int i = MAX_LOG - 1; i >= 0; i--) {
		if (t[i][a] && upper(b, t[i][a])) {
			ans = max(ans, h[i][a]);
		dbg 	cout << i << " " << a << " " << val << " " << h[i][a] << endl;
			y[i][a] = min(y[i][a], val);
			a = t[i][a];
		}
	}
	assert(a == b);
	return ans;
}

int get_min(int a, int b, int val) {
	int c = lca(a, b);
	dbg cout << "@ " << a << " " << b << " " << c << endl;
	return max(get_min_to(a, c, val), get_min_to(b, c, val));
}

inline void upd(int &a, int b) {
	a = min(a, b);
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

	cin >> n >> m;

	vector<iii> v;

	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(make_pair(c, i), make_pair(a, b)));
	}

	sort(v.begin(), v.end());

	for(int i = 1; i <= n; i++) {
		tt[i] = i;
	}

	for(iii p : v) {
		int a = p.second.first;
		int b = p.second.second;
		a = get(a);
		b = get(b);
		if(a != b) {
			tt[a] = b;
			dbg cout << "++++ " << p.second.first << " " << p.second.second << endl;
			used[p.first.second] = true;
			::v[p.second.first].push_back(make_pair(p.second.second, p.first));
			::v[p.second.second].push_back(make_pair(p.second.first, p.first));
		}
	}

	timer = 0;

	dfs(1);

	for(iii p : v) {
		int ind = p.first.second;
		if(!used[ind]) {
			int a = p.second.first;
			int b = p.second.second;
			int c = p.first.first;
			int min_val = get_min(a, b, c);
			ans[ind] = min_val - 1;
			dbg cout << "$$$ " << ind << " " << min_val << endl;
		}
	}

	for(int i = MAX_LOG - 1; i > 0; i--) {
		for(int j = 1; j <= n; j++) {
			upd(y[i - 1][j], y[i][j]);
			upd(y[i - 1][t[i - 1][j]], y[i][j]);
		}
	}

	for(int j = 2; j <= n; j++) {
		int res = y[0][j];
		int ind = prev_ind[j];
		if(res == 2e9) {
			ans[ind] = -1;
		} else {
			ans[ind] = res - 1;
		}
	}

	for(int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}

}