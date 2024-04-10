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

const int MAX = 1e3 + 1;
bool ar[MAX][MAX];
const int MAX_Q = 1e5 + 1;
vector<int> v[MAX_Q];
int ans[MAX_Q];
int a[MAX_Q], b[MAX_Q], c[MAX_Q];
bool take[MAX_Q];
int n, m, q;
ll res;
void dfs(int pos) {
	if (a[pos] == 1) {
		if (!ar[b[pos]][c[pos]]) {
			ar[b[pos]][c[pos]] = true;
			res++;
			take[pos] = true;
		}
	}
	if (a[pos] == 2) {
		if (ar[b[pos]][c[pos]]) {
			ar[b[pos]][c[pos]] = false;
			res--;
			take[pos] = true;
		}
	}
	if (a[pos] == 3) {
		take[pos] = true;
		int i = b[pos];
		for (int j = 1; j <= m; j++) {
			if (ar[i][j]) {
				res--;
			} else {
				res++;
			}
			ar[i][j] = !ar[i][j];
		}
	}
	ans[pos] = res;
	for (int i = 0; i < (int) v[pos].size(); i++) {
		dfs(v[pos][i]);
	}
	if (take[pos]) {
		if (a[pos] == 1) {
			ar[b[pos]][c[pos]] = false;
			res--;
		}
		if (a[pos] == 2) {
			ar[b[pos]][c[pos]] = true;
			res++;
		}
		if (a[pos] == 3) {
			int i = b[pos];
			for (int j = 1; j <= m; j++) {
				if (ar[i][j]) {
					res--;
				} else {
					res++;
				}
				ar[i][j] = !ar[i][j];
			}
		}
	}
}
int main() {
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
	sync;
#ifdef LOCAL
	input;
#else

#endif

	read(n);
	read(m);
	read(q);

	for (int i = 1; i <= q; i++) {
		read(a[i]);
		read(b[i]);
		if (a[i] <= 2)
			read(c[i]);
		if (a[i] == 4) {
			v[b[i]].push_back(i);
		} else {
			v[i - 1].push_back(i);
		}
	}

	dfs(0);

	for(int i = 1; i <= q; i++)
		write(ans[i]);

}