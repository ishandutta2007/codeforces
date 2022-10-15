#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
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
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
char ccc;
bool _minus = false;
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
char wr[12];
int k;
inline void write(int x) {
	k = 0;
	if (!x)
		++k, wr[k] = '0';
	while (x) {
		++k;
		wr[k] = char(x % 10 + '0');
		x /= 10;
	}
	for (int i = k; i >= 1; --i)
		putchar(wr[i]);
	putchar('\n');
}
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

int main() {

	sync;
	srand(time(NULL));
	cout.precision(0);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	int n, m, k;
	cin >> n >> m >> k;

	int ar[n + 1];
	for(int i = 1; i <= n; i++)
		cin >> ar[i];

	int t[m + 2];
	ms(t);

	int a[m + 1], b[m + 1], c[m + 1];
	for(int i = 1; i <= m; i++)
		cin >> a[i] >> b[i] >> c[i];

	for(int i = 1; i <= k; i++){
		int a, b;
		cin >> a >> b;
		t[a]++, t[b + 1]--;
	}

	ll g[n + 2];
	ms(g);

	ll e = 0;
	for(int i = 1; i <= m; i++){
		e += t[i];
		g[a[i]] += e * c[i];
		g[b[i] + 1] -= e * c[i];
	}

	ll q = 0;

	for(int i = 1; i <= n; i++){
		q += g[i];
		cout << ar[i] + q << " ";
	}

}