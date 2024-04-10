#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e12 + 1;
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
#define prev __prev
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
#define DEBUG
#endif

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int ar[101][101];

set<int> s1[101], s2[101];

int main() {
	sync;
	srand(time(NULL));
	cout.precision(10);
	cout << fixed;
#ifdef LOCAL
	input;
#else

#endif

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> ar[i][j];
			s1[i].insert(ar[i][j]);
			s2[j].insert(ar[i][j]);
		}
	}

	vector<pair<string, int> > v;

	if(n <= m) {
		for(int i = 1; i <= n; i++) {
			int a = *s1[i].begin();
			for(int j = 1; j <= m; j++) {
				ar[i][j] -= a;
			}
			while(a--) {
				v.push_back(make_pair("row", i));
			}
		}
		for(int j = 1; j <= m; j++) {
			s2[j].clear();
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				s2[j].insert(ar[i][j]);
			}
		}
		for(int j = 1; j <= m; j++) {
			if(s2[j].size() > 1) {
				cout << -1 << endl;
				return 0;
			}
			int a = *s2[j].begin();
			while(a--) {
				v.push_back(make_pair("col", j));
			}
		}
	} else {
		for(int j = 1; j <= m; j++) {
			int a = *s2[j].begin();
			for(int i = 1; i <= n; i++) {
				ar[i][j] -= a;
			}
			while(a--) {
				v.push_back(make_pair("col", j));
			}
		}
		for(int j = 1; j <= n; j++) {
			s1[j].clear();
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				s1[i].insert(ar[i][j]);
			}
		}
		for(int i = 1; i <= n; i++) {
			if(s1[i].size() > 1) {
				cout << -1 << endl;
				return 0;
			}
			int a = *s1[i].begin();
			while(a--) {
				v.push_back(make_pair("row", i));
			}
		}
	}

	cout << v.size() << endl;
	for(pair<string, int> a : v) {
		cout << a.first << " " << a.second << endl;
	}

}