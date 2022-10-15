#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-5;
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

const int MAX = 1e5 + 10;
int to[MAX][26];
int sz = 0;
void make(string &s){
	int pos = 0;
	for(char c : s){
		if(!to[pos][c - 'a']){
			to[pos][c - 'a'] = ++sz;
		}
		pos = to[pos][c - 'a'];
	}
}

bool culc(int pos){
	for(int i = 0; i < 26; i++){
		if(to[pos][i] && !culc(to[pos][i])){
			return true;
		}
	}
	return false;
}

bool culc2(int pos){
	int sz = 0;
	for(int i = 0; i < 26; i++){
		if(to[pos][i]){
			sz++;
		}
	}
	if(sz == 0){
		return true;
	}
	for(int i = 0; i < 26; i++){
		if(to[pos][i] && !culc2(to[pos][i])){
			return true;
		}
	}
	return false;
}

int main() {
	sync;
	srand(time(NULL));
	cout.precision(3);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;
	while(n--){
		string s;
		cin >> s;
		make(s);
	}
	bool res = culc(0);
	bool res2 = culc2(0);

	if(!res){
		cout << "Second" << endl;
		return 0;
	}

	if(m == 1){
		cout << "First" << endl;
		return 0;
	}

	if(res2){
		cout << "First" << endl;
		return 0;
	}

	cout << (m & 1 ? "First" : "Second") << endl;

}