#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-12;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef M_PI
#define M_PI 3.141592653589793238462643383
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

const int MAX = 1e5 + 10;

int ar[MAX];
int t1[MAX << 2];

void build1(int v, int l, int r) {
	if (l == r) {
		t1[v] = ar[l];
		return;
	}
	int x = (l + r) >> 1;
	build1(v << 1, l, x);
	build1(v << 1 | 1, x + 1, r);
	t1[v] = min(t1[v << 1], t1[v << 1 | 1]);
}

int n, k;

struct segment_tree {
private:
	unordered_map<int, int> t, y;
	inline void push(int v) {
		if (y[v]) {
			t[v << 1] = t[v << 1 | 1] = y[v << 1] = y[v << 1 | 1] = y[v];
			y[v] = 0;
		}
	}
	int upd(int v, int tl, int tr, int l, int r, int val) {
		if (l <= tl && tr <= r) {
			t[v] = val;
			y[v] = val;
			return val;
		}
		if (tr < l || r < tl)
			return (t[v] == 0 ? t1[v] : t[v]);
		push(v);
		int x = (tl + tr) >> 1;
		return t[v] = min(upd(v << 1, tl, x, l, r, val),
				upd(v << 1 | 1, x + 1, tr, l, r, val));
	}
	int get(int v, int tl, int tr, int l, int r) {
		if (l <= tl && tr <= r) {
			return (t[v] == 0 ? t1[v] : t[v]);
		}
		if (tr < l || r < tl)
			return INT_MAX;
		push(v);
		int x = (tl + tr) >> 1;
		return min(get(v << 1, tl, x, l, r), get(v << 1 | 1, x + 1, tr, l, r));
	}
public:
	void upd(int l, int r, int val) {
		upd(1, 1, n, l, r, val);
	}
	int get(int l, int r) {
		return get(1, 1, n, l, r);
	}
} st[MAX];

int t2[MAX], y2[MAX];

void build2(int v, int l, int r) {
	if (l == r) {
		t2[v] = st[l].get(1, n);
		return;
	}
	int x = (l + r) >> 1;
	build2(v << 1, l, x);
	build2(v << 1 | 1, x + 1, r);
	t2[v] = min(t2[v << 1], t2[v << 1 | 1]);
}

inline void push(int v) {
	if (y2[v]) {
		t2[v << 1] = t2[v << 1 | 1] = y2[v << 1] = y2[v << 1 | 1] = y2[v];
		y2[v] = 0;
	}
}

void upd(int v, int tl, int tr, int l, int r, int val) {
	if (l <= tl && tr <= r) {
		t2[v] = y2[v] = val;
		return;
	}
	if (tr < l || r < tl)
		return;
	push(v);
	int x = (tl + tr) >> 1;
	upd(v << 1, tl, x, l, r, val);
	upd(v << 1 | 1, x + 1, tr, l, r, val);
	t2[v] = min(t2[v << 1], t2[v << 1 | 1]);
}

int get(int v, int tl, int tr, int l, int r) {
	if (l <= tl && tr <= r) {
		return t2[v];
	}
	if (tr < l || r < tl)
		return INT_MAX;
	push(v);
	int x = (tl + tr) >> 1;
	return min(get(v << 1, tl, x, l, r), get(v << 1 | 1, x + 1, tr, l, r));
}

void upd2(int v, int tl, int tr, int pos, int l, int r, int val) {
	if (tl == tr) {
		if (y2[v])
			st[tl].upd(1, n, y2[v]);
		y2[v] = 0;
		st[tl].upd(l, r, val);
		t2[v] = st[tl].get(1, n);
		return;
	}
	int x = (tl + tr) >> 1;
	push(v);
	if (pos <= x)
		upd2(v << 1, tl, x, pos, l, r, val);
	else
		upd2(v << 1 | 1, x + 1, tr, pos, l, r, val);
	t2[v] = min(t2[v << 1], t2[v << 1 | 1]);
}

int get2(int v, int tl, int tr, int pos, int l, int r) {
	if (tl == tr) {
		if (y2[v])
			st[tl].upd(1, n, y2[v]);
		y2[v] = 0;
		return st[tl].get(l, r);
	}
	int x = (tl + tr) >> 1;
	push(v);
	return (pos <= x ?
			get2(v << 1, tl, x, pos, l, r) :
			get2(v << 1 | 1, x + 1, tr, pos, l, r));
}

inline int get_block(ll x) {
	return (x - 1) / n + 1;
}

inline int get_pos_in_block(ll x) {
	return x - (get_block(x) - 1) * n;
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(12);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	cin >> n >> k;

	for(int i = 1; i <= n; i++) {
		cin >> ar[i];
	}

	build1(1, 1, n);
	build2(1, 1, k);

	int q;
	cin >> q;

	while(q--) {
		int t;
		ll l, r;
		cin >> t >> l >> r;
		int l1 = get_block(l);
		int r1 = get_block(r);
		int L1 = get_pos_in_block(l);
		int R1 = get_pos_in_block(r);
		if(t == 1) {
			int x;
			cin >> x;
			if(l1 == r1) {
				upd2(1, 1, k, l1, L1, R1, x);
			} else {
				upd2(1, 1, k, l1, L1, n, x);
				upd2(1, 1, k, r1, 1, R1, x);
				if(l1 + 1 < r1) {
					upd(1, 1, k, l1 + 1, r1 - 1, x);
				}
			}
		} else {
			int ans = INT_MAX;
			if(l1 == r1) {
				ans = get2(1, 1, k, l1, L1, R1);
			} else {
				ans = min(ans, get2(1, 1, k, l1, L1, n));
				ans = min(ans, get2(1, 1, k, r1, 1, R1));
				if(l1 + 1 < r1) {
					ans = min(ans, get(1, 1, k, l1 + 1, r1 - 1));
				}
			}
			cout << ans << endl;
		}
	}

}