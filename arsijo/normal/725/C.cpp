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

ii _get[26];

void make(string s, string t) {
	int now = 0;
	for (int i = 0; i < 13; i++) {
		_get[s[i] - 'A'] = make_pair(0, now);
		now++;
	}
	now = 13;
	for (int i = 13; i < 26; i++) {
		now--;
		_get[s[i] - 'A'] = make_pair(1, now);
	}
	for(int i = 1; i < (int) t.size(); i++){
		int diff_x = abs(_get[t[i] - 'A'].first - _get[t[i - 1] - 'A'].first);
		int diff_y = abs(_get[t[i] - 'A'].second - _get[t[i - 1] - 'A'].second);
		if(diff_x > 1 || diff_y > 1)
			return;
		if(diff_x == 0 && diff_y == 0)
			return;
	}
	now = 0;
	for(int i = 0; i < 13; i++){
		cout << s[i];
	}
	cout << endl;
	for(int i = 25; i >= 13; i--){
		cout << s[i];
	}
	cout << endl;
	exit(0);
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
	for(int i = 1; i < (int) s.size(); i++) {
		if(s[i - 1] == s[i]) {
			cout << "Impossible" << endl;
			return 0;
		}
	}

	bool used[26];
	ms(used);

	string t = "";
	for(int i = 0; i < (int) s.size(); i++){
		if(!used[s[i] - 'A']){
			used[s[i] - 'A'] = true;
			t += s[i];
		}
	}

	for(int i = 0; i < 26; i++){
		make(t, s);
		t = t.substr(1) + t[0];
	}

	cout << "Impossible" << endl;

}