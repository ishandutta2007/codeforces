#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-7;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
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
	putchar('\n');
}

#ifdef LOCAL
//#define DEBUG
#endif

bool is_sqr(ll n){
	ll a = sqrt(n) + E;
	return a * a == n && n > 0;
}

bool check(ll n){
	if(n & 1){
		ll e = sqr(n) / 2;
		cout << e << " ? " << is_sqr(sqr(e) + sqr(n)) << endl;
	}
	for(ll i = 2; i <= sqr(n); i += 2){
		if(is_sqr(sqr(n) + sqr(i))){
			cout << n << " " << i << endl;
			return true;
		}
	}
	for(ll i = 1; i < n; i++){
		if(is_sqr(sqr(n) - sqr(i)))
			return true;
	}
	return false;
}

// 4 * a * a + 4 * b * b == c * c
// 4 * (a * a + b * b) == c * c

pair<ll, ll> solve(ll n){
	if(n & 1){
		ll e = sqr(n) / 2;
		return make_pair(e, e + 1);
	}
	pair<ll, ll> ans = solve(n / 2);
	ans.first *= 2;
	ans.second *= 2;
	return ans;
}

void _solve(ll n){
	if(n <= 2){
		cout << -1 << endl;
		return;
	}
	if((n & (n - 1)) == 0){
		cout << n / 4 * 3 << " " << n / 4 * 5 << endl;
		return;
	}
	pair<ll, ll> ans = solve(n);
	cout << ans.first << " " << ans.second << endl;
}

int main() {
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
	sync;
#ifdef LOCAL
	input;
#else

#endif

	ll n;
	cin >> n;
	_solve(n);

}