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

const int MAX = 2001;
int n, m, k;
vector<pair<ii, int> > vec[MAX];
bool bol[MAX][MAX];
ll f[MAX][MAX];
int t[MAX];
int T[MAX][4];
int i, j;
inline void upd(int x, int y, ll val) {
	for (i = x; i < MAX; i |= (i + 1))
		for (j = y; j < MAX; j |= (j + 1))
			f[i][j] += val;
}
ll ans;
inline ll get(int x, int y) {
	ans = 0;
	for (i = x; i >= 0; i &= (i + 1), i--)
		for (j = y; j >= 0; j &= (j + 1), j--)
			ans += f[i][j];
	return ans;
}
ll ans2;
inline ll get(int x1, int y1, int x2, int y2) {
	return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
}
inline bool is_ask() {
	char c = '1';
	while (c != 'A' && c != 'S') {
		c = getchar();
	}
	if (c == 'A') {
		for (int i = 0; i < 3; i++)
			getchar();
	} else {
		for (int i = 0; i < 6; i++)
			getchar();
	}
	return c == 'A';
}
ll ANS[MAX];
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
	read(k);
	for (int i = 1; i <= k; i++) {
		int len;
		int x, y, c;
		read(len);
		vec[i].reserve(len);
		for (int j = 0; j < len; j++) {
			read(x);
			read(y);
			read(c);
			vec[i].push_back(make_pair(make_pair(x, y), c));
		}
	}

	int q;
	read(q);
	int res = 0;
	for (int i = 1; i <= k; i++) {
		t[i] = true;
	}
	int pos;
	int j;
	for (int i = 0; i < q; i++) {
		if (is_ask()) {
			for (j = 1; j <= k; j++) {
				bol[res][j] = t[j];
			}
			for (j = 0; j < 4; j++)
				read(T[res][j]);
			res++;
		} else {
			read(pos);
			t[pos] = !t[pos];
		}
	}
	int i1, j1;
	for (int i1 = 1; i1 <= k; i1++) {
		for (j1 = 0; j1 < (int) vec[i1].size(); j1++) {
			upd(vec[i1][j1].first.first, vec[i1][j1].first.second,
					vec[i1][j1].second);
		}
		for (j1 = 0; j1 < res; j1++) {
			if (bol[j1][i1]) {
				ANS[j1] += get(T[j1][0], T[j1][1], T[j1][2], T[j1][3]);
			}
		}
		for (j1 = 0; j1 < (int) vec[i1].size(); j1++) {
			upd(vec[i1][j1].first.first, vec[i1][j1].first.second,
					-vec[i1][j1].second);
		}
	}

	for (int j = 0; j < res; j++) {
		cout << ANS[j] << endl;
	}

}