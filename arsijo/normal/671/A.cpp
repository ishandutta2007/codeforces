#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef short int si;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-9;
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
#define y1 hello_world
unsigned char ccc;
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
char wwww[12];
int kkkk;
inline void write(int x) {
	kkkk = 0;
	if (!x)
		++kkkk, wwww[kkkk] = '0';
	while (x) {
		++kkkk;
		wwww[kkkk] = char(x % 10 + '0');
		x /= 10;
	}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar('\n');
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

#define x first
#define y second

inline ld dist(ii a, ii b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

const int MAX = 2e5;

ii ar[MAX];

ld pref[MAX], suff[MAX], cost[MAX], pref2[MAX], suff2[MAX];

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	ii a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> ar[i].first >> ar[i].second;
		cost[i] = dist(ar[i], c);
	}

	ld ans = LONG_LONG_MAX;

	for(int q = 0; q < 2; q++) {

		ld sum = 0;

		pref[0] = 1e18;

		for(int i = 1; i <= n; i++) {
			pref[i] = min(pref[i - 1] + cost[i] * 2, pref2[i - 1] + cost[i] + dist(a, ar[i]));
			sum += cost[i] * 2;
			pref2[i] = sum;
		}
		for(int i = n; i >= 1; i--){
			suff[i] = suff[i + 1] + cost[i] * 2;
		}
		ans = min(ans, pref[n]);

		for(int i = 1; i <= n; i++){
			ans = min(ans, pref[i - 1] + suff[i + 1] + dist(b, ar[i]) + cost[i]);
		}

		swap(a, b);
	}

	cout << ans << endl;

}