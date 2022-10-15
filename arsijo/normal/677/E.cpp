#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
int MOD = 1e9 + 7;
const ld E = 1e-8;
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
char wwww[12];
int kkkk;
inline void write(int x) {
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
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
//#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

struct big {
	int two, three;
	big() {
		two = three = 0;
	}
	big(int a, int b) {
		two = a;
		three = b;
	}
	ld get_log_10() {
		return log10((ld) 2) * two + log10((ld) 3) * three;
	}
	bool operator<(big b) {
		return get_log_10() < b.get_log_10();
	}
	big operator-(big b) {
		return big(two - b.two, three - b.three);
	}
	big operator+(big b) {
		return big(two + b.two, three + b.three);
	}
};

const int N = 1000;
int dp[4][N + 2][N + 2];
big dp1[N + 2][N + 2];
big dp2[N + 2][N + 2];

ll _pow(ll n, ll m){
	return (m == 0 ? 1 : m & 1 ? n * _pow(n, m - 1) : sqr(_pow(n, m >> 1))) % MOD;
}

int main() {

	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;

	//test();

#ifdef LOCAL
	input;
	//output;
#else

#endif

	int n;
	cin >> n;

	int ar[n + 2][n + 2];
	ms(ar);

	int max_val = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			ar[i][j] = c - '0';
			max_val = max(max_val, ar[i][j]);
		}
	}

	if(max_val == 0) {
		cout << 0 << endl;
		return 0;
	}

	if(max_val == 1) {
		cout << 1 << endl;
		return 0;
	}

	big ans(0, 0);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(ar[i][j]) {
				dp1[i][j] = big(ar[i][j] == 2, ar[i][j] == 3) + dp1[i - 1][j - 1];
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = n; j >= 1; j--) {
			if(ar[i][j]) {
				dp2[i][j] = big(ar[i][j] == 2, ar[i][j] == 3) + dp2[i - 1][j + 1];
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dp[0][i][j] = (ar[i][j] ? dp[0][i - 1][j - 1] + 1 : 0);
		}
		for(int j = n; j >= 1; j--) {
			dp[1][i][j] = (ar[i][j] ? dp[1][i - 1][j + 1] + 1 : 0);
		}
	}

	for(int i = n; i >= 1; i--) {
		for(int j = 1; j <= n; j++) {
			dp[2][i][j] = (ar[i][j] ? dp[2][i + 1][j - 1] + 1 : 0);
		}
		for(int j = n; j >= 1; j--) {
			dp[3][i][j] = (ar[i][j] ? dp[3][i + 1][j + 1] + 1 : 0);
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int len = n;
			for(int z = 0; z < 4; z++)
			len = min(len, dp[z][i][j]);
			if(!len)
			continue;
			big res = dp1[i + len - 1][j + len - 1] - dp1[i - len][j - len] + dp2[i + len - 1][j - len + 1] - dp2[i - len][j + len];
			res.two -= (ar[i][j] == 2);
			res.three -= (ar[i][j] == 3);
			if(ans < res) {
				ans = res;
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(ar[i][j]) {
				dp1[i][j] = big(ar[i][j] == 2, ar[i][j] == 3) + dp1[i - 1][j];
				dp2[i][j] = big(ar[i][j] == 2, ar[i][j] == 3) + dp2[i][j - 1];
			}
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dp[0][i][j] = (ar[i][j] ? dp[0][i - 1][j] + 1 : 0);
			dp[1][i][j] = (ar[i][j] ? dp[1][i][j - 1] + 1 : 0);
		}
	}

	for(int i = n; i >= 1; i--) {
		for(int j = n; j >= 1; j--) {
			dp[2][i][j] = (ar[i][j] ? dp[2][i + 1][j] + 1 : 0);
			dp[3][i][j] = (ar[i][j] ? dp[3][i][j + 1] + 1 : 0);
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int len = n;
			for(int z = 0; z < 4; z++)
			len = min(len, dp[z][i][j]);
			if(!len)
			continue;
			big res = dp2[i][j + len - 1] - dp2[i][j - len] + dp1[i + len - 1][j] - dp1[i - len][j];
			res.two -= (ar[i][j] == 2);
			res.three -= (ar[i][j] == 3);
			if(ans < res) {
				ans = res;
			}
		}
	}

	//cout << ans.two << " " << ans.three << endl;

	ll _ans = _pow(2, ans.two) * _pow(3, ans.three);
	_ans %= MOD;
	cout << _ans << endl;

}