#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
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
	putchar(' ');
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

const int MAX = 1e6 + 1;
int a[MAX], b[MAX], n, m, c[MAX];

inline bool in(int l, int r, int x){
	if(l <= r)
		return l <= x && x <= r;
	return x <= r || l <= x;
}

inline int get(int i){
	return i > n ? i - n : i;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(15);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	read(n);
	read(m);

	for(int i = 1; i <= n; i++)
		read(a[i]);
	for(int i = 1; i <= m; i++)
		read(b[i]);

	for(int i = 1; i <= m; i++){
		assert(c[b[i]] == 0);
		c[b[i]] = i;
	}

	int ans = 0;

	for(int l = 1, r = 1; l <= n; l++){
		r = max(r, l);
		if(c[a[l]] == 0){
			continue;
		}
		while(r - l + 1 < n){
			if(c[a[get(r + 1)]] && !in(c[a[l]], c[a[get(r)]], c[a[get(r + 1)]])){
				r++;
			}else{
				break;
			}
		}
		ans = max(ans, r - l + 1);
	}

	cout << ans << endl;

}