#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
const int MOD = 1e9 + 7;
const ld E = 1e-8;
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

int n, m, k;

void get(int ind, int &a, int &b) {
	int q = 0;
	for (int i = 1; i <= n; i++) {
		q += m * k;
		if (ind <= q) {
			a = i;
			break;
		}
	}
	q = (a - 1) * m * k;
	for (int i = 1; i <= m; i++) {
		q += k;
		if (ind <= q) {
			b = i;
			break;
		}
	}
}

ll get(ll t) {
	t--;
	return min(t * 5LL, 10LL + 1LL * t);
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

	cin >> n >> m >> k;
	int a, b;
	cin >> a >> b;
	int c1, d1, c2, d2;
	get(a, c1, d1);
	get(b, c2, d2);
	if(c1 > c2)
	swap(c1, c2);
	ll ans1 = min(c2 - c1, n - (c2 - c1));
	ans1 *= 15LL;
	ll ans2;
	if(ans1 == 0) {
		ans2 = get(abs(d2 - d1) + 1);
	} else {
		ans2 = get(d2) + get(d1);
	}
	cout << ans1 + ans2 << endl;
}