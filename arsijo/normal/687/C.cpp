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
char wwww[12];
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


int main() {

	sync;
	srand(time(NULL));
	cout.precision(5);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	int n, k;
	cin >> n >> k;

	bool dp[1001][1001];
	ms(dp);

	dp[0][0] = true;
	for(int q = 0; q < n; q++){
		int a;
		cin >> a;
		for(int i = 500; i >= 0; i--){
			for(int j = 500; j >= 0; j--){
				if(dp[i][j]){
					//cout << "+ " << i << " " << j << endl;
					dp[i + a][j] = true;
					dp[i + a][a + j] = true;
				}
			}
		}
	}

	vector<int> ans;

	for(int i = 0; i <= 500; i++){
		if(dp[k][i]){
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < (int) ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;

}