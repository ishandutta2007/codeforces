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

const int MAX = 1e5;
int ar[MAX];
string s[MAX], s2[MAX];

inline void upd(ll &a, ll b){
	a = min(a, b);
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

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}
	for(int i = 0; i < n; i++){
		cin >> s[i];
		s2[i] = s[i];
		reverse(s2[i].begin(), s2[i].end());
	}
	ll dp[n][2];
	dp[0][0] = 0;
	dp[0][1] = ar[0];
	const ll INF = 1e18;
	for(int i = 1; i < n; i++){
		dp[i][0] = dp[i][1] = INF;
		if(dp[i - 1][0] != INF){
			if(s[i] >= s[i - 1]){
				upd(dp[i][0], dp[i - 1][0]);
			}
			if(s2[i] >= s[i - 1]){
				upd(dp[i][1], dp[i - 1][0] + ar[i]);
			}
		}
		if(dp[i - 1][1] != INF){
			if(s[i] >= s2[i - 1]){
				upd(dp[i][0], dp[i - 1][1]);
			}
			if(s2[i] >= s2[i - 1]){
				upd(dp[i][1], dp[i - 1][1] + ar[i]);
			}
		}
	}

	ll res = min(dp[n - 1][0], dp[n - 1][1]);
	cout << (res == INF ? -1 : res) << endl;

}