#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
ll MOD = 1e9 + 7;
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
#define prev asdklhsdireufhdashj
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

#ifdef DEBUG
#define dbg if(1)
#else
#define dbg if(0)
#endif

int n, m;
const int MAX = 1e5 + 1;
int d[MAX], a[MAX];
int last[MAX];
vector<ii> v;
bool get(int size) {
	ms(last);
	for (int i = 1; i <= size; i++) {
		if (d[i]) {
			last[d[i]] = i;
		}
	}
	v.clear();
	for (int i = 1; i <= m; i++) {
		if (last[i]) {
			v.push_back(make_pair(last[i], a[i]));
		} else {
			return false;
		}
	}
	sort(v.begin(), v.end());
	int last = 0;
	int now = 0;
	int pos;
	for (int i = 0; i < m; i++) {
		pos = v[i].first;
		now += pos - last - 1;
		last = pos;
		if (now >= v[i].second) {
			now -= v[i].second;
		} else {
			return false;
		}
	}
	return true;
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

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	cin >> d[i];
	for(int i = 1; i <= m; i++)
	cin >> a[i];

	int l = 1, r = n;
	while(l < r){
		int x = (l + r) >> 1;
		if(get(x)){
			r = x;
		}else{
			l = x + 1;
		}
	}

	cout << (get(l) ? l : -1) << endl;

}