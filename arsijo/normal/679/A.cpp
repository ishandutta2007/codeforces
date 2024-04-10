#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-5;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
//#define endl "\n"
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

int M;

bool prime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
int Q = 0;
int get(int n){
	cout << n << "\n";
	string s;
	cin >> s;
	return s[0] == 'y';
}

int solve() {
	Q = 0;
	int res = -1;
	for (int i = 2; i <= 10; i++) {
		if (prime(i)) {
			if (get(i)) {
				res = i;
				break;
			}
		}
	}
	if(res == -1){
		return 0;
	}
	for (int i = res; i * res <= 100; i++) {
		if (prime(i)) {
			if (get(i * res)) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {

#ifdef LOCAL
	//input;
	//output;
#else

#endif

	cout << (solve() ? "composite" : "prime") << endl;

}