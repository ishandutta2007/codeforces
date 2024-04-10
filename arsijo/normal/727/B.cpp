#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 2012;
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
#define prev asdklhsdireufhdashj
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

bool ok(char c){
	return ('0' <= c && c <= '9') || (c == '.');
}

ll to_ll(string s){
	ll ans = 0;
	for(char c : s){
		if('0' <= c && c <= '9'){
			ans = ans * 10 + c - '0';
		}
	}
	return ans;
}

ll get(string s){
	ll ans = to_ll(s);
	if(!((int) s.size() >= 3 && s[s.size() - 3] == '.')){
		ans *= 100;
	}
	return ans;
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

	string s;
	cin >> s;
	ll ans = 0;
	for(int i = 0; i < (int) s.size(); i++){
		if(ok(s[i])){
			string t;
			t += s[i];
			while(i + 1 < (int) s.size() && ok(s[i + 1])){
				i++;
				t += s[i];
			}
			ans += get(t);
		}
	}

	string b = "";

	if(ans % 100){
		b = ".";
		b += char(ans % 100 / 10 + '0');
		b += char(ans % 10 + '0');
	}

	ans /= 100;

	string a;
	int g = 0;
	while(ans){
		g++;
		if(g >= 4 && g % 3 == 1)
			a += ".";
		a += char(ans % 10 + '0');
		ans /= 10;
	}
	if((int) a.size() == 0){
		a = "0";
	}
	reverse(a.begin(), a.end());
	cout << a << b << endl;

}