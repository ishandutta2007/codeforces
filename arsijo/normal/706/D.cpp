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

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 2e5 + 10;
const int MAX_SIZE = MAX * 32;
int _left[MAX_SIZE], _right[MAX_SIZE];
int has[MAX_SIZE];
int size;

inline bool in(int mask, int i){
	return (mask & (1 << i)) != 0;
}

void add(int val, int a){
	int pos = 1;
	for(int i = 30; i >= 0; i--){
		if(in(val, i)){
			if(_right[pos] == 0){
				_right[pos] = size++;
			}
			pos = _right[pos];
		}else{
			if(_left[pos] == 0){
				_left[pos] = size++;
			}
			pos = _left[pos];
		}
		has[pos] += a;
	}
}

int get(int val){
	int ans = 0;
	int pos = 1;
	for(int i = 30; i >= 0; i--){
		int a = _left[pos];
		int b = _right[pos];
		if(in(val, i))
			swap(a, b);
		if(has[b]){
			pos = b;
			ans ^= (1 << i);
		}else{
			pos = a;
		}
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

	size = 2;
	add(0, +1);
	int q;
	cin >> q;
	while(q--){
		char c;
		int val;
		cin >> c >> val;
		if(c == '+'){
			add(val, +1);
		}else if(c == '-'){
			add(val, -1);
		}else{
			cout << get(val) << endl;
		}
	}

}