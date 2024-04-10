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

ll a, b, c, d;

bool check(string s){
	ll A = 0, B = 0, C = 0, D = 0;
	int q = 0, w = 0;
	for(int i = 0; i < (int) s.size(); i++){
		if(s[i] == '0'){
			A += q;
			C += w;
			q++;
		}else{
			B += q;
			D += w;
			w++;
		}
	}
	return (A == a && B == b && C == c && D == d);
}

int get(ll w){
	ll f = sqrt(w * 2 + E);
	return f + 1;
}

string solve() {
	ll w = a + b + c + d;
	if (w == 0) {
		return "0";
	}
	// (n + 1) * n / 2 == w
	// (n + 1) * n == w * 2
	ll f = sqrt(w * 2 + E);
	if (f * (f + 1) != w * 2) {
		return "Impossible";
	}
	f++;
	if (w == a) {
		return string(f, '0');
	}
	if (w == d) {
		return string(f, '1');
	}
	char c1 = '0', c2 = '1';
	int a = ::a, b = ::b, c = ::c, d = ::d;
	int g = get(a);
	int h = get(d);
	string ans = "";
	for(int i = g; i >= 1; i--){
		while(c >= i && h){
			ans += '1';
			c -= i;
			h--;
		}
		ans += '0';
	}
	while(h){
		ans += '1';
		h--;
	}
	if(check(ans))
		return ans;
	return "Impossible";
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

	cin >> a >> b >> c >> d;

	cout << solve() << endl;

}