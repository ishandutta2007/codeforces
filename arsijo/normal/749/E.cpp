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

ll sum(ll n) {
	return n * (n + 1) / 2;
}

ld get(int n) {
	return (ld) sum((ll) n - 1) / 2;
}

struct segment_tree {

};

struct fenwick_tree {
	ll *t, n;
	fenwick_tree(int n) {
		t = new ll[n];
		for (int i = 0; i < n; i++) {
			t[i] = 0;
		}
		this->n = n;
	}
	void clear() {
		for (int i = 0; i < n; i++) {
			t[i] = 0;
		}
	}
	void add(int pos, ll val) {
		for (int i = pos; i < n; i |= (i + 1)) {
			t[i] += val;
		}
	}
	ll sum(int pos) {
		ll ans = 0;
		for (int i = pos; i >= 0; i &= (i + 1), i--) {
			ans += t[i];
		}
		return ans;
	}
};

int n;

ld t(int d) {
	return (ld) sum(d) / (ld) sum(n);
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
	//output;
#else

#endif

	cin >> n;

	ld ans = 0;
	ll s = (n * 1LL * (n + 1)) / 2;
	for(int i = 1; i <= n; i++) {
		ans += (ld) get(i) * ((ld) ((ld) n - i + 1) / s);
	}

	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		v[i]--;
	}
	fenwick_tree tree(n);
	for(int i = n - 1; i >= 0; i--) {
		ans += t(n - i - 1) * (ld) tree.sum(v[i]);
		tree.add(v[i], 1);
	}
	tree.clear();
	for(int i = 0; i < n; i++) {
		ans += t(i) * ((ld) i - tree.sum(v[i]));
		tree.add(v[i], 1);
	}

	tree.clear();
	fenwick_tree tree2(n);
	fenwick_tree tree3(n);
	for(int i = n - 1; i >= 0; i--) {
		ld r = tree.sum(v[i]);
		ld r2 = tree2.sum(v[i]);
		ld s = tree3.sum(v[i]);
		if(s) {
			ld j = i + 1;
			//cout << r2 << " " << 2 * j * r << " " << sqr((ll) j) * s << " " << r << " " << j * s << endl;
			ld a = r2 - 2 * j * 1LL * r + sqr(j) * s + r - j * 1LL * s;
			a /= (ld) 2;
			//cout << a << " " << s << " " << (a / (ld) (s * sum(n))) << endl;
			ans -= a / ((ld) (sum(n)));
			//cout << a << " " << tree.sum(v[i]) << " " << tree2.sum(v[i]) << endl;
			//ans -= (ld) a / sum(n);
		}
		if(i + 1 < n) {
			tree3.add(v[i + 1], 1);
			tree2.add(v[i + 1], sqr((ll) i + 1));
			tree.add(v[i + 1], i + 1);
		}
	}
	cout << ans << endl;

}