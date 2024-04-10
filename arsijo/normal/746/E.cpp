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

const int MAX = 2e5;
int ar[MAX];
int n, m;

set<int> e;
int f, s;

void no() {
	cout << -1 << endl;
	exit(0);
}

int get_1() {
	while (e.find(f) != e.end())
		f += 2;
	if (f > m) {
		no();
	}
	e.insert(f);
	return f;
}
int get_2() {
	while (e.find(s) != e.end())
		s += 2;
	if (s > m) {
		no();
	}
	e.insert(s);
	return s;
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
	f = 1, s = 2;
	cin >> n >> m;
	int ans = 0;
	int a = 0;
	int b = 0;
	for(int i = 0; i < n; i++) {
		cin >> ar[i];
		e.insert(ar[i]);
		if(ar[i] & 1) {
			a++;
		} else {
			b++;
		}
	}

	set<int> s;

	for(int i = 0; i < n; i++) {
		if(s.find(ar[i]) != s.end()) {
			ans++;
			if(ar[i] & 1) {
				if(b < a) {
					ar[i] = get_2();
					b++, a--;
				} else {
					ar[i] = get_1();
				}
			} else {
				if(a < b) {
					ar[i] = get_1();
					b--, a++;
				} else {
					ar[i] = get_2();
				}
			}
		}else{
			s.insert(ar[i]);
		}
	}

	for(int i = 0; i < n; i++){
		if(ar[i] & 1){
			if(b < a){
				ans++;
				ar[i] = get_2();
				b++, a--;
			}
		}else {
			if(a < b){
				ans++;
				ar[i] = get_1();
				a++, b--;
			}
		}
	}

	cout << ans << endl;
	for(int i = 0; i < n; i++){
		cout << ar[i] << " ";
	}

}