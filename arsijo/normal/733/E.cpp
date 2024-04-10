#include <bits/stdc++.h>
using namespace std;
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
const int MAX = 1E6;
char c[MAX];

ll solve_long(int pos) {
	vector<int> l, r;
	for (int i = pos - 1; i >= 0; i--) {
		if (c[i] == 'U') {
			l.push_back(i);
		}
	}
	for (int i = pos + 1; i < n; i++) {
		if (c[i] == 'D') {
			r.push_back(i);
		}
	}
	ll ans = 0;
	for (int i = 0; i < (int) min(l.size(), r.size()); i++) {
		ans += (r[i] - l[i]) * 2;
	}
	if (c[pos] == 'D') {
		if (l.size() > r.size()) {
			ans += pos - l[r.size()] + n - l[r.size()];
		} else {
			ans += pos + 1;
		}
	} else {
		if (r.size() > l.size()) {
			ans += r[l.size()] - pos + r[l.size()] + 1;
		} else {
			ans += n - pos;
		}
	}
	return ans;
}

void solve_long() {
	for (int i = 0; i < n; i++)
		cout << solve_long(i) << " ";
	cout << endl;
}

ll anses[MAX];
int pref[MAX], suff[MAX];

struct fenwick_tree {
	ll *t;
	int n;
	fenwick_tree(int n) {
		t = new ll[n];
		this->n = n;
		for (int i = 0; i < n; i++)
			t[i] = 0;
	}
	inline void upd(int pos, int val) {
		for (int i = pos; i < n; i |= (i + 1))
			t[i] += val;
	}
	inline ll sum(int pos) {
		ll ans = 0;
		for (int i = pos; i >= 0; i &= (i + 1), i--)
			ans += t[i];
		return ans;
	}
	inline ll sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};

void solve_ok() {
	for (int i = 0; i < n; i++) {
		pref[i] = (i == 0 ? 0 : pref[i - 1]) + (c[i] == 'U');
	}
	for (int i = n - 1; i >= 0; i--) {
		suff[i] = (i == n - 1 ? 0 : suff[i + 1]) + (c[i] == 'D');
	}
	vector<int> v;
	int l_size, r_size, size;
	fenwick_tree tree1(n);
	for (int i = 0; i < n; i++) {
		l_size = (i == 0 ? 0 : pref[i - 1]);
		r_size = (i == n - 1 ? 0 : suff[i + 1]);
		size = min(l_size, r_size);
		if (size) {
			anses[i] -= 2 * tree1.sum(v[v.size() - size], i);
		}

		if (c[i] == 'D') {
			if (l_size > r_size) {
				anses[i] += i + n - v[l_size - r_size - 1] * 2;
			} else {
				anses[i] += i + 1;
			}
		} else {
			v.push_back(i);
			tree1.upd(i, i);
		}
	}
	v.clear();
	fenwick_tree tree2(n);
	for (int i = n - 1; i >= 0; i--) {
		l_size = (i == 0 ? 0 : pref[i - 1]);
		r_size = (i == n - 1 ? 0 : suff[i + 1]);
		size = min(l_size, r_size);
		if (size) {
			anses[i] += 2 * tree2.sum(i, v[v.size() - size]);
		}
		if (c[i] == 'U') {
			if (l_size < r_size) {
				anses[i] += v[r_size - l_size - 1] * 2 + 1 - i;
			} else {
				anses[i] += n - i;
			}
		} else {
			v.push_back(i);
			tree2.upd(i, i);
		}
	}
	for (int i = 0; i < n; i++){
		if(i)
			putchar(' ');
		write(anses[i]);
	}
	putchar('\n');
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

	read(n);
	for(int i = 0; i < n; i++)
	c[i] = getchar();
	//solve_long();
	solve_ok();

}