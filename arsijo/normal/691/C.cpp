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

string get(string s) {
	int l = 0;
	while (l < (int) s.size() && s[l] == '0') {
		l++;
	}
	if (l == (int) s.size())
		return "0";
	int r = (int) s.size() - 1;
	while (s[r] == '0')
		r--;
	string ans = s.substr(l, r - l + 1);
	if (ans == ".")
		return "0";
	return ans;
}

string get2(string s) {
	int l = 0;
	while (l < (int) s.size() && s[l] == '0') {
		l++;
	}
	if (l == (int) s.size())
		return "0";
	int r = (int) s.size() - 1;
	string ans = s.substr(l, r - l + 1);
	return ans;
}

string get3(string s) {
	int l = 0;
	int r = (int) s.size() - 1;
	while (r >= 0 && s[r] == '0')
		r--;
	if (r == -1)
		return "";
	string ans = s.substr(l, r - l + 1);
	if (ans == ".")
		return "0";
	return ans;
}

void solve_1(string s) {
	s = get2(s);
	if (s.size() == 1) {
		cout << s << endl;
	} else {
		string t = get3(s.substr(1, s.size() - 1));
		cout << s[0];
		if (!t.empty())
			cout << "." << t;
		cout << "E" << s.size() - 1 << endl;
	}
	exit(0);
}

string get4(string s){
	string ans = "";
	for(int i = 0; i < (int) s.size(); i++)
		if(s[i] != '.')
			ans += s[i];
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

	string s;
	cin >> s;
	if(s.find('.') == s.npos) {
		solve_1(s);
	}
	s = get(s);
	if(s == "0") {
		cout << s << endl;
		return 0;
	}
	if(s[s.size() - 1] == '.') {
		solve_1(s.substr(0, (int) s.size() - 1));
	}
	int ind = -1;
	for(int i = 0; i < (int) s.size(); i++) {
		if('1' <= s[i] && s[i] <= '9') {
			ind = i;
			break;
		}
	}
	int pos = s.find('.') - ind;
	if(pos > 0)
	pos--;
	string e = get2(get4(s));
	cout << e[0];
	if(e.size() != 1){
		string t = get3(e.substr(1, e.size() - 1));
		cout << "." << t;
	}
	if(pos)
		cout << "E" << pos << endl;

}