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
#define M_PI acos(-1)
#define remove tipa_remove
#define next tipa_next
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
inline ld sqr(ld t) {
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
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 1e5 + 10;

int x[MAX], r[MAX], f[MAX];

const int MAX_T = 12e5;

int ar[MAX * 3];

struct fenwick_tree {
	int *t, n;
	fenwick_tree(int n) {
		t = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = 0;
		}
		this->n = n;
	}
	void add(int pos, int val) {
		for (int i = pos; i < n; i |= (i + 1)) {
			t[i] += val;
		}
	}
	int sum(int pos) {
		int ans = 0;
		for (int i = pos; i >= 0; i &= (i + 1), i--) {
			ans += t[i];
		}
		return ans;
	}
};

vector<int> vec[MAX_T];
fenwick_tree *trees[MAX_T];

void build(int v, int l, int r) {
	if (l == r) {
		trees[v] = new fenwick_tree(1);
		vec[v].push_back(ar[l]);
		return;
	}
	int x = (l + r) >> 1;
	build(v << 1, l, x);
	build(v << 1 | 1, x + 1, r);
	vec[v].resize(r - l + 1);
	merge(vec[v << 1].begin(), vec[v << 1].end(), vec[v << 1 | 1].begin(),
			vec[v << 1 | 1].end(), vec[v].begin());
	trees[v] = new fenwick_tree((int) vec[v].size());
}

int get(int v, int tl, int tr, int l, int r, int val) {
	if (l <= tl && tr <= r) {
		if (vec[v].back() <= val) {
			return trees[v]->sum((int) vec[v].size() - 1);
		}
		l = 0, r = (int) vec[v].size() - 1;
		while (l < r) {
			int x = (l + r) >> 1;
			if (vec[v][x] <= val) {
				l = x + 1;
			} else {
				r = x;
			}
		}
		return trees[v]->sum(l - 1);
	}
	if (tr < l || r < tl) {
		return 0;
	}
	int x = (tl + tr) >> 1;
	return get(v << 1, tl, x, l, r, val) + get(v << 1 | 1, x + 1, tr, l, r, val);
}

void upd(int v, int tl, int tr, int pos, int val) {
	int l = 0, r = (int) vec[v].size() - 1;
	while (l < r) {
		int x = (l + r) >> 1;
		if (vec[v][x] < val) {
			l = x + 1;
		} else {
			r = x;
		}
	}
	trees[v]->add(l, 1);
	if (tl == tr) {
		return;
	}
	int x = (tl + tr) >> 1;
	if (pos <= x) {
		upd(v << 1, tl, x, pos, val);
	} else {
		upd(v << 1 | 1, x + 1, tr, pos, val);
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

	int n, k;
	read(n);
	read(k);
	set<int> s;
	for(int i = 1; i <= n; i++) {
		read(x[i]);
		read(r[i]);
		read(f[i]);
		s.insert(x[i]);
		s.insert(x[i] - r[i]);
		s.insert(x[i] + r[i]);
	}

	map<int, int> m;
	int sz = 0;
	for(int a : s) {
		m[a] = sz++;
	}

	for(int i = 0; i < sz; i++) {
		ar[i] = -1e9;
	}
	for(int i = 1; i <= n; i++) {
		ar[m[x[i]]] = f[i];
	}

	build(1, 0, sz - 1);

	vector<pair<int, ii> > v;
	for(int i = 1; i <= n; i++) {
		v.push_back(make_pair(r[i], make_pair(x[i], f[i])));
	}
	sort(v.rbegin(), v.rend());
	ll ans = 0;
	for(pair<int, ii> a : v) {
		int x = a.second.first;
		int r = a.first;
		int f = a.second.second;
		ans += get(1, 0, sz - 1, m[x - r], m[x + r], f + k) - get(1, 0, sz - 1, m[x - r], m[x + r], f - k - 1);
		upd(1, 0, sz - 1, m[x], f);
	}

	cout << ans << endl;

}