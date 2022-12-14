#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
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
	putchar(' ');
}

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int get_bits(ll a){
	int ans = 0;
	while(a){
		a >>= 1;
		ans++;
	}
	return ans - 1;
}

map<ll, ll> m;

bool get_bit(ll a, int bit){
	return (a & (1LL << bit)) != 0;
}

ll get_lca(ll a, ll b){
	int n = get_bits(a);
	int m = get_bits(b);
	ll ans = 0;
	for(int i = 0; i <= min(n, m); i++){
		if(get_bit(a, n - i) == get_bit(b, m - i)){
			ans <<= 1;
			ans |= get_bit(a, n - i);
		}else{
			break;
		}
	}
	return ans;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(5);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	int q;
	cin >> q;
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			ll a, b, w;
			cin >> a >> b >> w;
			ll c = get_lca(a, b);
			while(a != c){
				m[a] += w;
				a >>= 1;
			}
			while(b != c){
				m[b] += w;
				b >>= 1;
			}
		}else{
			ll a, b;
			cin >> a >> b;
			ll ans = 0;
			ll c = get_lca(a, b);
			while(a != c){
				ans += m[a];
				a >>= 1;
			}
			while(b != c){
				ans += m[b];
				b >>= 1;
			}
			cout << ans << endl;
		}
	}

}