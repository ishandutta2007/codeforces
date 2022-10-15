#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
const ld E = 1e-10;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
#define endl "\n"
#endif
#ifndef LONG_LONG_MAX
#define LONG_LONG_MAX LLONG_MAX
#endif
#ifndef M_PI
#define M_PI acos(-1)
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

string s;
char res;
int m;
int n;

int find(int r, char c){
	while(s[r] != c)
		r--;
	return r;
}

string solve(int l, int r){
	string ans = "";
	while(r - l + 1 >= m){
		l = find(l + m - 1, res) + 1;
		ans += res;
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

	cin >> m;

	cin >> s;

	n = (int) s.size();
	s = "!" + s;
	int dp[2][n + 2];
	ms(dp);
	for(char c = 'a'; c <= 'z'; c++) {
		dp[0][0] = 0;
		for(int i = 1; i <= n; i++) {
			if(s[i] <= c) {
				dp[0][i] = 0;
			} else {
				dp[0][i] = dp[0][i - 1] + 1;
			}
		}
		dp[1][n + 1] = 0;
		for(int i = n; i >= 1; i--) {
			if(s[i] <= c) {
				dp[1][i] = 0;
			} else {
				dp[1][i] = dp[1][i + 1] + 1;
			}
		}
		bool ok = true;
		for(int i = 1; i <= n; i++) {
			if(dp[0][i] + dp[1][i] > m) {
				ok = false;
			}
		}
		if(ok) {
			res = c;
			break;
		}
	}

	string ans;

	for(int i = 1; i <= n; i++) {
		if(s[i] < res) {
			ans += s[i];
		}
	}

	for(int i = 1; i <= n; i++) {
		if(s[i] >= res) {
			int l = i;
			while(i + 1 <= n && s[i + 1] >= res)
				i++;
			ans += solve(l, i);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans << endl;

}