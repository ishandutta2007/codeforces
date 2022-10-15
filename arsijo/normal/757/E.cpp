#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
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
#ifdef LOCAL
const int MAX = 1e3 + 1;
#else
const int MAX = 1e6 + 1;
#endif
const int MAX_LOG = 21;
ll dp[MAX_LOG][MAX];
vector<int> vec[MAX];
int t[MAX];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	for(int i = 0; i < MAX; i++)
		dp[0][i] = 1;
	for(int i = 1; i < MAX_LOG; i++)
		dp[i][0] = 2;
	for(int i = 1; i < MAX_LOG; i++){
		for(int j = 1; j < MAX; j++){
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}
	for(int i = 2; i < MAX; i++){
		if(t[i] == 0){
			ll w = i;
			for(int j = i; j < MAX; j += i)
				t[j] = 0;
			while(w < MAX){
				for(int j = w; j < MAX; j += w)
					t[j]++;
				w *= i;
			}
			for(int j = i; j < MAX; j += i)
				vec[j].push_back(t[j]);
		}
	}
	int q;
	read(q);
	while(q--){
		int r, n;
		read(r);
		read(n);
		ll res = 1;
		for(int a : vec[n]){
			//cout << a << " ";
			res = (res * dp[a][r]) % MOD;
		}
		//cout << endl;
		write(res);
		putchar('\n');
	}

}