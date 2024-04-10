#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-13;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 1003;

int last[MAX], next[MAX], to[MAX], an[MAX], sz = 0;
ll val[MAX];

void clear() {
	ms(last);
	sz = 0;
}

void add(int a, int b, ll c, int pr) {
	++sz;
	next[sz] = last[a];
	last[a] = sz;
	to[sz] = b;
	val[sz] = c;
	an[sz] = pr;
}

void add(int a, int b, ll c) {
	add(a, b, c, sz + 2);
	add(b, a, 0, sz);
}

int t;
bool used[MAX];

ll make(int pos, ll val) {
	if (pos == t) {
		return val;
	}
	used[pos] = true;
	for (int i = last[pos]; i; i = next[i]) {
		int to = ::to[i];
		if (!used[to] && ::val[i]) {
			ll q = make(to, min(val, ::val[i]));
			if (q) {
				::val[i] -= q;
				::val[an[i]] += q;
				return q;
			}
		}
	}
	return 0;
}

ll solve() {
	ll ans = 0;
	ll t;
	do {
		ms(used);
		ans += t = make(1, INT_MAX);
	} while (t);
	return ans;
}

ll get(ld a, ld b){
	ld ans = a / b;
	return (ll) ans;
}

int main() {

	sync;
	cout.precision(12);
	cout << fixed;
	srand(time(NULL));

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int n, m, w;
	cin >> n >> m >> w;
	t = n;
	int a[m], b[m], c[m];
	for(int i = 0; i < m; i++)
	cin >> a[i] >> b[i] >> c[i];
	ld l = 0, r = 1e6;
	while(l + E < r) {
		ld x = (l + r) / 2;
		clear();
		for(int i = 0; i < m; i++)
		add(a[i], b[i], get(c[i], x));
		if(w <= solve())
		l = x;
		else
		r = x;
	}

	cout << l * w;

}