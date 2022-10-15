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
#define prev time_prev
#define remove tipa_remove
#define next tipa_next
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

map<pair<int, int>, pair<int, int> > m;

ll ans = 0;

const int MAX = 1e5;
ll a[MAX], b[MAX], c[MAX];

int max_res;
ii ind;
map<pair<int, int>, pair<int, int> >::iterator it;
void upd(pair<int, int> p, int i, int h) {
	if (p.first > p.second)
		swap(p.first, p.second);
	it = m.find(p);
	if (it != m.end()) {
		ld r = min(min(p.first, p.second), h + it->second.first);
		if (r > max_res) {
			max_res = r;
			ind = make_pair(i, it->second.second);
		}
	}
}

void add(pair<int, int> p, int i, int h) {
	if (p.first > p.second)
		swap(p.first, p.second);
	it = m.find(p);
	if (it == m.end() || (it->second.first < h)) {
		m[p] = make_pair(h, i);
	}
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

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
	cin >> a[i] >> b[i] >> c[i];

	max_res = -1;
	ind = make_pair(-1, -1);
	for(int i = 0; i < n; i++) {
		int r = min(a[i], min(b[i], c[i]));
		if(r > max_res) {
			max_res = r;
			ind = make_pair(i, -1);
		}
	}
	for(int i = 0; i < n; i++) {
		upd(make_pair(a[i], b[i]), i, c[i]);
		upd(make_pair(a[i], c[i]), i, b[i]);
		upd(make_pair(c[i], b[i]), i, a[i]);
		add(make_pair(a[i], b[i]), i, c[i]);
		add(make_pair(a[i], c[i]), i, b[i]);
		add(make_pair(c[i], b[i]), i, a[i]);
	}

	if(ind.second == -1){
		cout << 1 << endl;
		cout << ind.first + 1 << endl;
	}else{
		cout << 2 << endl;
		cout << ind.first + 1 << " " << ind.second + 1 << endl;
	}

}