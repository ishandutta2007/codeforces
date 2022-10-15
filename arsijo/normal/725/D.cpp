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

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n;
	cin >> n;

	ll a, b;
	cin >> a >> b;

	multiset<ll> v1;
	multiset<pair<ll, ll> >v2;

	for(int i = 1; i < n; i++) {
		ll t, w;
		cin >> t >> w;
		if(t <= a) {
			v2.insert(make_pair(t, w - t + 1));
		} else {
			v1.insert(w - t + 1);
		}
	}

	int ans = (int) v1.size() + 1;
	int res = ans;
	while(!v1.empty() && a >= *v1.begin()) {
		a -= *v1.begin();
		v1.erase(v1.begin());
		res--;
		while(!v2.empty() && v2.rbegin()->first > a){
			v1.insert(v2.rbegin()->second);
			v2.erase(v2.find(*v2.rbegin()));
			res++;
		}
		ans = min(ans, res);
	}

	cout << ans << endl;

}