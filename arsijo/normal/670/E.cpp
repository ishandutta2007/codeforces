#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
const ll MOD = 1e9 + 7;
const ld E = 1e-10;
#define null NULL
#define ms(x) memset(x, 0, sizeof(x))
#ifndef LOCAL
//#define endl "\n"
#endif
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define _read(x) freopen(x, "r", stdin)
#define _write(x) freopen(x, "w", stdout)
#define files(x) _read(x ".in"); _write(x ".out")
#define filesdatsol(x) _read(x ".dat"); _write(x ".sol")
#define output _write("output.txt")
#define input _read("input.txt")
#define mod % MOD
char ccc;
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
	while (x) {
		++kkkk;
		wwww[kkkk] = char(x % 10 + '0');
		x /= 10;
	}
	for (int i = kkkk; i >= 1; --i)
		putchar(wwww[i]);
	putchar(' ');
}
template<typename T> inline T sqr(T t) {
	return t * t;
}
#ifdef LOCAL
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n, m, p;
const int MAX = 5e5 + 2;
int next[MAX], prev[MAX];
string s, t;

int main() {

	sync;
	srand(time(NULL));
	cout.precision(0);
	cout << fixed;

#ifdef LOCAL
	input;
#else

#endif

	cin >> n >> m >> p >> s >> t;
	s = "!" + s;

	for(int i = 0; i <= n; i++)
	next[i] = i + 1;
	for(int i = 1; i <= n + 1; i++)
	prev[i] = i - 1;

	for(int j = 0; j < (int) t.size(); j++) {
		if(t[j] == 'L') {
			p = prev[p];
		} else if(t[j] == 'R') {
			p = next[p];
		} else {
			int l, r;
			if(s[p] == '(') {
				int t = 1;
				l = p;
				int i = next[p];
				for(i = next[p]; t; i = next[i]) {
					t += (s[i] == '(' ? 1 : -1);
					if(t == 0)
					break;
				}
				r = i;
				p = next[r];
			} else {
				int t = 1;
				r = p;
				int i = prev[p];
				for(i = prev[p]; t; i = prev[i]) {
					t += (s[i] == ')' ? 1 : -1);
					if(t == 0)
					break;
				}
				l = i;
				p = next[r];
			}
			int a = prev[l], b = next[r];
			next[a] = b;
			prev[b] = a;
			while(p > n)
			p = prev[p];
		}
	}

	for(int i = next[0]; i <= n; i = next[i])
	cout << s[i];

}