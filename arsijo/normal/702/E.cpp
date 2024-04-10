#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ld, ld> ii;
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

int n;
ll k;
const int MAX = 1e5 + 1;
ll sum[40][MAX], min_val[40][MAX], next[40][MAX];

int main() {

	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> next[0][i];
	}
	for(int i = 0; i < n; i++){
		cin >> sum[0][i];
		min_val[0][i] = sum[0][i];
	}
	for(int i = 1; i < 40; i++){
		for(int j = 0; j < n; j++){
			next[i][j] = next[i - 1][next[i - 1][j]];
			dbg if(i == 1)
				cout << j << " " << next[i - 1][j] << " " << sum[i - 1][j] << " " << sum[i - 1][next[i - 1][j]] << endl;
			sum[i][j] = sum[i - 1][j] + sum[i - 1][next[i - 1][j]];
			min_val[i][j] = min(min_val[i - 1][j], min_val[i - 1][next[i - 1][j]]);
		}
	}

	for(int i = 0; i < n; i++){
		ll ans_1 = 0;
		ll ans_2 = LONG_LONG_MAX;
		int pos = i;
		for(int j = 39; j >= 0; j--){
			if(k & (1LL << j)){
				dbg cout << j << endl;
				ans_1 += sum[j][pos];
				dbg cout << j << " " << pos << " " << sum[j][pos] << endl;
				ans_2 = min(ans_2, min_val[j][pos]);
				pos = next[j][pos];
			}
		}
		cout << ans_1 << " " << ans_2 << endl;
	}

}