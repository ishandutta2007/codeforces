#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
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
#define M_PI acos(-1)
#define remove tipa_remove
#define next tipa_next
#define mod % MOD
#define y1 hello_world
unsigned char ccc;
bool _minus = false;
inline ld sqr(ld t) {
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
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

const int MAX = 1e5 + 10;

int dp1[MAX];
int dp2[MAX];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	string a;
	string b;
	cin >> a >> b;

	int m = (int) b.size();
	int n = (int) a.size();

	int now = 0;

	for(int i = 0; i < (int) b.size(); i++) {
		while(now < (int) a.size() && a[now] != b[i]) {
			now++;
		}
		dp1[i] = ++now;
	}

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	now = 0;

	for(int i = 0; i < (int) b.size(); i++) {
		while(now < (int) a.size() && a[now] != b[i]) {
			now++;
		}
		dp2[i] = ++now;
	}

	int l = 0, r = m - 1;
	while(l < r){
		swap(dp2[l], dp2[r]);
		l++, r--;
	}
	int ans = 0;
	int pos = -1;
	for(int i = 0; i <= m; i++) {
		int now = (i ? dp1[i - 1] : 0);
		if(now > n){
			break;
		}
		int res = i;
		if(i < m) {
			int l = i, r = m - 1;
			while(l < r) {
				int x = (l + r) >> 1;
				if(dp2[x] + now <= n){
					r = x;
				}else{
					l = x + 1;
				}
			}
			if(dp2[l] + now <= n){
				res += (m - l);
			}
		}
		if(res > ans){
			ans = res;
			pos = i;
		}
	}

	if(!ans){
		cout << "-" << endl;
		return 0;
	}

	reverse(b.begin(), b.end());

	//cout << ans << " " << pos << endl;

	string add = "";
	for(int j = 0; j < pos; j++){
		add += b[j];
	}
	int t = ans - pos;
	for(int i = m - t; i < m; i++){
		add += b[i];
	}
	cout << add << endl;

}