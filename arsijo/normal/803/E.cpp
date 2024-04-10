#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-12;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef M_PI
#define M_PI 3.141592653589793238462643383
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

const int MAX = 1e3 + 10;

bool dp[MAX][MAX + MAX + 1];
int from[MAX][MAX + MAX + 1];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(12);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	dp[0][MAX] = true;
	for(int i = 0; i < n; i++) {
		for(int j = MAX - k + 1; j < MAX + k; j++) {
			if(dp[i][j]) {
				if(s[i] == '?' || s[i] == 'L') {
					dp[i + 1][j - 1] = true;
					from[i + 1][j - 1] = j;
				}
				if(s[i] == '?' || s[i] == 'D') {
					dp[i + 1][j] = true;
					from[i + 1][j] = j;
				}
				if(s[i] == '?' || s[i] == 'W') {
					dp[i + 1][j + 1] = true;
					from[i + 1][j + 1] = j;
				}

			}
		}
	}

	if(dp[n][MAX - k] || dp[n][MAX + k]){
		string ans = "";
		int val = (dp[n][MAX - k] ? MAX - k : MAX + k);
		for(int i = n; i; i--){
			int to = from[i][val];
			if(to < val)
				ans += "W";
			else if(to > val)
				ans += "L";
			else
				ans += "D";
			val = to;
		}
		assert(val == MAX);
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
		return 0;
	}

	cout << "NO" << endl;

}